#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 40000;

int n;
int q[N];
int f[N];


int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    for(int i = 0;i < n;i++){
        int ans = 15;
        for(int j = 0;j < 15;j++){
            for(int k = 0;k < 15;k++){
                if((q[i] + j) * (int)pow(2,k) % 32768 == 0){
                    ans = min(ans,j + k);
                }
            }
        }
        printf("%d ",ans);
    }
    return 0;
}