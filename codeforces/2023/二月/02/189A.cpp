#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

#define pb push_back

using namespace std;

const int N = 100010;

int n,a,b,c;

int main(){
    scanf("%d%d%d%d",&n,&a,&b,&c);
    int res = 0;
    for(int i = 0;i < 4010;i++){
        for(int j = 0;j < 4010;j++){
            int tmp = n - i * a - j * b;
            if(tmp >= 0 && tmp % c == 0){
                res = max(i + j + (tmp / c),res);
            }
        }
    }
    printf("%d\n",res);
    return 0;
}