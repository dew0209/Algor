#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int main(){
    string s;cin >> s;
    bool ok = false;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'a')continue;
        int j = i;
        while(j < s.size() && s[j] != 'a')j++;
        for(int k = i;k < j;k++){
            --s[k];
        }
        ok = true;
        break;
    }
    if(!ok)s[s.size() - 1] = 'z';
    cout << s << endl;
}