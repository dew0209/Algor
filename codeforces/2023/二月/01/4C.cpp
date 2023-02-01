#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

typedef long long LL;

using namespace std;

const int N = 100010;

int n;
map<string,int> cnt;


int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        string c;cin >> c;
        int count = cnt[c]++;
        if(count == 0){
            printf("OK\n");
        }else {
            cout << c << count << endl;
        }
    }
    return 0;
}