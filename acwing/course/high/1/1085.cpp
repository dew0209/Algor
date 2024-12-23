//dp

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 15;

int f[N][10];

void init(){
    for(int i = 0;i <= 9;i++){
        if(i != 4){
            f[1][i]++;
        }
    }
    for(int i = 2;i < N;i++){
        for(int j = 0;j <= 9;j++){
            if(j == 4)continue;
            for(int k = 0;k <= 9;k++){
                if(k == 4 || j == 6 && k == 2)continue;
                f[i][j] += f[i - 1][k];
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
            if(j == 4 || last == 6 && j == 2)continue;
            res += f[i + 1][j];
        }
        if(x == 4 || last == 6 && x == 2)break;
        last = x;
        if(!i)res++;
    }
    return res;
}

int main(){
    init();
    int a,b;
    while(cin >> a >> b,a && b){
        cout << dp(b) - dp(a - 1) << endl;
    }
    return 0;
}