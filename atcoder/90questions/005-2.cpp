#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

const int M = 33,mod = 1e9 + 7;


struct Matrix{
    int sz;
    LL x[M][M];
};

Matrix multiply(Matrix A,Matrix B){
    Matrix C;
    C.sz = A.sz;
    //answer
    for(int i = 0;i < C.sz;i++){
        for(int j = 0;j < C.sz;j++)C.x[i][j] = 0;
    }
    for(int i = 0;i < A.sz;i++){
        for(int j = 0;j < A.sz;j++){
            for(int k = 0;k < A.sz;k++){
                C.x[i][k] += A.x[i][j] * B.x[j][k];
                C.x[i][k] %= mod;
            }
        }
    }
    return C;
}

Matrix powers(Matrix A,LL T) {
    Matrix E[64], F;
    E[0] = A;
    //A1  A2  A4  A  A16  ...
    for (int i = 1; i < 62; i++) {
        E[i] = multiply(E[i - 1], E[i - 1]);
    }
    F.sz = E[0].sz;

    for (int i = 0; i < F.sz; i++) {
        for (int j = 0; j < F.sz; j++) {
            F.x[i][j] = 0;
        }
    }
    F.x[0][0] = 1;




    for (int i = 62; i >= 0; i--) {
        if ((T & (1LL << i)) != 0LL) {
            F = multiply(F, E[i]);
        }
    }

    return F;
}


LL N,B,K;
LL c[11];

int main(){
    cin >> N >> B >> K;
    for(int i = 1;i <= K;i++)cin >> c[i];
    Matrix A;
    A.sz = B;
    for(int i = 0;i < B;i++){
        for(int j = 0;j < B;j++)A.x[i][j] = 0;
    }
    //di tui
    for(int i = 0;i < B;i++){
        for(int j = 1;j <= K;j++){
            int nex = (i * 10 + c[j]) % B;
            A.x[i][nex] += 1;
        }
    }

    Matrix Z = powers(A,N);

    LL answer = Z.x[0][0];


    cout << answer << endl;

    return 0;
}