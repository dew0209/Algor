class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool ok1 = true;
        bool ok2 = true;
        //分类讨论
        //构建偶数结果集
        int a = 0;
        int b = 0;
        for(int i = 0;i < n;i++){
            if(nums1[i] % 2 == 0){
                a++;
            }else {
                b++;
            }
        }
        //构建偶数
        for(int i = 0;i < n;i++){
            if(nums1[i] % 2 == 0){
                
            }else {
                //奇数 - 奇数 = 偶数
                if(b - 1 <= 0){
                    ok1 = false;
                    break;
                }
                
            }
        }
        //构建奇数
        for(int i = 0;i < n;i++){
            if(nums1[i] % 2 == 1){
                
            }else {
                //奇数 - 偶数 = 奇数
                if(b <= 0){
                    ok2 = false;
                    break;
                }
                
            }
        }
        return ok1 || ok2;
    }
};