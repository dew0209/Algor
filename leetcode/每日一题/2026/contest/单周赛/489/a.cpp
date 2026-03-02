class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> res;
        vector<int> cnt(200,0);
        for(int i = 0;i < bulbs.size();i++){
            cnt[bulbs[i]] = 1 - cnt[bulbs[i]];
        }
        for(int i = 1;i <= 100;i++){
            if(cnt[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};