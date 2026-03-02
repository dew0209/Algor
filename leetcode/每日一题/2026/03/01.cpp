//https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers/?envType=daily-question&envId=2026-03-01

class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for(char c : n) {
            res = max(res, c - '0');
        }
        return res;
    }
};