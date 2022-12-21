#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


typedef long long LL;

using namespace std;

const int N = 5010;

vector<vector<int>> ans(N);

int n;

int main(){
       
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d",&n);
    for(int i = 1;i <= 2 * n;i++){
        int c;
        scanf("%d",&c);
        ans[c].push_back(i);
    }
    bool ok = 1;
    for(int i = 1;i < N;i++){
        if(ans[i].size() % 2 != 0){
            ok = 0;
            break;
        }
    }
    if(!ok){
        printf("%d\n",-1);
        //cout << -1 << endl;
    }else {
        for(int i = 1;i < N;i++){
            for(int j = 0;j < ans[i].size();j += 2){
                //cout << ans[i][j] << ' ' << ans[i][j + 1] << endl;
                printf("%d %d\n",ans[i][j],ans[i][j + 1]);
            }
        }
    }
    return 0;
}