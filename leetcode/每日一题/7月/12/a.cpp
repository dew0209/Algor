#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> a(m);//行
        vector<int> b(n);//列
        for(int i = 0;i < indices.size();i++){
            int ri = indices[i][0];
            int ci = indices[i][1];
            a[ri]++;
            b[ci]++;
        }
        int res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if((a[i] + b[j]) % 2)res++;
            }
        }
        return res;
    }
};