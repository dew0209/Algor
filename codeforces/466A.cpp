#include <iostream>

using namespace std;

const int N = 100010;

double n,m,a,b;

int main(){
    cin >> n >> m >> a >> b;
    int res = 0;
    if(b / m < a){
        int cnt = (int)(n / m);
        if(cnt * b + (n - cnt * m) * a < (cnt + 1) * b){
            res = (int)(cnt * b + (n - cnt * m) * a);
        }else {
            res = (int)((cnt + 1) * b);
        }
    }else {
        res = (int)(n * a);
    }
    cout << res << endl;

    return 0;
}