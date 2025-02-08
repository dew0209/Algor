//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010,M = 1000010;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int q[N],d[N];
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c;ne[idx] = h[a],h[a] = idx++;
    d[b]++;
}

void topsort(){
    int hh = 0,tt = -1;
    for (int i = 1; i <= n + m; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if ( -- d[j] == 0)
                q[ ++ tt] = j;
        }
    }
}

int main(){

    cin >> n >> m;
    memset(h,-1,sizeof h);

    for(int i = 1;i <= m;i++){

        memset(st,0,sizeof st);

        int cnt;cin >> cnt;

        int start = n,end = 1;

        while(cnt--){
            int stop;cin >> stop;
            start = min(start,stop);
            end = max(end,stop);
            st[stop] = true;
        }

        int ver = n + i;
        for(int j = start;j <= end;j++){
            if(!st[j])add(j,ver,0);
            else add(ver,j,1);
        }
    }

    topsort();

    for(int i = 1;i <= n;i++)dist[i] = 1;

    for(int i = 0;i < n + m;i++){

        int j = q[i];

        for(int k = h[j];~k;k = ne[k]){

            dist[e[k]] = max(dist[e[k]],dist[j] + w[k]);

        }

    }

    int res = 0;

    for(int i = 1;i <= n;i++)res = max(res,dist[i]);

    cout << res << endl;

    return 0;
}


作者：lu0209
链接：https://www.acwing.com/activity/content/code/content/9190535/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。