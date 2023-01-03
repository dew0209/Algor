#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


typedef long long LL;

using namespace std;

const int N = 10010;

int n,m;
int cnt[N][3];//统计：cnt[i][0]：女孩的数量，披萨，打车
vector<string> q(N);

int check(string s){
    int a = (s[0] - '0');
    int b = (s[1] - '0');
    int c = (s[3] - '0');
    int d = (s[4] - '0');
    int e = (s[6] - '0');
    int f = (s[7] - '0');
    if(a == b && b == c && c == d && d == e && e == f)return 2;
    if(a > b && b > c && c > d && d > e && e > f)return 1;
    return 0;
}

int main(){
    cin >> n;
    int ma = 0,mb = 0,mc = 0;
    for(int i = 0;i < n;i++){
        cin >> m;
        cin >> q[i];//name
        while(m--){
            string s;cin >> s;
            int ok = check(s);
            cnt[i][ok]++;
        }
        ma = max(cnt[i][0],ma);
        mb = max(cnt[i][1],mb);
        mc = max(cnt[i][2],mc);
    }
    //cout << ma << " " << mb << " " << mc << endl;
    vector<vector<string>> ans(3);
    for(int i = 0;i < n;i++){
        if(cnt[i][0] == ma){
            ans[0].push_back(q[i]);
        }
        if(cnt[i][1] == mb){
            ans[1].push_back(q[i]);
        }
        if(cnt[i][2] == mc){
            ans[2].push_back(q[i]);
        }
    }
    string ra = "If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i = 0;i < ans[0].size();i++){
        ra += ans[0][i];
        if(i != ans[0].size() - 1){
            ra += ", ";
        }else ra += ".";
    }
    string rb = "If you want to order a pizza, you should call: ";
    for(int i = 0;i < ans[1].size();i++){
        rb += ans[1][i];
        if(i != ans[1].size() - 1){
            rb += ", ";
        }else rb += ".";
    }
    string rc = "If you want to call a taxi, you should call: ";
    for(int i = 0;i < ans[2].size();i++){
        rc += ans[2][i];
        if(i != ans[2].size() - 1){
            rc += ", ";
        }else rc += ".";
    }
    cout << rc << endl << rb << endl << ra << endl;

    return 0;
}