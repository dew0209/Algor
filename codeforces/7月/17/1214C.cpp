#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int main(){
    int n;string s;cin >> n >> s;
    int count = 0;
    int a = 0,b = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == ')')a++;
        else b++;
        if(a > b){
            count = max(count,a - b);
        }
    }
    if(count > 1 || a != b)cout << "NO" << endl;
    else cout << "YES" << endl;
}