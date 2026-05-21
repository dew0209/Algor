//https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2026-05-21

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;
        for(auto& x : arr1){
            while(x){
                st.insert(x);
                x /= 10;
            }
        }
        int mx = 0;
        for(auto& x : arr2){
            while(x && !st.contains(x)){
                x /= 10;
            }
            mx = max(mx,x);
        }
        return mx ? to_string(mx).size() : 0;
    }
};