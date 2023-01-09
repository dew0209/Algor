#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n,m;
int q[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)scanf("%d",&q[i]);
    while(m--){
        int c;scanf("%d",&c);
        int l = 0,r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= c)r = mid;
            else l = mid + 1;
        }
        if(q[l] != c){
            printf("-1 -1\n");
        }else {
            printf("%d ",l);
            l = 0,r = n - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(q[mid] <= c)l = mid;
                else r = mid - 1;
            }
            printf("%d\n",l);
        }
    }
    return 0;
}