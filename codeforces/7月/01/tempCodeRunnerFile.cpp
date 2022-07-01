#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
char res[110][110];


int main(){
    cin >> n >> m;
    int op = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(op){
                if(j){
                    res[i][j] = 'B';
                }else {
                    res[i][j] = 'W';
                }
                
            }else {
                if(j){
                    res[i][j] = 'W';
                }else {
                    res[i][j] = 'B';
                }
            }
        }
        op ^= 1;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            char c;cin >> c;
            if(c == '-')res[i][j] = c;
            //cout << res[i][j];
        }
        //cout << endl;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << res[i][j];
        }
        cout << endl;
    }
}