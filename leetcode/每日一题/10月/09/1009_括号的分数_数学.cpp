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
        int bal = 0;
        int sum = 0;
        int n = s.size();
        for(int i = 0;i < n;i++){
            bal += s[i] == '(' ? 1 : -1;
            if(s[i] == ')' && s[i - 1] == '('){
                sum += 1 << bal;
            }
        }
        return sum;
    }
};