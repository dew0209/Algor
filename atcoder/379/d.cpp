#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

int n;

const int N = 200010;

int main(){
    cin >> n;
    queue<int> q;
    vector<LL> height(n + 1);
    height[0] = 0;
    int t;
    for(int i = 0;i < n;i++){
        cin >> t;

        if(t == 1){
            height[i + 1] = height[i];
            q.push(i);
        }

        if(t == 2){
            int add;cin >> add;
            height[i + 1] = height[i] + add; 
        }

        if(t == 3){
            LL h;cin >> h;
            height[i + 1] = height[i];
            int res = 0;
            while(q.size()){
                if(height[i + 1] - height[q.front()] >= h){
                    res++;
                    q.pop();
                }else {
                    break;
                }
            }
            cout << res << endl;
        }


    }

}