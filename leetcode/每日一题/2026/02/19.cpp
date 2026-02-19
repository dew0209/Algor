//
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> res;
        int n = s.size();
        for(int i = 0;i < n;i++){
            int j = i;
            while(j < n && s[j] == s[i]){
                j++;
            }
            res.push_back(j - i);
            i = j - 1;
        }
        int ans = 0;
        for(int i = 0;i < res.size() - 1;i++){
            ans += min(res[i],res[i + 1]);
        }
        return ans;
    }
};