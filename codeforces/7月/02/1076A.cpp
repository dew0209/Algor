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
    int n;
    string s;
    cin >> n >> s;
    int pos = -1;
    for(int i = 0;i < n - 1;i ++){
        if(s[i] > s[i + 1]){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        s = s.substr(0,pos) + s.substr(pos + 1);
    }else {
        s = s.substr(0,n - 1);
    }
    cout << s << endl;
}