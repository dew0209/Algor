#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;

int n;

const int N = 200010;

LL query(vector<LL>& cnt,LL u,LL last){

    if(cnt.size() == 0){
        return -1;
    }

    int l = 0,r = cnt.size() - 1;

    while(l < r){
        int mid = l + r  + 1 >> 1;
        if(u <= cnt[mid] - last){
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    
    if(cnt[l] - last >= u )return cnt[l];
    return -1;
}

int main(){
    cin >> n ;
    
    vector<LL> w;
    map<LL,int> cnt;
    int a = 0;
    LL t = 0;
    LL h = 0;
    LL lastre = 0;
    for(int i = 1;i <= n;i++){
        
        int op;cin >> op;
        if(op == 1){
            a++;
        }else if(op == 2) {
            LL T;cin >> T;
            t = t + T;
            w.push_back(t);
            cnt[t] = a;
        }else if(op == 3){
            LL H;cin >> H;
            LL d = query(w,H,0);
            if(d == -1){
                cout << 0 << endl;
            }else {
                cout << max(0LL,cnt[d] - lastre) << endl;
                lastre = lastre + max(0LL,cnt[d] - lastre);
            }
            h = h + H;
        }

    }
    return 0;
}