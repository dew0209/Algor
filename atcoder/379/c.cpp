#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const int N = 200010;

int n,m;

int X[N];
int A[N];

pair<int,int> arr[N];



int main(){
    
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> X[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> A[i];
        arr[i - 1] = {X[i],A[i]};
    }

    sort(arr,arr + m);

    LL res = 0;

    //从1开始干
    LL st = 1;
    int j = 0;
    while(true){
        if(st == (LL)n + 1 && j == m){
            break;
        }
        if(st > (LL)n + 1 || j >= m || st < (LL)arr[j].first){
            res = -1;
            break;
        }
        if(st > arr[j].first){
            res = res + (LL)(st - arr[j].first) * (LL)arr[j].second;
        }
        

        LL newSt = (LL)st + arr[j].second - 1;
        res = res + (LL)(1 + arr[j].second - 1) * (LL)(arr[j].second - 1) / 2;

        j++;
        st = newSt + 1;
    }
    cout << res << endl;
}