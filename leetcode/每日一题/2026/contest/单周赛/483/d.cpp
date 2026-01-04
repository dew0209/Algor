//https://leetcode.cn/problems/minimum-cost-to-merge-sorted-lists/description/

class Solution {
public:
    vector<int> merged(vector<int>& a,vector<int>& b){
        vector<int> res;
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                res.push_back(a[i++]);
            }else {
                res.push_back(b[j++]);
            }
        }
        while(i < n)res.push_back(a[i++]);
        while(j < m)res.push_back(b[j++]);
        return res;
    }
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        int u = 1 << n;
        //中位数
        vector<int> median(u);
        //长度
        vector<int> len(u);
        //合并后的集合
        vector<vector<int>> sorted(u);

        vector<long long> f(u);

        //预处理
        for(int i = 0;i < n;i++){
            int r = 1 << i;
            for(int j = 0;j < r;j++){
                int x = j | r;

                //长度
                len[x] = len[j] + lists[i].size();

                vector<int> mergedVector = merged(sorted[j],lists[i]);
                //中位数
                median[x] = mergedVector[(mergedVector.size() - 1) / 2];
                
                //合并后的集合
                sorted[x] = mergedVector;
            }
        }
        //获得结果
        for(int i = 0;i < u;i++){
            if((i & (i - 1)) == 0){
                continue;
            }
            f[i] = LLONG_MAX;
            for(int j = (i - 1) & i;j > 0;j = (j - 1) & i){
                int k = i ^ j;
                f[i] = min(f[i],f[j] + f[k] + len[j] + len[k] + abs(median[j] - median[k]));
            }
        }
        return f[u - 1];
    }
};