#include <iostream>
using namespace std;
//不会  没想明白
long long modpow(long long a, long long b, long long m) {
    long long p = 1, q = a;
    for (int i = 0; i < 63; i++) {
        if ((b & (1LL << i)) != 0) {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}

const long long mod = 1000000007;

long long N, B, K;
long long C[11];

long long power10[64];
long long DP[64][1009];
long long Answer[64][1009];

int main() {
    cin >> N >> B >> K;
    for (int i = 1; i <= K; i++) cin >> C[i];

    for (int i = 0; i <= 62; i++) {
        power10[i] = modpow(10LL, (1LL << i), B);
    }
    for (int i = 1; i <= K; i++) {
        DP[0][C[i] % B] += 1;
    }
    for (int i = 0; i < 62; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < B; k++) {
                //10^0 = 10  10^1 = 100
                int nex = (j * power10[i] + k) % B;
                DP[i + 1][nex] += DP[i][j] * DP[i][k];
                DP[i + 1][nex] %= mod;
            }
        }
    }
    Answer[0][0] = 1;
    for (int i = 0; i < 62; i++) {
        if ((N & (1LL << i)) != 0LL) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < B; k++) {
                    int nex = (j * power10[i] + k) % B;
                    Answer[i + 1][nex] += Answer[i][j] * DP[i][k];
                    Answer[i + 1][nex] %= mod;
                }
            }
        }
        else {
            for (int j = 0; j < B; j++) Answer[i + 1][j] = Answer[i][j];
        }
    }
    cout << Answer[62][0] << endl;
    return 0;
}