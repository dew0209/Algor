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

const int N = 200010,MOD = 1e9 + 7;

int cnt[3];

int main(){
    
    for(int i = 0;i < 3;i++){
        string s;cin >> s;
        if(s[1] == '<'){
            cnt[s[2] - 'A']++;
        }else {
            cnt[s[0] - 'A']++;
        }
    }
    if(cnt[0] == cnt[1] || cnt[1] == cnt[2] || cnt[0] == cnt[2]){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(i == cnt[j])cout << (char)('A' + j);
        }
    }
    cout << endl;
    return 0;
}