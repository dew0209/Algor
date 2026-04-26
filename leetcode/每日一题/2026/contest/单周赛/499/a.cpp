class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0;i < n;i++){
            if(i == 0 || i == n - 1){
                res.push_back(nums[i]);
                continue;
            }
            bool ok = true;
            for(int j = 0;j < i;j++){
                if(nums[j] >= nums[i]){
                    ok = false;
                }
            }
            if(ok){
                res.push_back(nums[i]);
            }else {
                ok = true;
                for(int j = i + 1;j < n;j++){
                    if(nums[j] >= nums[i]){
                        ok = false;
                    }
                }
                if(ok){
                    res.push_back(nums[i]);
                }
            }
        }
        return res;
    }
};