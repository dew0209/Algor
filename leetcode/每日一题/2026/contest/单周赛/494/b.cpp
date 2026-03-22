class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool ok1 = true;
        bool ok2 = true;
        //分类讨论
        //构建偶数结果集
        
        //存储偶数
        vector<int> a;
        //存储奇数
        vector<int> b;

        
        for(int i = 0;i < n;i++){
            if(nums1[i] % 2 == 0){
                a.push_back(nums1[i]);
            }else {
                b.push_back(nums1[i]);
            }
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        //构建偶数
        for(int i = 0;i < n;i++){
            if(nums1[i] % 2 == 0){
                
            }else {
                //在b里面找到小于当前数的数
                //奇数 - 奇数 = 偶数
                int fl = b.size() != 0 && b[0] != nums1[i];
                if(!fl){
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
                int fl = b.size() != 0 && b[0] < nums1[i];
                if(!fl){
                    ok2 = false;
                    break;
                }
                
            }
        }
        return ok1 || ok2;

        
        
    }
};