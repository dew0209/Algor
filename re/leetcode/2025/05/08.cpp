//https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-ii/description/?envType=daily-question&envId=2025-05-08


#define x first
#define y second

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 750 * 750,M = N * 4,INF = 0x3f3f3f3f;

class Solution {
public:
    int n,m;
    int h[N],e[M],ne[M],w[M],idx;
    int d[N];
    int price[N];
    bool st[N];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void add(int a,int b,int c){
        e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
    }

    int dijkstr(){
        d[0] = 0;
        priority_queue<PIII,vector<PIII>,greater<PIII>> q;
        q.push({d[0],{0,0}});
        while(q.size()){
            auto t = q.top();
            q.pop();
            int u = t.y.x,distance = t.x;
            int spendStep = t.y.y;
            if(u == n)return d[n];
            if(st[u])continue;
            st[u] = true;
            for(int i = h[u];~i;i = ne[i]){
                int j = e[i];
                int val = max(distance,price[j]);
                int mul2 = (!spendStep || spendStep % 2 == 0) ? w[i] : (w[i] * 2);
                if(d[j] > val + mul2){
                    d[j] = val + mul2;
                    q.push({d[j],{j,spendStep + 1}});
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
                    add(b,a,1);
                }

            }
        }
        n = lenm * (lenn - 1) + lenm - 1;
        return dijkstr();
    }
};