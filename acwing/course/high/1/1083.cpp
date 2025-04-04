//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int f[N][10];


void init(){
    
    for(int i = 0;i <= 9;i++)f[1][i] = 1;
    
    for(int i = 2;i < N;i++){
        for(int j = 0;j <= 9;j++){
            for(int k = 0;k <= 9;k++){
                if(abs(j - k) >= 2){
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }
}

int dp(int u){
    
    if(!u)return 0;
    
    vector<int> nums;
    
    while(u)nums.push_back(u % 10),u /= 10;
    
    int n = nums.size();
    
    int last = -1;
    
    int res = 0;
    
    for(int i = n - 1;i >= 0;i--){
        
        int x = nums[i];
        
        for(int j = 0;j < x;j++){
            if(abs(j - last) >= 2){
                res += f[i + 1][j];
            }
            
        }
        if(abs(x - last) >= 2)last = x;
        else break;
        if(!i)res++;
    }

    for(int i = 1;i < n;i++){
        for(int j = 1;j <= 9;j++){
            res += f[i][j];
        }
    }
    return res;
}


int main(){
    init();
    int a,b;cin >> a >> b;
    cout << dp(b) - dp(a - 1) << endl;
    
    return 0;
}
