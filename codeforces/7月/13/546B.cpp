#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 100010;

int n;
int q[N];

int main(){
    int n;cin >> n;
    map<int,int> cnt;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        cnt[x]++;
    }
    int res = 0;
    for(int i = 1;i <= 2 * n;i++){
        if(cnt[i] > 1){
            cnt[i + 1] += cnt[i] - 1;
            res += cnt[i] - 1;
            cnt[i] = 1;
        }
    }
    cout << res << endl;
}