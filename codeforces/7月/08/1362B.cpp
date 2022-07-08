#include <iostream>

using namespace std;

const int N = 100100;

int n;
int in[N];
int is[N];

bool check(int u){
    for(int i = 1;i <= n;i++){
        if(!is[in[i] ^ u])return false;
    }
    return true;
}

void solve(){
    for(int i = 0;i < N;i++)is[i] = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> in[i];
        is[in[i]] = true;
    }
    for(int k = 1;k < 1024;k++){
        if(check(k)){
            cout << k << endl;
            return ;
        }
    }
    cout << "-1" << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}