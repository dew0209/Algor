#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        bool ok = false;
        if(s1 == s2)ok = true;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                swap(s1[i],s1[j]);
                if(s1 == s2){
                    ok = true;
                    break;
                }
                swap(s1[i],s1[j]);
            }
        }
        return ok;
    }
};