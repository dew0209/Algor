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
    int n;cin >> n;
    vector<int> a;
    for(int i = 0;i < n;i++){
        int c;
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    bool ok = a.size() > 3;
    if(ok)cout << "NO" << endl;
    else {
        
        if(a.size() == 3 && abs(a[0] - a[1]) != abs(a[1] - a[2])){
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
        }
    }
}