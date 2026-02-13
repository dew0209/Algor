//https://leetcode.cn/problems/longest-balanced-substring-ii/description/?envType=daily-question&envId=2026-02-13

class Solution {
public:

    int twoCase(string& s,char x,char y){
        map<int,int> cnt;
        int n = s.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            if(s[i] != x && s[i] != y){
                continue;
            }
            cnt.clear();
            cnt[0] = i - 1;
            int sum = 0;
            while(i < n && (s[i] == x || s[i] == y)){
                sum += (s[i] == x ? 1 : -1);
                
                if(cnt.contains(sum)){
                    res = max(res,i - cnt[sum]);
                }else {
                    cnt[sum] = i;
                }
                i++;
            }
        }
        return res;

    }

    long long getId(int x,int y,int n){
        return 1LL * (x + n) << 32 | (y + n);
    }

    int longestBalanced(string s) {
        int n = s.size();

        int res = 0;

        int count = 0;
        for(int i = 0;i < n;i++){
            if(i > 0 && s[i] == s[i - 1]){
                count++;
            }else {
                count = 1;
            }
            res = max(res,count);
        }

        res = max(res,twoCase(s,'a','b'));
        res = max(res,twoCase(s,'a','c'));
        res = max(res,twoCase(s,'c','b'));
        

        map<long long ,int> cnt;
        cnt[getId(0,0,n)] = -1;

        int pre[3] = {0,0,0};
        
        for(int i = 0;i < n;i++){

            pre[s[i] - 'a']++;

            long long id = getId(pre[1] - pre[0],pre[1] - pre[2],n);

            if(cnt.contains(id)){
                res = max(res,i - cnt[id]);
            }else {
                cnt[id] = i;
            }
        }
        return res;
    }
};