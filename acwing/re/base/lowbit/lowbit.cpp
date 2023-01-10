#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int c[N];
int res[N];

int lowbit(int n){
    int cnt = 0;
    for(int i = n;i;i -= i&(-i))cnt++;
    return cnt;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> c[i];
    }
    for(int i = 0;i < n;i++){
        res[i] = lowbit(c[i]);
    }
    for(int i = 0;i < n;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    return 0;
}