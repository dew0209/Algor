class Solution {
public:
    vector<int> get_divisors(int n){
        vector<int> res;
    
        for(int i = 1;i <= n/i;i++)
            if(n % i==0){
                res.push_back(i);
                if(i != n / i)res.push_back(n/i);
            }
    
        sort(res.begin(),res.end());
        return res;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> nex_dec(n);
        nex_dec[n - 1] = n;
        int p = n;
        for(int i = n - 2;i >= 0;i--){
            if(nums[i] > nums[i + 1]){
                p = i;
            }
            nex_dec[i] = p;
        }


        vector<int> res = get_divisors(n);
        int ans = 0;
        int last = -1;

        for(int i = 0;i < res.size();i++){
            int k = res[i];
            bool ok = true;
            last = -1;
            for(int l = 0;l < n;l += k){
                int r = l + k - 1;
                int m = nex_dec[l];
                if(m >= r){
                    if(nums[l] < last){
                        ok = false;
                        break;
                    }
                    last = nums[r];
                }else {
                    if(nex_dec[m + 1] < r || nums[m + 1] < last || nums[m + 1] < last || nums[r] > nums[l]){
                        ok = false;
                        break;
                    }
                    last = nums[m];
                }

            }
            if(ok){
                cout << k << endl;
                ans += k;
            }
        }
        return ans;
        
    }
};