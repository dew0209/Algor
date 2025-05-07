//https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-i/description/?envType=daily-question&envId=2025-05-07

#define x first
#define y second

typedef pair<int,int> PII;
const int N = 150010 * 2,INF = 0x3f3f3f3f;



class Solution {
public:
    int n,m;
    int h[N],e[N],ne[N],w[N],idx;
    int d[N];
    int price[N];
    bool st[N];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void add(int a,int b,int c){
        e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
    }

    int dijkstr(){
        memset(d,0x3f,sizeof d);
        d[0] = 0;
        priority_queue<PII,vector<PII>,greater<PII>> q;
        q.push({d[0],0});
        while(q.size()){
            auto t = q.top();
            q.pop();
            int u = t.y,distance = t.x;
            if(st[u])continue;
            st[u] = true;
            for(int i = h[u];~i;i = ne[i]){
                int j = e[i];
                int val = max(distance,price[j]);
                if(d[j] > val + w[i]){
                    d[j] = val + w[i];
                    q.push({d[j],j});
                }
            }
        }
        if(d[n] == INF)return -1;
        return d[n];
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        m = 0;
        memset(h,-1,sizeof h);
        memset(d,0x3f,sizeof d);
        memset(st,0,sizeof st);

        int lenn = moveTime.size();
        int lenm = moveTime[0].size();

        for(int i = 0;i < lenn;i++){
            for(int j = 0;j < lenm;j++){
                int a = lenm * i + j;
                price[a] = moveTime[i][j];
                for(int t = 0;t < 4;t++){
                    int ax = dx[t] + i;
                    int ay = dy[t] + j;
                    if(ax < 0 || ax >= lenn || ay < 0 || ay >= lenm)continue;
                    m++;
                    int b = ax * lenm + ay;
                    //cout << "加边：" << b << " --> " << a << endl;
                    add(b,a,1);
                }

            }
        }
        n = lenm * (lenn - 1) + lenm - 1;
        //cout << "n为：" << n << endl;
        return dijkstr();
    }
};