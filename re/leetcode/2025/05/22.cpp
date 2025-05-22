//https://leetcode.cn/problems/zero-array-transformation-iii/description/?envType=daily-question&envId=2025-05-22

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end(),[](const vector<int>&a,const vector<int>& b){
            return a[0] < b[0];
        });

        int n = nums.size();
        int m = queries.size();

        priority_queue<int> q;

        vector<int> cnt(n + 1,0);

        int op = 0;

        for(int i = 0,j = 0;i < n;i++){
            op += cnt[i];
            while(j < m && queries[j][0] == i){
                q.push(queries[j][1]);
                j++;
            }

            while(op < nums[i] && q.size() && q.top() >= i){
                op += 1;
                cnt[q.top() + 1] -= 1;
                q.pop();
            }
            
            if(op < nums[i]){
                return -1;
            }
        }
        return q.size();
    }
};