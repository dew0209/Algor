// 题目链接：https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/

// 思路一：昨天暴力的代码也能过

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
            i = j - 1;
        }
        int res = -1;
        for(int i = 0;i < 26;i++){
            int len = cnt[i].size();
            if(len > 0){
                if(cnt[i][0] > 2){
                    res = max(cnt[i][0] - 2,res);
                }
                if(len > 1 && cnt[i][0] > 1){
                    res = max(min(cnt[i][0] - 1,cnt[i][1]),res);
                }
                if(len > 2){
                    res = max(cnt[i][2],res);
                }
            }
        }
        return res;
    }
};

// 思路二：后置排序

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<int> cnt[26];

        for(int i = 0;i < n;){
            int j = i + 1;
            while(j < n && s[i] == s[j])j++;
            cnt[s[i] - 'a'].push_back(j - i);
            i = j;
        }
        int res = -1;
        for(int i = 0;i < 26;i++){
            sort(cnt[i].begin(),cnt[i].end());
            reverse(cnt[i].begin(),cnt[i].end());
            int len = cnt[i].size();
            if(len > 0){
                if(cnt[i][0] > 2){
                    res = max(cnt[i][0] - 2,res);
                }
                if(len > 1 && cnt[i][0] > 1){
                    res = max(min(cnt[i][0] - 1,cnt[i][1]),res);
                }
                if(len > 2){
                    res = max(cnt[i][2],res);
                }
            }
        }
        return res;
    }
};


//思路：二分查找
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<int> cnt[26];
        for(int i = 0;i < n;){
            int j = i + 1;
            while(j < n && s[i] == s[j])j++;
            cnt[s[i] - 'a'].push_back(j - i);
            i = j;
        }
        int res = -1;
        
        for(int i = 0;i < 26;i++){
            int l = 1,r = n - 2;
            while(l <= r){
                int mid = (l + r) >> 1;
                int count = 0;
                for(auto x : cnt[i]){
                    if(x >= mid){
                        count += x - mid + 1;
                    }
                }
                if(count >= 3){
                    res = max(res,mid);
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
        }
        return res;
    }
};