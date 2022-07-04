//https://codeforces.com/contest/1272/problem/C
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100010;

typedef long long LL;

int n,m;

int main(){
    cin >> n >> m;
    string s;cin >> s;
    set<char> cnt;
    for(int i = 0;i < m;i++){
        char c;cin >> c;
        cnt.insert(c);
    }
    LL res = 0;
    for(int i = 0;i < n;i++){
        int j = i;
        while(j < n && cnt.find(s[j]) != cnt.end()){
            j++;
        }
        int len = j - i;
        i = j;
        res += len * 1LL * (len + 1) / 2;
    }
    cout << res << endl;
}