const int N = 200010;
class Solution {
    int p[N];
    int count = 1;
    map<int,int> cnt; 
    int find(int x){
        if(x != p[x])p[x] = find(p[x]);
        return p[x];
    }

    int get(int u){
        if(cnt.contains(u)){
            return cnt[u];
        }
        cnt[u] = count++;
        return cnt[u];
    }


public:

    int maxActivated(vector<vector<int>>& points) {
        for(int i = 1;i < N;i++){
            p[i] = i;
        }
        count = 1;
        cnt.clear();

        long long OFFSET = 3e9;


        for(auto& point : points){
            int x = point[0];
            int y = point[1];
            x = find(get(x));
            y = find(get(y + OFFSET));
            if(x != y){
                p[x] = p[y];
            }
        }

        int mx1 = 0,mx2 = 0;
        map<int,int> Size;
        for(auto& point : points){
            int x = point[0];
            x = find(get(x));
            Size[x]++;
        }
        for(auto& [x,y] : Size){
            if(y > mx1){
                mx2 = mx1;
                mx1 = y;
            }else if(y > mx2){
                mx2 = y;
            }
        }
        
        return mx1 + mx2 + 1;
    }
};