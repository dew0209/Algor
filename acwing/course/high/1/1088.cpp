//dp

#include <iostream>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2000010;

typedef long long LL;


int n,m;
int oil[N],spend[N];
LL s[N];
int q[N];
bool st[N];


int main(){
    
    scanf("%d",&n);
    
    for(int i = 1;i <= n;i++){
        //cin >> spend[i] >> oil[i];
        scanf("%d%d",&oil[i],&spend[i]);
        oil[i + n] = oil[i];
        spend[i + n] = spend[i];
    }
    
    for(int i = 1;i <= 2 * n;i++){
        s[i] = oil[i] - spend[i];
        s[i] += s[i - 1];
    }
    
    int hh = 0,tt = -1;

    for(int i = 2 * n;i >= 1;i--){
        if(hh <= tt && q[hh] > i + n - 1)hh++;
        while(hh <= tt && s[q[tt]] >= s[i])tt--;
        q[++tt] = i;
        if(i <= n && s[q[hh]] - s[i - 1] >= 0)st[i] = true;
    }
    
    hh = 0,tt = -1;
    
    memset(s,0,sizeof s);
    oil[0] = oil[n];
    for(int i = 2 * n;i >= 1;i--){
        s[i] = oil[i] - spend[i - 1];
        s[i] += s[i + 1];
    }
    for(int i = 1;i <= 2 * n;i++){
        if(hh <= tt && q[hh] < i - n + 1)hh++;
        while(hh <= tt && s[q[tt]] >= s[i])tt--;
        q[++tt] = i;
        if(i > n && s[q[hh]] - s[i + 1] >= 0)st[i - n] = true;
    }
    
    for(int i = 1;i <= n;i++){
        if(st[i])printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}