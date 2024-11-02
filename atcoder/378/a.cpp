#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

#define x first
#define y second

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int a[10];

int main(){
    
    cin >> a[0];
    cin >> a[1];
    cin >> a[2];
    cin >> a[3];
    map<int,int> cnt;
    cnt[a[0]]++;
    cnt[a[1]]++;
    cnt[a[2]]++;
    cnt[a[3]]++;
    int res = 0;
    for(auto [k,v] : cnt){
        if(v >= 2){
            res += v / 2;
        }
    }
    cout << res << endl;
}