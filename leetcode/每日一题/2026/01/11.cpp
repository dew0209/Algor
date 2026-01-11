//https://leetcode.cn/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11


class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1);
        stack<int> st;
        for(int i = 0;i < n;i++){
            int h = heights[i];
            while(!st.empty() && heights[st.top()] >= h){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }
        vector<int> right(n,n);
        st = stack<int>();
        for(int i = n - 1;i >= 0;i--){
            int h = heights[i];
            while(!st.empty() && heights[st.top()] >= h){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans = max(ans,heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m,0);

        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }else {
                    heights[j] = 0;
                }
            }
            res = max(res,largestRectangleArea(heights));
        }
        return res;
    }

};