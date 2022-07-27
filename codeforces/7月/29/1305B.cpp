#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int main(){
    string s;cin >> s;
    vector<int> cntl;
    vector<int> cntr;
    int n = s.size();
    int l = 0,r = n - 1;
    while(l < r){
        while(l < n && s[l] == ')')l++;
        while(r >= 0 && s[r] == '(')r--;
        if(l < r){
            cntl.push_back(l + 1);
            cntr.push_back(r + 1);
            l++,r--;
        }
    }
    if(cntl.empty()){
        cout << 0 << endl;
    }else {
        cout << 1 << endl;
        cout << 2 * cntl.size() << endl;
        for(int i = 0;i < cntl.size();i++)cout << cntl[i] << ' ';
        for(int i = cntr.size() - 1;i >= 0;i--)cout << cntr[i] << ' ';
    }
}