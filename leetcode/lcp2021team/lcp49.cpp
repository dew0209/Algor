/*
 * 看了楼教主的代码写出来的
 * 大致思路为：
 *      二进制枚举每个1，如果不需要该1可以完成任务，则必不要
 *                    如果不需要该1不可以完成任务，则必要
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

using VI=vector<int>;
using VLL=vector<LL>;

#define next(p) (p == n-1 ? 0 : p + 1)
#define prev(p) (p == 0 ? n - 1 : p - 1)

const int N = 50010;

class Solution {
public:
    VLL a;
    VI order;
    int n;
    bool solve(LL val){
        VI visited(n);
        for(int src : order){
            if(val < a[src])continue;
            if(visited[src])continue;
            LL key = (val | a[src]);
            visited[src] = 1;
            int s = src;
            int t = src;
            while(1){
                if(next(t) == s)return 1;
                if(key >= a[prev(s)])
                    key |= a[s = prev(s)],visited[s] = 1;
                else if(key >= a[next(t)])
                    key |= a[t = next(t)],visited[t] = 1;
                else break;
            }
        }
        return 0;
    }
    LL ringGame(vector<long long>& _a) {
        a = _a;
        n = _a.size();
        order = VI(n);
        for(int i = 0;i < n;i++)order[i] = i;
        sort(order.begin(),order.end(),[&](int x,int y){return a[x] > a[y];});
        LL ret = 0;
        for(LL i = (1LL<<61);i > 0;i /= 2)if(!solve((ret | i) - 1))ret |= i;
        return ret;
    }
};