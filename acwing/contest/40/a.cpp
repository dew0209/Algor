#include <iostream>

using namespace std;

const int N = 100010;

int n;
char res[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)res[i] = 'o';
    int a = 1;
    int b = 1;
    while(b <= n){
        res[a] = 'O';
        res[b] = 'O';
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    for(int i = 1;i <= n;i++){
        cout << res[i];
    }
    cout << endl;
    return 0;
}