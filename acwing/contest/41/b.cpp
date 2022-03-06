#include <iostream>
#include <cstring>
#include <set>

using namespace std;

struct Line{
    int a,b,c;
    bool operator< (Line l) const {
        if(a != l.a)return a < l.a;
        if(b != l.b)return b < l.b;
        if(c != l.c)return c < l.c;
        return false;
    }
};

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

int n,x0,y0;

int main(){
    cin >> n >> x0 >> y0;
    set<Line> S;
    for(int i = 0;i < n;i++){
        int x1,y1;cin >> x1 >> y1;
        int a = y1 - y0;
        int b = x0 - x1;
        int gg = gcd(a,b);
        a /= gg;
        b /= gg;
        int c = -a * x0 - b * y0;
        if(a < 0)a = -a,b = -b,c = -c;
        S.insert({a,b,c});
    }
    cout << S.size() << endl;

    return 0;

}