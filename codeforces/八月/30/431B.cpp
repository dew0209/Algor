#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;
LL stu[6];
LL q[10][10];
LL resCnt[6];

int main(){
    int n = 5;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> q[i][j];
        }
    }
    for(int i = 0;i < 5;i++)stu[i] = i;
    LL tmp = 0,res = 0;
    do{
        tmp += q[stu[0]][stu[1]] + q[stu[1]][stu[0]];
        tmp += q[stu[2]][stu[3]] + q[stu[3]][stu[2]];
        
        tmp += q[stu[1]][stu[2]] + q[stu[2]][stu[1]];
        tmp += q[stu[3]][stu[4]] + q[stu[4]][stu[3]];

        tmp += q[stu[2]][stu[3]] + q[stu[3]][stu[2]];

        tmp += q[stu[3]][stu[4]] + q[stu[4]][stu[3]];


        res = max(res,tmp);
        tmp = 0;

    }while(next_permutation(stu,stu + n));
    cout << res << endl;
}