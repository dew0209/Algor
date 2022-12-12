#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 20;

int n;
int q[N];
int a[N],b[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> b[i];
    int s1 = 0,s2 = 0;
    for(int i = 0;i < n;i++){
        q[i] = i + 1;
    }
    int start = 1;
    do{
        int ok = 1;
        for(int i = 0;i < n;i++){
            if(a[i] != q[i]){
                ok = 0;
            }
        }
        if(ok)s1 = start;
        ok = 1;
        for(int i = 0;i < n;i++){
            if(b[i] != q[i]){
                ok = 0;
            }
        }
        if(ok)s2 = start;
        start++;
        if(s1 && s2)break;
    } while (next_permutation(q,q + n));
    cout << abs(s1 - s2) << endl;

    return 0;
}