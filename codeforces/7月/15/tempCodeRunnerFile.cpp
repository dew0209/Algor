#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
int a[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    int res = -1;
    for(int d = 4;d <= 4;d++){
        bool ok = true;
        int diff = -1;
        for(int i = 1;i <= n;i++){
            int diffAbs = abs(a[i] - d);
            if(diff == - 1 || diff == diffAbs || diff == 0){
                diff = diffAbs;
                //cout << diff << "dede" << endl;
            }else if(diffAbs != 0) {
                ok = false;
                break;
            }
        }
        if(ok){
            if(res == -1){
                res = diff;
            }else {
                res = min(res,diff);
            }
        }
    }
    cout << res << endl;
    return 0;
}