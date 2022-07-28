#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int main(){
    string s,t;
    vector<int> res;
    int n;
    cin >> n;
    cin >> s >> t;
    for(int i = 0;i < n;i++){
        if(s[i] == t[i])continue;
        int pos = -1;
        for(int j = i + 1;j < n;j++){
            if(s[j] == t[i]){
                pos = j;
                break;
            }
        }
        if(pos == -1){
            cout << -1 << endl;
            return 0;
        }
        for(int j = pos - 1;j >= i;j--){
            swap(s[j],s[j + 1]);
            res.push_back(j + 1);
        }
    }
    cout << res.size() << endl;
    for(int i = 0;i < res.size();i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}