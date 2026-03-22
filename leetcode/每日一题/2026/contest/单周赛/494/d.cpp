

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> or_l;
        map<int,int> last;
        long long ans = 0;

        for(int i = 0;i < n;i++){
            int x = nums[i];
            last[x] = i;
            for(auto& [val,_] : or_l){
                val |= x;
            }
            or_l.push_back({x,i});

            int m = 1;
            for (int j = 1; j < or_l.size(); j++) {
                if (or_l[j].first != or_l[j - 1].first) {
                    or_l[m++] = or_l[j];
                }
            }
            or_l.resize(m);

            for(int k = 0;k < m;k++){
                auto [val,left] = or_l[k];

                int right = k + 1 < m ? or_l[k + 1].second - 1 : i;
                auto it = last.find(val);
                if(it != last.end() && it->second >= left){
                    ans += min(right,it->second) - left + 1;
                }
            }

        }
        return ans;
    }
};