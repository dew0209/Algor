#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n,m;
bool st[N];
int q[N];

int main(){
    cin >> n >> m;
    int res = 0;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        if(!st[c]){
            st[c] = true;
            q[res++] = i;

        }
    }
    if(res < m)cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i = 0; i < m;i++)cout << q[i] << ' ';
    }
}