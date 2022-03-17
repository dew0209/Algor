#include <iostream>

using namespace std;

const int N = 100010;

int n,m;

int main(){
    cin >> n >> m;
    double minv = 100;
    while(n--){
        double a,b;cin >> a >> b;
        double res = a / b;
        minv = min(minv,res);
    }
    printf("%.6lf",m * minv);
    return 0;
}