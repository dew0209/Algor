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
    int n,sy,sx,ey,ex;
    string s;
    cin >> n >> sx >> sy >> ex >> ey;
    cin >> s;
    for(int i = 0;i < n;i++){
        if(s[i] == 'N' && sy < ey)sy++;
        else if(s[i] == 'S' && sy > ey)sy--;
        else if(s[i] == 'E' && sx < ex)sx++;
        else if(s[i] == 'W' && sx > ex)sx--;
        if(sx == ex && sy == ey){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}