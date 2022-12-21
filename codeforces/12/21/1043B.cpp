#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


typedef long long LL;

using namespace std;

const int N = 1010;

int n;
int q[N];
int s[N];

bool check(int u){
    bool ok = 1;
    for(int i = 1;i + u <= n;i++) {
        if(q[i] - q[i - 1] != q[i + u] - q[i + u - 1]){
            ok = 0;
            break;
        }
    }
    return ok;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    //for(int i = 1;i <= n;i++)s[i] = s[i] - s[i - 1];
    vector<int> res;
    for(int i = 1;i <= n;i++){
        if(check(i)){
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for(auto c : res){
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}