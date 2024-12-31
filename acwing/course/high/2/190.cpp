//bfs

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;


const int N = 1010;

int n;

string a[N],b[N];


int extend(queue<string>& q,unordered_map<string,int>& da,unordered_map<string,int>& db,string a[],string b[]){
    
    for(int k = 0,sk = q.size();k < sk;k++){
        
        auto t = q.front();
        q.pop();
        
        for(int i = 0;i < t.size();i++){
            
            for(int j = 0;j < n;j++){
                
                if(t.substr(i,a[j].size()) == a[j]){
                    
                    string state = t.substr(0,i) + b[j] + t.substr(i + a[j].size());
                    
                    if(da.count(state))continue;
                    if(db.count(state))return da[t] + 1 + db[state];
                    da[state] = da[t] + 1;
                    q.push(state);
                }
            }
        }
    }
    return 11;
}

int bfs(string A,string B){
    
    if(A == B)return 0;
    
    queue<string> qa,qb;
    unordered_map<string,int> da,db;
    
    qa.push(A),da[A] = 0;
    qb.push(B),db[B] = 0;
    
    while(qa.size() && qb.size()){
        int t = 0;
        if(qa.size() < qb.size()){
            t = extend(qa,da,db,a,b);
        }else {
            t = extend(qb,db,da,b,a);
        }
        if(t <= 10)return t;
    }
    return 11;
}

int main(){
    n = 0;
    string A,B;
    cin >> A >> B;
    
    while(cin >> a[n] >> b[n])n++;
    
    int step = bfs(A,B);
    
    if(step > 10)cout << "NO ANSWER!" << endl;
    else cout << step << endl;
    return 0;
}