//https://leetcode.cn/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14

class Solution {
public:
    bool isGood(vector<int>& nums) {
        map<int,int> cnt;
        int n = nums.size() - 1;
        for(auto& num : nums){
            cnt[num]++;
        }
        for(auto [x,y] : cnt){
            if(x == n){
                if(y != 2){
                    return false;
                }
            }else if(x < 1 || x > n){
                return false;
            }else if(y != 1){
                return false;
            }
        }
        return true;
    }
};