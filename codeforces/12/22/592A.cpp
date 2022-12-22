#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


typedef long long LL;

using namespace std;

const int N = 400;

int n;
int q[N];
string str[10];

int main(){
    for(int i = 0;i < 8;i++)cin >> str[i];
    int a = N,b = N;
    for(int i = 0;i < 8;i++){
        bool ok = 0;
        for(int j = 0;j < 8;j++){
            if(str[j][i] == 'B'){
                ok = 1;
            }
            if(str[j][i] == 'W'){
                if(!ok){
                    a = min(a,j);
                }
            }
        }
    }
    for(int i = 7;i >= 0;i--){
        bool ok = 0;
        for(int j = 7;j >= 0;j--){
            if(str[j][i] == 'W'){
                ok = 1;
            }
            if(str[j][i] == 'B'){
                if(!ok){
                    b = min(7 - j,b);
                }
            }
        }
    }
    //cout << a << ' ' << b << endl;
    if(a <= b){
        cout << "A" << endl;
    }else cout << "B" << endl;

    return 0;
}