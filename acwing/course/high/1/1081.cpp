//dp

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 35;

int X,Y,K,B;
int g[N][N];

void init(){
    for(int i = 0;i < N;i++)g[i][0] = 1;
    for(int i = 1;i < N;i++){
        for(int j = 1;j <= i;j++){
            g[i][j] = g[i - 1][j] + g[i - 1][j - 1];
        }
    }
}

int dp(int u){
    if(!u)return 0;
    vector<int> nums;
    while(u)nums.push_back(u % B),u /= B;
    int n = nums.size();
    int last = 0;
    int res = 0;
    for(int i = n - 1;i >= 0;i--){
        int x = nums[i];
        if(x){
            res += g[i][K - last];
            if(x > 1){
                if(K - last - 1 >= 0)res += g[i][K - last - 1];
                break;
            }else {
                last++;
                if(last > K)break;
            }
        }
        if(!i && last == K)res++;
    }
    return res;
}

int main(){
    init();
    cin >> X >> Y >> K >> B;
    cout << dp(Y) - dp(X - 1) << endl;
    return 0;
}