//题目链接：https://leetcode.cn/problems/shopping-offers/solutions/1063610/gong-shui-san-xie-yi-ti-shuang-jie-zhuan-qgk1/


class Solution {
public:
    map<vector<int>,int> cnt;

    int dfs(vector<int>& price,int n,vector<vector<int>>& special, vector<int>& needs,int m){
        if(!cnt.count(needs)){
            int mv = 0;
            for (int i = 0; i < m; ++i) {
                mv += needs[i] * price[i];
            }
            for(int i = 0;i < n;i++){
                vector<int> nextNeeds;
                for(int j = 0;j < needs.size();j++){
                    if(special[i][j] > needs[j]){
                        break;
                    }
                    nextNeeds.push_back(needs[j] - special[i][j]);
                }
                if(needs.size() == nextNeeds.size()){
                    mv = min(mv,special[i][m] + dfs(price,n,special,nextNeeds,m));
                }
            }
            cnt[needs] = mv;
        }
        return cnt[needs];
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        
        vector<int> f(n,0);
        cnt[f] = 0;
        return dfs(price,special.size(),special,needs,n);
    }
};