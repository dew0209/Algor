//https://leetcode.cn/problems/type-of-triangle/?envType=daily-question&envId=2025-05-19

class Solution {
public:
    string triangleType(vector<int>& nums) {
        string res = "none";

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if(a - b < c && b - c < a && a - c < b && a + b > c && a + c > b && b + c > a){
            
            if(a == b && b == c){
                res = "equilateral";
            }else if( a == b || a == c || b == c){
                res = "isosceles";
            }else {
                res = "scalene";
            }

        }
        return res;
    }
};