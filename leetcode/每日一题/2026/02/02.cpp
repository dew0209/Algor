//https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/?envType=daily-question&envId=2026-02-02


class Solution {
public:

    void adjust(int k){
        while(s1.size() < k && s2.size() > 0){
            int x = *(s2.begin());
            s1.emplace(x);
            sum1 += x;
            s2.erase(s2.begin());
        }

        while(s1.size() > k){
            int x = *prev(s1.end());
            s2.emplace(x);
            sum1 -= x;
            s1.erase(prev(s1.end()));
        }

    }

    void addOne(int x,int k){
        
        if(!s2.empty() && x >= *(s2.begin())){
            s2.emplace(x);
        }else {
            s1.emplace(x);
            sum1 += x;
        }
        adjust(k);
    }

    void init(vector<int>& nums,int k){
        sum1 = 0;
        for(int i = 1;i < k - 1;i++){
            addOne(nums[i],k - 2);
        }
    }

    void eraseOne(int x,int k){
        auto it = s1.find(x);
        if(it != s1.end()){
            s1.erase(it);
            sum1 -= x;
        }else {
            s2.erase(s2.find(x));
        }
        adjust(k);
    }


    multiset<int> s1,s2;
    long long sum1;
    long long sum = 0;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        init(nums,k);
        cout << sum1 << endl;
        int n = nums.size();
        long long res = sum1 + nums[k - 1];
        for(int i = k;i < n;i++){
            int j = i - dist - 1;
            if(j > 0){
                eraseOne(nums[j],k - 2);
            }
            addOne(nums[i - 1],k - 2);
            res = min(res,sum1 + nums[i]);
        }
        return res + nums[0];
    }
};