//https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/description/?envType=daily-question&envId=2026-02-25

class Solution {
public:
    int lowbit(int u){
        int res = 0;
        for (int i = u; i; i -= i & -i) res ++ ;
        return res;
    }
    void quick_sort(vector<int>& q,int l,int r){
        if(l >= r)return;
        int x = lowbit(q[l + r >> 1]);
        int i = l - 1,j = r + 1;
        while(i < j){
            do i++; while(lowbit(q[i]) < x);
            do j--; while(lowbit(q[j]) > x);
            if(i < j)swap(q[i],q[j]);
        }
        quick_sort(q,l,j);
        quick_sort(q,j + 1,r);
    }

    void quick_sort_A(vector<int>& q,int l,int r){
        if(l >= r)return;
        int x = q[l + r >> 1];
        int i = l - 1,j = r + 1;
        while(i < j){
            do i++; while(q[i] < x);
            do j--; while(q[j] > x);
            if(i < j)swap(q[i],q[j]);
        }
        quick_sort_A(q,l,j);
        quick_sort_A(q,j + 1,r);
    }

    vector<int> sortByBits(vector<int>& arr) {
        quick_sort(arr,0,arr.size() - 1);

        //调整局部
        for(int i = 0;i < arr.size();i++){
            int j = i;
            while(j < arr.size() && lowbit(arr[j]) == lowbit(arr[i])){
                j++;
            }
            quick_sort_A(arr,i,j - 1);
            i = j - 1;
        }

        return arr;
    }
};