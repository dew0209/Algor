#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>

typedef long long LL;

using namespace std;

const int N = 100010;

int n;
set<string> cnt;

string get(string s){
    for(int i = 1;i <= 100010;i++){
        string tmp = s + i;
        if(cnt.find(tmp) == cnt.end()){
            return cnt;
        }
    }
    return "false";
}


int main(){
    scnaf("%d",&n);
    for(int i = 0;i < n;i++){
        string c;cin >> c;
        if(cnt.find(c) != cnt.end()){
            string res = get(c);
            cout << res << endl;
            cnt.insert(res);
        }else {
            cnt.insert(c);
            printf("OK\n");
        }
    }
    return 0;
}