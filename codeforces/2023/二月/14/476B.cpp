#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

const int N = 100010;

using namespace std;

double get(int a,int b){
    double res = 1;
    for(int i = a;i >= a - b + 1;i--){
        res *= i;
    }
    for(int i = 1;i <= b;i++){
        res /= i;
    }
    return res;
}


int main(){
    string a,b;cin >> a >> b;
    int ca = 0,cb = 0,t = 0;
    for(int i = 0;i < a.size();i++){
        if(a[i] == '+')ca++;
        if(a[i] == '-')cb++;
    }
    for(int i = 0;i < b.size();i++){
        if(b[i] == '+')ca--;
        if(b[i] == '-')cb--;
        if(b[i] == '?')t++;
    }
    ca = abs(ca);
    cb = abs(cb);
    double res = get(t,ca) * 1.0 * get(t - ca,cb) / pow(2,t);
    printf("%.12lf\n",res <= 0 ? 0 : res);
    return 0;
}