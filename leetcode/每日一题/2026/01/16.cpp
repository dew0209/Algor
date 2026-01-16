//https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/?envType=daily-question&envId=2026-01-16


class Solution {
public:
    int MOD = 1e9 + 7;
    unordered_set<int> f(vector<int>& fences){
        unordered_set<int> res;
        int n = fences.size();
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                res.insert(fences[j] - fences[i]);
            }
        }
        return res;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int> a = f(hFences);
        unordered_set<int> b = f(vFences);

        int r = 0;

        for(auto& c : a){
            if(b.contains(c)){
                r = max(c,r);
            }
        }
        if(r == 0)return -1;
        return 1LL * r * r % MOD;
    }
};