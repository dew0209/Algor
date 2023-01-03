#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

typedef long long LL;

using namespace std;

const int N = 200010;

int n;
int q[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    vector<int> cnt0;
    vector<int> res(n + 1);
    for(int i = 1;i <= n;i++){
        if(q[i] == 0)cnt0.push_back(i);
    }
    int idx = 0;
    //cout << cnt0.size() << endl;
    for(int i = 1;i <= n;i++){
        while(cnt0[idx] < i && idx < cnt0.size() - 1)idx++;
        //cout << idx << "===" << cnt0[idx] << endl;
            if(idx >= 1 && cnt0[idx] >= i){
                res[i] = min(cnt0[idx] - i,i - cnt0[idx - 1]);
                //cout << i << " 1" << endl;
            }else if(idx == 0 && cnt0[idx] >= i){
                res[i] = cnt0[idx] - i;
                //cout << i << " 2" << endl;
            }else if(i >= cnt0[idx]){
                res[i] = i - cnt0[idx];
                //cout << i << " 3" << endl;
            }
        
    }
    for(int i = 1;i <= n;i++){
        cout << res[i];
        if(i < n)cout << ' ';
        else cout << endl;
    }
    return 0;
}