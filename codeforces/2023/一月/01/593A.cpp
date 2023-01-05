#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

typedef long long LL;

using namespace std;

int n;
string s[105];

int main(){
    cin >> n;
    int res = 0;
    for(int i = 0;i < n;i++)cin >> s[i];
    for(char i = 'a';i <= 'z';i++){
        for(int j = i;j <= 'z';j++){
            int cnt = 0;
            for(int k = 0;k < n;k++){
                bool ok = 1;
                for(int q = 0;q < s[k].size();q++){
                    if(s[k][q] != i && s[k][q] != j){
                        ok = 0;
                        break;
                    }
                }
                if(ok){
                    cnt += s[k].size();
                }
            }
            res = max(cnt,res);
        }
    }
    cout << res << endl;
    return 0;
}