#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

int arr[] = {31,28,31,30,31,30,31,31,30,31,30,31,
            31,28,31,30,31,30,31,31,30,31,30,31,
            31,29,31,30,31,30,31,31,30,31,30,31,
            31,28,31,30,31,30,31,31,30,31,30,31,
            31,28,31,30,31,30,31,31,30,31,30,31,
};

int main(){
    int n;cin >> n;
    vector<int> res;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        res.push_back(c);
    }
    for(int i = 0;i < 60;i++){
        if(arr[i] == res[0]){
            bool ok = 1;
            for(int j = 0,k = i;j < res.size();j++,k++){
                if(res[j] != arr[k]){
                    ok = 0;
                }
            }
        
            if(ok){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}