//bfs

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define fi first
#define se second

const int N = 1010;

char g[2][4];
unordered_map<string,int> dist;
unordered_map<string,pair<char,string>> pre;

void set(string s){
    for(int i = 0;i < 4;i++)g[0][i] = s[i];
    for(int i = 4,j = 3;j >= 0;j--,i++)g[1][j] = s[i];
}

string get(){
    
    string s;
    
    for(int i = 0;i < 4;i++){
        s += g[0][i];
    }
    
    for(int i = 3;i >= 0;i--){
        s += g[1][i];
    }
    
    return s;
}

string move0(string s){
    set(s);
    for(int i = 0;i < 4;i++){
        swap(g[0][i],g[1][i]);
    }
    return get();
}

string move1(string s){
    
    set(s);
    char a = g[0][3];
    char b = g[1][3];
    for(int i = 3;i > 0;i--){
        g[0][i] = g[0][i - 1];
        g[1][i] = g[1][i - 1];
    }
    g[0][0] = a;
    g[1][0] = b;
    return get();
}

string move2(string s){
    set(s);
    char a = g[0][1];
    char b = g[0][2];
    char c = g[1][2];
    char d = g[1][1];
    g[0][1] = d;
    g[0][2] = a;
    g[1][2] = b;
    g[1][1] = c;
    return get();
}

int bfs(string start,string end){
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(s == end)return dist[s];
        string m[3];
        m[0] = move0(s);

        m[1] = move1(s);

        m[2] = move2(s);


        for(int i = 0;i < 3;i++){
            if(!dist.count(m[i])){
                dist[m[i]] = dist[s] + 1;
                pre[m[i]] = {'A' + i,s};
                q.push(m[i]);
                if(m[i] == end)return dist[end];
            }
        }
    }
    return -1;
}

int main(){
    string start,end;
    for(int i = 0;i < 8;i++){
        int x;cin >> x;
        end += (x + '0');
    }
    for(int i = 1;i <= 8;i++){
        start += (i + '0');
    }
    int step = bfs(start,end);
    cout << step << endl;
    string res;
    
    while(start != end){
        
        res += pre[end].fi;
        end = pre[end].se;
        
    }
    
    reverse(res.begin(),res.end());
    if(step)cout << res << endl;
    return 0;
}