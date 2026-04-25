//https://leetcode.cn/problems/maximize-the-distance-between-points-on-a-square/?envType=daily-question&envId=2026-04-25

class Solution {
public:
    bool check(vector<long long>& nums,long long x,int side,int k){
        //a ......... b
        //a - (b - 4 * side) >= x
        // a - b + 4 * side >= x
        // b <= a - x + 4 * side
        for(auto st : nums){
            int a = st;
            long long b = a - x + 4LL * side;
            long long cur = a;
            for(int i = 0;i < k - 1;i++){
                auto it = lower_bound(nums.begin(),nums.end(),cur + x);
                if(it == nums.end() || *it > b){
                    cur = -1;
                    break;
                }
                cur = *it;
            }
            if(cur >= 0){
                return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> nums;
        for(auto& point : points){
            int x = point[0],y = point[1];
            if(x == 0){
                nums.push_back(y);
            }else if(y == side){
                nums.push_back(1LL * side + x);
            }else if(x == side){
                nums.push_back(3LL * side - y);
            }else if(y == 0){
                nums.push_back(4LL * side - x);
            }
        }
        sort(nums.begin(),nums.end());

        long long l = 1,r = side;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(nums,mid,side,k)){
                l = mid;
            }else {
                r = mid - 1;
            }
        }
        return l;
    }
};