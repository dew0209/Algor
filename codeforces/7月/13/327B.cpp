#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n;

int main(){
    cin >> n;
    for(int i = 3 * N;i <= 3 * N + n - 1;i++){
        cout << i << ' ';
    }
}