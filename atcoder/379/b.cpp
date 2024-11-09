#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const int N = 20;

int n,k;





int main(){
    string s;
    cin >> n >> k;
    cin >> s;

    int res = 0;

    for(int i = 0,j = 0;i < n;i++){
        if(s[i] == 'O'){
            if(i - j + 1 >= k){
                res++;
                j = i + 1;
            }
        }else {
            j = i + 1;
        }
    }
    cout << res << endl;
}