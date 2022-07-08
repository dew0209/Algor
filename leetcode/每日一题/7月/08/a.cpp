#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a = 0;
        int b = 0;
        for(auto &c : position){
            if(c % 2){
                a++;
            } else {
                b++;
            }
        }
        return min(a,b);
    }
};