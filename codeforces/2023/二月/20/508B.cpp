#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

string get_res(string r,string s){
    int len = r.size();
    for(int i = 0;i < len;i++){
        if(r[i] > s[i])return r;
        else if(r[i] < s[i])return s;
    }
    return r;
}

int main(){
    string s;cin >> s;
    string t = s;
    string q = s;
    int n = s.size();
    int a = -1;
    int b = -1;
    for(int i = n - 2;i >= 0;i--){
        if((s[i] - '0') % 2 == 0 && s[i] > s[n - 1]){
            a = i;
            break;
        }
    }
    for(int i = 0;i < n - 1;i++){
        if((s[i] - '0') % 2 == 0 && s[i] < s[ n - 1]){
            b = i;
            break;
        }
    }
    if(a == -1 && b == -1){
        printf("-1\n");
    }else if(a == -1 && b != -1){
        swap(t[b],t[n - 1]);
        cout << t << endl;
    }else if(a != -1 && b == -1){
        swap(q[a],q[n - 1]);
        cout << q << endl;
    }else {
        swap(t[b],t[n - 1]);
        swap(q[a],q[n - 1]);
        cout << get_res(t,q) << endl;
    }
    return 0;
}