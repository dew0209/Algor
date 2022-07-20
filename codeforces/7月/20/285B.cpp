#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 200010;

int n,s,t;
int q[N];

int main(){
    cin >> n >> s >> t;
    int ok = -1;
    for(int i = 1;i <= n;i++)cin >> q[i];
    for(int i = 0;i < n;i++){
        if(s == t){
            ok = i;
            break;
        }
        s = q[s];
    }
    cout << ok << endl;
}