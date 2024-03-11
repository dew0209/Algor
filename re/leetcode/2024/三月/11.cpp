题目链接：https://leetcode.cn/problems/capitalize-the-title/description/?envType=daily-question&envId=2024-03-11

思路：双指针

class Solution {
public:
    string capitalizeTitle(string title) {
       int n = title.size();
       string res = "";
       for(int i = 0;i < n;i++){
           int j = i;
           while(j < n && title[j] != ' ')j++;
           int k = i;
           while(k < j){
               title[k++] = tolower(title[k]);
           }
           if(j - i > 2){
                title[i] = toupper(title[i]);
           }
           i = j;
       } 
       return title;
    }
};