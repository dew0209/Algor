//题目连接：https://leetcode.cn/problems/implement-magic-dictionary/description/?envType=daily-question&envId=2024-08-12

//思路：暴力


class MagicDictionary {
public:
    vector<string> dict;
    MagicDictionary() {

    }

    bool check(string st,string search){
        int cnt[26];
        for(int i = 0;i < 26;i++)cnt[i] = 0;
        int n = st.size();
        int m = search.size();
        if(n != m)return false;

        int res = 0;
        for(int i = 0,j = 0;i < n;i++,j++){
            if(st[i] != search[j]){
                res++;
            }
        }

        return res == 1;
    }
    
    void buildDict(vector<string> dictionary) {
        dict = dictionary;
    }
    
    bool search(string searchWord) {
        int n = dict.size();
        for(int i = 0;i < n;i++){
            string st = dict[i];
            if(check(st,searchWord)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */