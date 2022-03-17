#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m, q;
string s, t;
char strs[N], strt[N];
int cnt[N];

int main(){
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s%s", strs, strt);
    s = strs, t = strt;
    s = ' ' + s;

    for (int i = m; i <= n; i ++ )
    {
        cnt[i] = cnt[i - 1];
        if (s.substr(i - m + 1, m) == t)
            cnt[i] ++ ;
    }

    while (q -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l += m - 1;
        if (l > r) puts("0");
        else printf("%d\n", cnt[r] - cnt[l - 1]);
    }
    return 0;
}