//https://codeforces.com/problemset/problem/327/A
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[110];
int f[110];

/**
 * 
 * 思路：
 *      看影响：
 *              1 翻转  -1
 *              0 翻转  1
 *      结果为 s + 翻转区间[i,j]  （s是原来的1的数量）
 *      根据影响，重新构造数组，求一段连续子数组最大的和 + s 即为答案   
 * @author LoveLJ
 */

int main(){
    int n;
    cin >> n;
    int s = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i])s++;
        a[i] = a[i] == 1 ? -1 : 1;
    }
    int res = 0;
    //O(n)
    for(int i = 1;i <= n;i++){
        f[i] = max(a[i] + f[i - 1],a[i]);
        res = max(res,s + f[i]);
    }
    cout << res << endl;
    return 0;
}