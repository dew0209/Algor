#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int a[N],b[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n);
    cin >> m;
    for(int i = 0;i < m;i++){
        cin >> b[i];
    }
    sort(b,b + m);
    int res = 0;
    int i = 0,j = 0;
    
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= 1){
            res++;
            i++;
            j++;
        }else {
            if(a[i] < b[j])i++;
            else j++;
        }
    }
    cout << res << endl;
}