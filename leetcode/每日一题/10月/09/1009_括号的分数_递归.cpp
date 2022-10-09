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
        return dfs(s);
    }
    int dfs(string s){
        if(s.size() == 2)return 1;
        int len = 0,sum = 0;
        int n = s.size();
        for(int i = 0;i < n;i++){
            sum += s[i] == '(' ? 1 : -1;
            if(sum == 0){
                len = i + 1;
                break;
            }
        }
        if(len == n){
            return 2 * dfs(s.substr(1,n - 2));
        }else {
            return dfs(s.substr(0,len)) + dfs(s.substr(len));
        }
    } 
};