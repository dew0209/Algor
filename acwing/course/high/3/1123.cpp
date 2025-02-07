//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int n,m;
int x,y;

int main(){
    
    cin >> x >> y;
    
    double a,b,c,d;
    double sum;
    while(cin >> a >> b >> c >> d){
        sum = sum + sqrt((a - c) * (a - c) + (b - d) * (b - d)) * 2;
    }
    
    int minutes = round(sum / 1000 / 20 * 60);
    int hour = minutes / 60;
    minutes %= 60;
    printf("%d:%02d\n",hour,minutes);
    return 0;
}