class Solution {
public:
    map<double, map<int,int>> mp;
    int ans = 0;
    int cmp(double a,long long b){
        if(abs(a - b) < 1e-9){
            return 0;
        }
        if(a > b){
            return 1;
        }
        return -1;
    }
    
    //数组,当前数值,前缀乘和,当前遍历起点，目标值，数值长度
    int dfs(vector<int>& nums,double u,vector<double>& sum,int id,long long target,int n){
        
        if(mp.count(u) && mp[u].count(id)){
            return mp[u][id];
        }

        if(id == n && cmp(u,target) == 0){
            return 1;
        }

        if(id){
            //剪枝
            if(cmp(u / sum[id - 1] * sum[n - 1] ,target) == -1){
                return 0;
            }
            //剪枝
            if(cmp(u / sum[n - 1] / sum[id - 1],target) == 1){
                return 0;
            }
        }
        
        if(id >= n){
            return 0;
        }

        int x = nums[id];
        //乘当前数
        int r1 = dfs(nums,u * x,sum,id + 1,target,n);
        //除当前数
        int r2 = dfs(nums,u / x,sum,id + 1,target,n);
        //保持不变
        int r3 = dfs(nums,u,sum,id + 1,target,n);
        mp[u][id] = r1 + r2 + r3;
        return r1 + r2 + r3;
    }
    
    int countSequences(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<double> sum(n,0);
        sum[0] = nums[0];
        for(int i = 1;i < n;i++){
            sum[i] = 1LL * nums[i] * sum[i - 1];
        }
        //开始递归
        return dfs(nums,1.0,sum,0,k,n);
    }
};