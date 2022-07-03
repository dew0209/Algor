#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> ans;
        while(n){
            ans.push_back(n % 10);
            n /= 10;
        }
        n = ans.size();
        int i = 1;
        while(i < n && ans[i] >= ans[i - 1])i++;
        if(i >= n)return -1;
        int j = 0;
        while(j < n && ans[j] <= ans[i])j++;
        swap(ans[i],ans[j]);
        long long ret = 0;
        for(int st = n - 1;st >= i;st--)ret = ret * 10 + ans[st];
        for(int st = 0;st < i;st++)ret = ret * 10 + ans[st];
        if(ret > INT_MAX)return -1;
        return ret;
    }
};