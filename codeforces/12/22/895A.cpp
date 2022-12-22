#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


typedef long long LL;

using namespace std;

const int N = 400;

int n;
int a[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++)scanf("%d",&a[i]);
    int ans = N;
    int l = 0,r = 0;
    int sum = 0;
    while(r < n){
        sum += a[r];
        while(sum > 180){
            ans = min(ans,2 * abs(180 - sum));
            sum -= a[l];
            l++;
        }
        ans = min(ans,2 * abs(180 - sum));
        r++;
    }
    printf("%d\n",ans);

    return 0;
}