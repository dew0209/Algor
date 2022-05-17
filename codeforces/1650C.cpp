#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 200010;


struct point{
    int weigth,position,id;
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<point> points(m);
    for(int i = 0;i < m;i++){
        cin >> points[i].position >> points[i].weigth;
        points[i].id = i + 1;
    }
    sort(points.begin(),points.end(),[](point a,point b){
        return a.weigth < b.weigth;
    });
    int sum = 0;
    for(int i = 0;i < m;i++){
        if(i < 2 * n)sum += points[i].weigth;
        else points.pop_back();
    }
    sort(points.begin(),points.end(),[](point a,point b){
        return a.position < b.position;
    });
    cout << sum << endl;
    for(int i = 0;i < n;i++){
        cout << points[i].id << ' ' << points[2 * n - i - 1].id << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}