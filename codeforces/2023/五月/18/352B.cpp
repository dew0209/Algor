#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 100010;


int n;
vector<PII> ans;
vector<PII> res;

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int c;scanf("%d",&c);
        ans.push_back({c,i});
    }
    sort(ans.begin(),ans.end());

    for(int i = 0;i < n;i++){
        //cout << ans[i].first << " --- " << ans[i].second << endl;
        int j = i + 1;
        int d = 0;
        int ok = 1;
        while(j < n && ans[j].first == ans[i].first){
            int diff = ans[j].second - ans[j - 1].second;
            if(d == 0)d = diff;
            if(diff != d){
                ok = 0;
            }
            j++;
        }
        if(ok){
            res.push_back({ans[i].first,d});
        }
        i = j - 1;
    }
    printf("%d\n",res.size());
    for(int i = 0;i < res.size();i++){
        printf("%d %d\n",res[i].first,res[i].second);
    }
}