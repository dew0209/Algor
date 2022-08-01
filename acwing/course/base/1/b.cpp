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
int q[N],tmp[N];

void merge_sort(int l,int r){
    if(l >= r)return;
    int mid = l + r >> 1;
    merge_sort(l,mid),merge_sort(mid + 1,r);
    int i = l,j = mid + 1,k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j])tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i <= mid)tmp[k++] = q[i++];
    while(j <= r)tmp[k++] = q[j++];
    for(i = l,k = 0;i <= r;i++,k++)q[i] = tmp[k];
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    merge_sort(0,n - 1);
    for(int i = 0;i < n;i++)cout << q[i] << ' ';
    cout << endl;
}