#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;

int n;
int dist[N];
int st[N];

int main(){
    cin >> n;
    vector<vector<int>> p(n + 10);
    for(int i = 1;i < n;i++){
        int x;cin >> x;
        dist[x]++;
        p[x].push_back(i + 1);
    }
    for(int i = 1;i <= n;i++){
        if(dist[i])st[i] = 1;
        for(auto c : p[i]){
            if(dist[c]){
                dist[i]--;
            }
        }
    }
    bool ok = true;
    //cout << "dist" << endl;
    for(int i = 1;i <= n;i++){
        //cout << dist[i] << ' ';
        if(dist[i] != 0 && dist[i] < 3){
            ok = false;
            break;
        }
        if(dist[i] == 0 && st[i]){
            ok = false;
            break;
        }
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
}