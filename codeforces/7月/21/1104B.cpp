#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n;
int main(){
    string s;cin >> s;
    vector<char> cnt;
    int ans = 0;
    for(int i = 0;i < s.size();i++){
        if(i == 0){
            cnt.push_back(s[i]);
        }else {
            if(s[i] == cnt.back()){
                ans++;
                cnt.pop_back();
            }else {
                cnt.push_back(s[i]);
            }
        }
    }
    if(ans % 2 == 0){
        cout << "No" << endl;
    }else {
        cout << "Yes" << endl;
    }
}