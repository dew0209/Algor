class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<int> idx;
        map<char,int> cnt;
        map<char,int> sum;
        
        vector<char> count;
        for(int i = 0;i < n;i++){
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                idx.push_back(i);
                count.push_back(c);
                sum[c]++;
                if(!cnt.contains(c)){
                    cnt[c] = i;
                }
            }
        }
        sort(count.begin(),count.end(),[&](int a, int b) { 
            if(sum[a] != sum[b]){
                return sum[a] > sum[b];
            } 
            return cnt[a] < cnt[b];
        });
        for(int i = 0;i < idx.size();i++){
            s[idx[i]] = count[i];
        }
        return s;
    }
};