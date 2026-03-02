class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lefts(n);
        vector<int> sum(n + 1);
        int mx = 0;
        deque<int> min_q,max_q;
        int left = 0;
        for(int right = 0;right < n;right++){
            int x = nums[right];
            sum[right + 1] = sum[right] ^ x;
            mx = max(x,mx);

            //入
            while(min_q.size() && x <= nums[min_q.back()]){
                min_q.pop_back();
            }
            min_q.push_back(right);

            while(max_q.size() && x >= nums[max_q.back()]){
                max_q.pop_back();
            }
            max_q.push_back(right);
            
            while(nums[max_q.front()] - nums[min_q.front()] > k){
                left++;
                if (min_q.front() < left) {
                    min_q.pop_front();
                }
                if (max_q.front() < left) {
                    max_q.pop_front();
                }
            }
            lefts[right] = left;
        }
        int width = bit_width((uint32_t)mx);
        vector<int> last(1 << width);
        int ans = 0;
        for(int i = width - 1;i >= 0;i--){
            fill(last.begin(),last.begin() + (1 << (width - i)),-1);
            last[0] = 0;
            ans <<= 1;
            int new_ans = ans | 1;
            for(int right = 0;right < n;right++){
                int s = sum[right + 1] >> i;
                if(last[new_ans ^ s] >= lefts[right]){
                    ans = new_ans;
                    break;
                }
                last[s] = right + 1;
            }
        }
        return ans;
    }
};