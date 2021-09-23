/*
 * 326. 3的幂 [https://leetcode-cn.com/problems/power-of-three/]
 * 一直 % 3 == 0 n /= 3 即可
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
#include <set>

using namespace std;

#define fi first
#define se second

typedef long long LL;
typedef pair<int,int> PII;

const int N = 110;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n && n % 3 == 0)n /= 3;
        return n == 1;
    }
};