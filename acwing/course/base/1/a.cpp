#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int n;
int q[N];

void quick_sort(int l,int r){
    if(l >= r)return;
    int x = q[l + r >> 1];
    int i = l - 1,j = r + 1;
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j)swap(q[i],q[j]);
    }
    quick_sort(l,j);
    quick_sort(j + 1,r);
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    quick_sort(0,n - 1);
    for(int i = 0;i < n;i++)cout << q[i] << ' ';
    cout << endl;
}