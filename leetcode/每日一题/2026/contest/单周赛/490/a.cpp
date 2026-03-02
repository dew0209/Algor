class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int aFlag = 1;
        int bFlag = 0;

        for(int i = 0;i < nums.size();i++){
            int id = i + 1;
            int x = nums[i];

            if(x % 2){
                aFlag = !aFlag;
                bFlag = !bFlag;
            }

            if(id % 6 == 0){
                aFlag = !aFlag;
                bFlag = !bFlag;
            }
            if(aFlag){
                a += x;
            }
            if(bFlag){
                b += x;
            }
            
        }
        return a - b;
    }
};