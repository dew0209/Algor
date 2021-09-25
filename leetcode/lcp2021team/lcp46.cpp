/*
 * 志愿者调配
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<long long,long long> PII;
typedef long long LL;

const int N = 100010;

int n,m;
PII tol[N];
int h[N],ne[N],e[N],idx;//建图

class Solution {

public:
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
        //设最终0号馆的人数为x,倒推，每个馆的人数初始状态都是 person = kx + b的形式
        tol[0] = {1,0};//0号馆最终的人数为x
        for(int i = 0;i < finalCnt.size();i++){
            tol[i + 1] = {0,finalCnt[i]};
        }

        //建图
        idx = 0;
        memset(h,-1,sizeof h);
        build(edges);

        //倒推
        for(int i = plans.size() - 1;i >= 0;i--){
            int num = plans[i][0];
            int id = plans[i][1];
            PII& to = tol[id];
            if(num == 1){
                to.first *= 2;
                to.second *= 2;
            }else if(num == 2){
                for(int j = h[id];~j;j = ne[j]){
                    int t = e[j];
                    tol[t].first -= to.first;
                    tol[t].second -= to.second;
                }
            }else {
                for(int j = h[id];~j;j = ne[j]){
                    int t = e[j];
                    tol[t].first += to.first;
                    tol[t].second += to.second;
                }
            }

        }
        //计算结果
        LL a = 0,b = 0;
        for(int i = 0;i <= finalCnt.size();i++){
            a += tol[i].first;
            b += tol[i].second;
        }
        vector<int> res;
        LL x = (totalNum - b ) / a;
        for(int ii = 0;ii <= finalCnt.size();ii++){
            res.push_back(x * tol[ii].first + tol[ii].second);
        }
        return res;
    }
    void build(vector<vector<int>>& edges){
        for(int i = 0;i < edges.size();i++){
            add(edges[i][0],edges[i][1]);
            add(edges[i][1],edges[i][0]);
        }
    }
    void add(int a,int b){
        e[idx] = b,ne[idx] = h[a],h[a] = idx++;
    }
};