#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

typedef long long LL;

using namespace std;

int main(){
    string s;cin >> s;
    int n = s.size();
    int r = (n + 19) / 20;
    //每行分几个
    int len = (n + r - 1) / r;
    //需要补几个星
    int cnt = len * r - n;
    int st = 0;
    cout << r << ' ' << len << endl;
    for(int i = 0;i < r;i++){
        int cl = len - (cnt > 0);
        for(int j = st;j < st + cl;j++){
            cout << s[j];
        }
        st = st + cl;
        if(cnt > 0){
            cout << "*";
        }
        cout << endl;
        cnt--;
    }
    return 0;
}