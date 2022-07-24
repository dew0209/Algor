#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int n;
map<string,int> cnt;

int get_v(string a,string b){
    if(!cnt.count(a) || !cnt.count(b))return INT_MAX;
    return cnt[a] + cnt[b];
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        int price;cin >> price;
        string s;cin >> s;
        sort(s.begin(),s.end());
        if(cnt.count(s) == 0){
            cnt[s] = price;
        }else cnt[s] = min(cnt[s],price);
    }
    int ans = INT_MAX;
    if(cnt.count("A") && cnt.count("B") && cnt.count("C")){
        ans = min(ans,cnt["A"] + cnt["B"] + cnt["C"]);
        //cout << ans << "dedee" << endl;
    }
    if(cnt.count("ABC")){
        ans = min(ans,cnt["ABC"]);
    }
    ans = min(ans,get_v("A","BC"));
    ans = min(ans,get_v("AB","C"));
    ans = min(ans,get_v("AB","BC"));
    ans = min(ans,get_v("AC","BC"));
    ans = min(ans,get_v("AC","B"));
    ans = min(ans,get_v("AC","AB"));
    if(ans == INT_MAX)ans = -1;
    cout << ans << endl;
}