#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

int mod2[6] = {0,2,4,3,1,2};
int mod3[6] = {0,3,4,2,1,3};
int mod4[6] = {0,4,1,4,1,4};

int main(){
    string s;
    cin >> s;
    vector<int> cnt;
    vector<int> res;
    //模拟除法，除法是从最高位开始搞的
    for(int i = 0;i < s.length();i++){
        cnt.push_back(s[i] - '0');
    }
    int r = 0;// r 是余数
    for(int i = 0;i < s.length();i++){
        r = r * 10 + cnt[i];
        //cout << s[i] << "debug" << r << endl;
        res.push_back(r / 4);
        //cout << r << endl;
        r %= 4;
        //cout << r << endl;
    }
    //r is the end r < 5
    //cout << r << endl;
    int ans = 1;
    ans += pow(2,r);    
    ans += pow(3,r);
    ans += pow(4,r);
    
    cout << ans % 5 << endl;
    return 0;
}