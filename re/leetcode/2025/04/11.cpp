//https://leetcode.cn/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res = 0;
            for(int i = low;i <= high;i++){
                if(check(i)){
                    res++;
                }
            }
            return res;
        }
        bool check(int u){
            if(!u)return false;
            vector<int> num;
            while(u){
                num.push_back(u % 10);
                u /= 10;
            }
            int n = num.size();
            if(n & 1)return false;
            
            int l = 0,r = n - 1;
    
            int sl = 0,sr = 0;
    
            while(l < r){
                sl += num[l];
                sr += num[r];
                l++;
                r--;
            }
            return sl == sr;
        }
    };