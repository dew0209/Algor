//维护左右两边最大的值

const int N = 100010;
class Solution {
public:
    int left[N];
    int right[N];
    int q[N];
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int hh = 0,tt = -1;

        for(int i = 0;i < n;i++){
            if(hh <= tt){
                left[i] = q[hh];
            }else {
                left[i] = -1;
            }
            while(hh <= tt && nums[q[tt]] <= nums[i])tt--;
            q[++tt] = i;
        }

        

        hh = 0,tt = -1;
        for(int i = n - 1;i >= 0;i--){
            if(hh <= tt){
                right[i] = q[hh];
            }else {
                right[i] = -1;
            }
            while(hh <= tt && nums[q[tt]] <= nums[i])tt--;
            q[++tt] = i;
        }
        long long res = 0;
        for(int i = 0;i < n;i++){
            if(left[i] != -1 && right[i] != -1){
                res = max(res,((long long)nums[left[i]] - nums[i]) * nums[right[i]]);
            }
        }
        return res;
    }
};