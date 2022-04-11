//https://codeforces.com/problemset/problem/327/A
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[110];

int main(){
    int n;
    cin >> n;
    //前缀和
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int res = 0;
    int ok = 0;
    //a[i]：表示1~i中1的数量和
    //必须经过一次翻转
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            //翻转i~j
            int sum = j - i + 1;
            int sumA = a[j] - a[i - 1];//1 的数量
            int sumB = sum - sumA;//0 的数量
            if(sumB > sumA){
                ok = 1;
                res = max(res,a[i - 1] + a[n] - a[j - 1] + sumB);
            }
        }
    }
    if(!ok){
        //没有翻转
        if(a[n] != n)res = 0;
        else res = n - 1;
    }
    cout << res << endl;

    return 0;
}