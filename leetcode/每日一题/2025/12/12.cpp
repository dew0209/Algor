//https://leetcode.cn/problems/count-mentions-per-user/?envType=daily-question&envId=2025-12-12

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int> f(n,0);
        vector<int> next_inline_time(n,0);

        sort(events.begin(), events.end(), [&](const vector<string> &lth, const vector<string> &rth) {
            int lth_timestamp = stoi(lth[1]);
            int rth_timestamp = stoi(rth[1]);
            if (lth_timestamp != rth_timestamp) {
                return lth_timestamp < rth_timestamp;
            }
            if (rth[0] == "OFFLINE") {
                return false;
            }
            return true;
        });

        for(auto ev : events){
            int curr_time = stoi(ev[1]);
            if(ev[0] == "MESSAGE"){
                if(ev[2] == "ALL"){
                    for(int i = 0;i < n;i++){
                        f[i]++;
                    }
                }else if(ev[2] == "HERE"){
                    for(int i = 0;i < n;i++){
                        if(next_inline_time[i] <= curr_time){
                            f[i]++;
                        }
                    }
                }else {
                    int idx = 0;
                    cout << ev[2] << endl;
                    for (int i = 0; i < ev[2].size(); i++) {
                        if (isdigit(ev[2][i])) {
                            idx = idx * 10 + (ev[2][i] - '0');
                        }
                        if (i + 1 == ev[2].size() || ev[2][i] == ' ') {
                            f[idx]++;
                            idx = 0;
                        }
                    }
                }

            }else {
                next_inline_time[stoi(ev[2])] = curr_time + 60;
            }
        }
        return f;
    }
};