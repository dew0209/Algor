class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        map<int,int> cnt;
        for(int i = 0;i < n;i++){
            int c = nums[i];
            cnt[c]++;
        }
        map<int,int> count;
        for(auto [x,y] : cnt){
            count[y]++;
        }

        for(int i = 0;i < n;i++){
            int c = nums[i];
            int y = count[cnt[c]];
            if(y == 1){
                return c;
            }
        }
        return -1;
    }
};