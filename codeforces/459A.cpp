//https://codeforces.com/problemset/problem/459/A

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int x1,y1,x2,y2;

int main(){
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        int d = abs(y1 - y2);
        
        if(x1 - d <= 1000 && x1 - d >= -1000){
            cout << x1 - d << ' ' << y1 << ' ' << x2 - d << ' ' << y2 << endl;
        }else {
            cout << x1 + d << ' ' << y1 << ' ' << x2 + d << ' ' << y2 << endl;
        }
    }else if(y1 == y2){
        int d = abs(x1 - x2);
        if(y1 - d <= 1000 && y1 - d >= -1000){
            cout << x1 << ' ' << y1 - d << ' ' << x2 << ' ' << y2 - d << endl;
        }else {
            cout << x1 << ' ' << y1 - d << ' ' << x2 << ' ' << y2 - d << endl;
        }
    }else if(abs(x1 - x2) == abs(y1 - y2)){
        cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << endl;
    }else cout << -1 << endl;
}