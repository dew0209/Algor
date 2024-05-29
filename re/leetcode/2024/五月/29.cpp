// 题目链接：https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-05-29

// 思路：双指针

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<int> cnt[26];

        for(int i = 0;i < n;i++){
            int j = i + 1;
            while(j < n && s[i] == s[j])j++;
            cnt[s[i] - 'a'].push_back(j - i);
            for(int v = cnt[s[i] - 'a'].size() - 1;v > 0;v--){
                if(cnt[s[i] - 'a'][v] > cnt[s[i] - 'a'][v - 1]){
                    swap(cnt[s[i] - 'a'][v],cnt[s[i] - 'a'][v - 1]);
                }else {
                    break;
                }
            }
            if(cnt[s[i] - 'a'].size() > 3){
                cnt[s[i] - 'a'].pop_back();
            }
            j = i - 1;
        }
        int res = -1;
        for(int i = 0;i < 26;i++){
            int len = cnt[i].size();
            if(len > 0){
                if(cnt[i][0] > 2){
                    res = max(cnt[i][0] - 2,res);
                }
                if(len > 1 && cnt[i][1] > 1){
                    res = max(cnt[i][1] - 1,res);
                }
                if(len > 2){
                    res = max(cnt[i][2],res);
                }
            }
        }
        return res;
    }
};