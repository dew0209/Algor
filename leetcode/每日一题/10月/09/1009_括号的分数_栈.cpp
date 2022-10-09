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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;


class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int st[n + 1];
        int idx = -1;
        st[++idx] = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '(')st[++idx] = 0;
            else {
                int v = st[idx--];
                st[idx] += max(2 * v,1);
            }
        }
        return st[0];
    }
};