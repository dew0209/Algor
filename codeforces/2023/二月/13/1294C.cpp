#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 200010;

int main(){

    int n;scanf("%d",&n);
    while(n--){
        unordered_map<int,int> primes;
        int x;
        cin >> x;

        for(int i = 2;i <= x/i;i++)
            while(x%i == 0){
                x /= i;
                primes[i]++;
            }
        if(x > 1)primes[x]++;
        LL res = 0;

        for(auto prime : primes){
            res = res + prime.second;
        }

        if(res <= 2){
            printf("NO\n");
        }else {
            LL a = 1;
            LL b = 1;
            LL c = 1;
            for(auto prime : primes){
                int count = prime.second;
                
                if(a == 1 && count > 0){
                    a = prime.fi;
                    count--;
                }
                while((b == 1 || a == b) && count > 0){
                    b = b * prime.fi;
                    count--;
                }
                c = c * pow(prime.fi,count);
                
            }
            if(a != b && a != c && b != c && a >= 2 && b >= 2 && c >= 2){
                printf("YES\n%lld %lld %lld\n",a,b,c);
            }else {
                printf("NO\n");
            }
        }
    }
}