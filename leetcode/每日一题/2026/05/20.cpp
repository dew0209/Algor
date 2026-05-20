//https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2026-05-20

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n,0);
        map<int,int> cntA;
        map<int,int> cntB;
        for(int i = 0;i < n;i++){
            int x = A[i];
            int y = B[i];
            if(x == y){
                res[i] = i > 0 ? res[i - 1] + 1 : 1;
            }else {
                res[i] = i > 0 ? res[i - 1] : 0;
                if(cntB.contains(x)){
                    res[i]++;
                }else {
                    cntA[x]++;
                }
                if(cntA.contains(y)){
                    res[i]++;
                }else {
                    cntB[y]++;
                }
            }
        }
        return res;
    }
};