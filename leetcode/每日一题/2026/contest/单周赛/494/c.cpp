class Solution {
public:
    int ans = 0;
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0){
            return -1;
        }

        int n1 = n / 2;
        int n2 = n - n1;

        vector<int> nums1(nums.begin(), nums.begin() + n1);
        vector<int> nums2(nums.begin() + n1, nums.end());

        map<int,int> cnt;

        int mask = (1 << n1) - 1;
        for (int sub = mask; ; sub = (sub - 1) & mask) {
                int r = 0;
                int sum = 0;
                for(int i = 0;i < n1;i++){
                    if(((sub >> i) & 1) == 1){
                        sum++;
                        r = r ^ nums1[i];
                    }
                }
                if(cnt.count(r)){
                    cnt[r] = max(cnt[r],sum);
                }else {
                    cnt[r] = sum;
                }
                if (sub == 0) break;  
        }
        
        int ans = 0;

        mask = (1 << n2) - 1;
        for (int sub = mask; ; sub = (sub - 1) & mask) {
                int r = 0;
                int sum = 0;
                for(int i = 0;i < n2;i++){
                    if(((sub >> i) & 1) == 1){
                        sum++;
                        r = r ^ nums2[i];
                    }
                }
                //统计结果集
                int diff = target ^ r;
                if(cnt.count(diff)){
                    ans = max(ans,cnt[diff] + sum);
                }
                if (sub == 0) break;  
        }
        if(ans == 0 && target != 0){
            return -1;
        }
        return n - ans;
    }
};