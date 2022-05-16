#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 200010;

LL q[N];
LL cnt[N];//操作的标记  防止被多次操作
int n,m,total;

int main(){
    cin >> n >> m;
    LL sum = 0;
    LL temp = -1;
    for(int i = 1;i <= n;i++){
        LL c;cin >> c;
        q[i] = c;
        sum += c;
    }
    cout << sum << "--" << endl;
    for(int i = 1;i <= m;i++){
        LL t,x,y;cin >> t >> x;
        if(t == 1){
            cin >> y;
            if(temp != -1 && cnt[x] < total)cnt[x] = total,q[x] = temp;
            sum += y - q[x];
            q[x] = y;
        }else {
            ++total;
            temp = x;
            sum = n * x;
        }
        cout << sum << endl;
    }
    return 0;
}