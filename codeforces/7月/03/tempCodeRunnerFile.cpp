#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;

int n;
int dist[N];

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int x;cin >> x;
        dist[x]++;
    }
    bool ok = true;
    for(int i = 1;i <= n;i++){
        if(dist[i] != 0 && dist[i] < 3){
            ok = false;
            break;
        }
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
}