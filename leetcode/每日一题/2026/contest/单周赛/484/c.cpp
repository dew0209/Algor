//https://leetcode.cn/problems/count-caesar-cipher-pairs/description/


class Solution {
public:
    bool check(string s,string t){
        int n = s.size();
        int diff = -1000000;

        for(int i = 0;i < n;i++){

            int a = s[i] - 'a';
            int b = t[i] - 'a';

            int x = b - a + (s[i] > t[i] ? 26 : 0);

            if(diff == -1000000){
                diff = x;
            }else if(diff != x){
                return false;
            }
            
        }
        return true;
        
    }
    long long countPairs(vector<string>& words) {
        vector<string> cnt;
        vector<int> sum;
        int id = -1;
        long long res = 0;
        for(auto word : words){
            //寻找边界
            int e = -1;
            for(int i = 0;i <= id;i++){
                if(check(word,cnt[i])){
                    e = i;
                    break;
                }
            }
            if(e == -1){
                cnt.push_back(word);
                sum.push_back(1);
                id++;
            }else {
                cnt[e] = word;
                sum[e]++;
            }
        }
        //统计结果
        for(int i = 0;i <= id;i++){
            int count = sum[i];
            res = res + 1LL * count * (count - 1) / 2;
        }
        return res;
    }
};