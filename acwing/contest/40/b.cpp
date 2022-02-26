#include <iostream>

using namespace std;

const int N = 100010;

int n;
int cnt[N];
int a[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        cnt[c]++;
    }
    int res = 0;
    for(int i = 1;i <= N;i++){
        if(cnt[i] > 0){
            res += cnt[i] - 1;
            cnt[i + 1] += cnt[i] - 1;
        }
    }
    cout << res << endl;

    return 0;
}