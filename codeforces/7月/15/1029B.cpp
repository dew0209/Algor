#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int a[N];


int main(){
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int j = i;
        while(j + 1 <= n && a[j + 1] <= a[j] * 2)j++;
        ans = max(ans,j - i + 1);
        i = j;
    }
    cout << ans << endl;
}
