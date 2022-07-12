#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

const int N = 200010;

int n,m;
int a[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    sort(a,a + n);
    int j = 0;
    int ans = 0;
    for(int i = 0;i < n;i++){
        //cout << a[i] << "debug";
        while(j < n && a[j] - a[i] <= 5){
            ans = max(ans,j - i + 1);
            ++j;
        }
    }
    cout << ans << endl;
}