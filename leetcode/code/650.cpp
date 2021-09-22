#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int f[N];

class Solution {
public:
    int minSteps(int n) {
        f[1] = 0;
        for(int i = 2;i < n;i++){
            f[i] = i;
            for(int j = 2;j <= i;j++){
                if(i % j == 0){
                    f[i] = min(f[i],f[j] + i / j);
                }
            }
        }
        return f[n];
    }
};