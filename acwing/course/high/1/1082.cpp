//dp

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 15;

int f[N][N];

void init(){
    for(int i = 1;i <= 9;i++)f[1][i] = 1;
    for(int i = 2;i < N;i++){
        for(int j = 0;j <= 9;j++){
            for(int k = j;k <= 9;k++){
                f[i][j] += f[i - 1][k];
            }
        }
    }
}

int dp(int u){
    if(!u)return 0;
    vector<int> nums;
    while(u)nums.push_back(u % 10),u /= 10;
    int n = nums.size();
    int last = 0;
    
    int res = 0;
    for(int i = n - 1;i >= 0;i--){
        int x = nums[i];
        for(int j = last;j < x;j++){
            res += f[i + 1][j];
        }
        if(x < last)break;
        last = x;
        if(!i)res++;
    }
    return res;
}

int main(){
    init();
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        cout << dp(b) - dp(a - 1) << endl;
    }
    return 0;
}