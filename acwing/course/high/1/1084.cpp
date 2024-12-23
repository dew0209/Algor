//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15,M = 110;

int p;
int f[N][10][M];

int mod(int x,int y){
    return (x % y + y) % y;
}

void init(){
    memset(f,0,sizeof f);
    for(int i = 0;i <= 9;i++)f[1][i][i % p]++;
    for(int i = 2;i < N;i++){
        for(int j = 0;j <= 9;j++){
            for(int k = 0;k < p;k++){
                for(int x = 0;x <= 9;x++){
                    f[i][j][k] += f[i - 1][x][mod(k - j,p)];
                }
            }
        }
    }
}

int dp(int u){
    
    if(!u)return 1;
    
    vector<int> nums;
    
    while(u)nums.push_back(u % 10),u /= 10;
    
    int n = nums.size();
    
    
    int res = 0;
    int last = 0;
    
    for(int i = n - 1;i >= 0;i--){
        int x = nums[i];
        for(int j = 0;j < x;j++){
            res += f[i + 1][j][mod(-last,p)];
        }
        last += x;
        if(!i && last % p == 0)res++;
    }
    return res;
}

int main(){
    int a,b;
    while(~scanf("%d%d%d",&a,&b,&p)){
        init();
        cout << dp(b) - dp(a - 1) << endl;
    }
    return 0;
}