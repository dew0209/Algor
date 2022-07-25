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
    int n;cin >> n;
    int c = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] != '*' && s[i] != '?')c++;
    }
    for(int i = 0;i < s.size();i++){
        if(s[i] == '*' && c < n)s.insert(i,n - c,s[i - 1]),c = n;
        else if(s[i] == '*' || s[i] == '?'){
            s.erase(i--,1);
            if(c > n)s.erase(i--,1),c--;
        }
    }
    
    cout << (n == c ? s : "Impossible") << endl;
}