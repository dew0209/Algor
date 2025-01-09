//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int n,m;
bool g[N][N];
bool st[N];

char get_min(){
    
    for(int i = 0;i < n;i++){
        if(!st[i]){
            bool fa = true;
            for(int j = 0;j < n;j++){
                
                if(!st[j] && g[j][i]){
                    fa = false;
                    break;
                }
                
            }
            
            if(fa){
                st[i] = true;
                return 'A' + i;
            }
            
        }
        
    }
    return 'A';
}

void floyd(){
    
    for(int k = 0;k < n;k++){
        
        for(int i = 0;i < n;i++){
            
            for(int j = 0;j < n;j++){
                
                g[i][j] |= g[i][k] & g[k][j];
            }
            
        }
        
    }
    
}

int check(){
    
    for(int i = 0;i < n;i++){
        
        if(g[i][i])return 2;
        
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(!g[i][j] && !g[j][i])return 0;
        }
    }
    return 1;
}

int main(){
    
    while(cin >> n >> m,n && m){
        memset(g,0,sizeof g);
        int type = 0;
        int t = 0;
        for(int i = 0;i < m;i++){
            char a,a1,b;
            cin >> a >> a1 >> b;
            int aid = a - 'A';
            int bid = b - 'A';
            if(!type){
                g[aid][bid] = true;
                floyd();
                type = check();
                if(type){
                    t = i + 1;
                }
            }
        }
        if(!type)cout << "Sorted sequence cannot be determined." << endl;
        else if(type == 2){
            printf("Inconsistency found after %d relations.\n",t);
        }else {
            
            memset(st,0,sizeof st);
            
            printf("Sorted sequence determined after %d relations: ",t);
            
            for(int i = 0;i < n;i++){
                cout << get_min();
            }
            cout << "." << endl;
        }
    }
    return 0;
}