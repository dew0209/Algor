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

const int N = 510;

using namespace std;

int cnt[26];

int main(){
    string s;cin >> s;
    for(int i = 0;i < s.size();i++){
        cnt[s[i] - 'a']++;
    }
    int count = 0;
    for(int i = 0;i < 26;i++){
        if(cnt[i] % 2){
            count++;
        }
    }
    if(count > 0)count--;
    if(count % 2 == 0){
        printf("First");
    }else {
        printf("Second");
    }
}