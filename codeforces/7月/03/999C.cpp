#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n,k;
string s;
int st[400010];

int main(){
    cin >> n >> k;
    cin >> s;
    vector<int> a(26);
    for(int i = 0;i < n;i++)a[s[i] - 'a']++;
    int pos = 26;
    for(int i = 0;i < 26;i++){
        if(k >= a[i]){
            k -= a[i];
        }else {
            pos = i;
            break;
        }
    }
    int rem = k;
    string ans;
    for(auto c : s){
        int cur = c - 'a';
        if(cur > pos || (cur == pos && rem == 0)){
            ans += c;
        }else if(cur == pos){
            rem--;
        }
    }
    cout << ans << endl;
}