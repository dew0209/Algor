#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int N = 100010;

int n;
int q[N];

int main(){
    scanf("%d",&n);
    int res = 0;
    int odd = 0;
    int even = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
        if(q[i] % 2)odd++;
        else even++;
    }
    int ok = odd == 1;
    for(int i = 1;i <= n;i++){
        if(q[i] % 2 == ok){
            printf("%d",i);
        }
    }
    return 0;
}