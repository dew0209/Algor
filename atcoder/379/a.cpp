#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const int N = 20;

int n;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};



int main(){
    
    cin >> n;

    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n;


    cout << b * 100 + c * 10 + a << ' ' << c * 100 + a * 10 + b << endl;
    
}