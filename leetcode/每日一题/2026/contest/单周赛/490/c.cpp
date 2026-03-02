class Solution {
public:
    
    string maximumXor(string t, string s) {
        //异或 不一样的就是1
        int n = s.size();
        string res = "";

        vector<int> cnt(2,0);
        for(int i = 0;i < n;i++){
            cnt[s[i] - '0']++;
        }
        
        for(int i = 0;i < n;i++){
            //高位
            //t当前位置的数值
            int tId = t[i] - '0';
            int target = !tId;
            if(cnt[target]){
                cnt[target]--;
                res += to_string(1);
            }else {
                cnt[tId]--;
                res += to_string(0);
            }
            
        }
        return res;
        
    }
};