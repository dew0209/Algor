class Solution {
public:
    
    // int solve1(vector<int>& a, int k) {
    //     int n = a.size();
    //     vector f(k + 1, vector<int>(n));
    //     for (int i = 1; i <= k; i++) {
    //         f[i][0] = f[i][1] = INT_MAX / 2;
    //     }

    //     for (int left = 1; left <= k; left++) {
    //         for (int i = 1; i < n - 1; i++) {
    //             // 选或不选
    //             int not_choose = f[left][i];
    //             int choose = f[left - 1][i - 1] + max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0);
    //             f[left][i + 1] = min(not_choose, choose);
    //         }
    //     }
    //     cout << "结果(0)：" << f[k][n - 1] << endl;


    //     return f[k][n - 1];
    // }

    int solve(vector<int>& a, int k){
        int n = a.size();
        vector<vector<int>> f(k + 1,vector<int>(n + 2));
        for(int i = 1;i <= k;i++){
            f[i][0] = INT_MAX / 2;
        }
        for(int i = 1;i <= k;i++){
            for(int j = 1;j < n - 1;j++){
                int not_choose = f[i][j - 1];
                int choose = (j - 2 >= 0 ? f[i - 1][j - 2] : (i - 1 == 0 ? 0 : INT_MAX / 2)) + max(max(a[j - 1],a[j + 1]) + 1 - a[j],0);
                f[i][j] = min(not_choose,choose);
                //cout << f[i][j] << " --- " << i << " ---- " << j << " --- " << not_choose << " ---- " << choose << endl;
            }
        }
        //cout << "结果：" << f[k][n - 2] << endl;
        return f[k][n - 2];
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if( k > n / 2){
            return -1;
        }

        //如果 nums[0] 是峰顶，那么 nums[n-1] 不是峰顶
        vector<int> a = {nums.back()};
        a.insert(a.end(), nums.begin(), nums.end());
        int ans1 = solve(a, k);

        // 如果 nums[0] 不是峰顶
        nums.push_back(nums[0]);
        int ans2 = solve(nums, k);

        return min(ans1,ans2);
    }
};