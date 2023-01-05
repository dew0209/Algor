#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

typedef long long LL;

using namespace std;

int main(){
    string s,a,b;cin >> s >> a >> b;
    int ia = s.find(a);
    int ib = s.find(b,ia + a.size());
    reverse(s.begin(),s.end());
    int ja = s.find(a);
    int jb = s.find(b,ja + a.size());
    int st1 = 0;
    int st2 = 0;
    if(ia < ib && ia != -1 && ib != -1){
        st1 = 1;
    }
    if(ja < jb && ja != -1 && jb != -1){
        st2 = 1;
    }
    if(st1 && st2){
        cout << "both" << endl;
    }else if(st1){
        cout << "forward" << endl;
    }else if(st2){
        cout << "backward" << endl;
    }else {
        cout << "fantasy" << endl;
    }
    return 0;
}