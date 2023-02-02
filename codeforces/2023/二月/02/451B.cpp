#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

#define pb push_back

using namespace std;

const int N = 100010;

int n;
int q[N];

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)scanf("%d",&q[i]);
    int ok = 0;
    int l = 1,r = 1;
    for(int i = 1;i <= n;i++){
        int j = i;
        while(j + 1 <= n && q[j] >= q[j + 1])j++;
        if(j != i && q[i] != q[j]){
            ok++;
            l = i,r = j;
        }
        i = j;
    }
    if(ok == 1 && ((r + 1 <= n && q[l] > q[r + 1])  || (l - 1 >= 1 && q[r] < q[l - 1]))){
        printf("no\n");
        return 0;
    }
    if(ok == 1 || ok == 0){
        printf("yes\n%d %d",l,r);
    }else {
        printf("no\n");
    }
    return 0;
}