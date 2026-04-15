//https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15


class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if(words[startIndex] == target){
            return 0;
        }
        int step1 = 0;
        for(int i = (startIndex - 1 + n) % n;i != startIndex;i = (i - 1 + n) % n){
            step1++;
            if(words[i] == target){
                break;
            }
        }
        int step2 = 0;
        for(int i = (startIndex + 1) % n;i != startIndex;i = (i + 1) % n){
            step2++;
            if(words[i] == target){
                break;
            }
        }
        int res = min(step1,step2);
        if(res == n - 1){
            res = -1;
        }
        return res;
    }
};