//https://leetcode.cn/problems/walking-robot-simulation/?envType=daily-question&envId=2026-04-06


int dx[4] = {0,1,2,3};
class Solution {
public:
    int get_less(vector<int>& arr,int x){
        int l = 0,r = arr.size() - 1;

        while(l < r){
            int mid = l + r + 1 >> 1;
            if(arr[mid] >= x){
                r = mid - 1;
            }else {
                l = mid;
            }
        }
        return l;
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = obstacles.size();
        map<int,vector<int>> cntx;
        map<int,vector<int>> cnty;
        for(auto& obt : obstacles){
            cntx[obt[0]].push_back(obt[1]);
            cnty[obt[1]].push_back(obt[0]);
        }
        for(auto& [x,y] : cntx){
            sort(y.begin(),y.end());
        }
        for(auto& [x,y] : cnty){
            sort(y.begin(),y.end());
        }

        //deal
        int x = 0,y = 0;
        int res = 0;
        int fx = 0;
        for(auto& op : commands){
            if(op == -2){
                fx = (fx - 1 + 4) % 4; 
            }else if(op == -1){
                fx = (fx + 1) % 4;
            }else {
                //move
                
                //find x
                if(fx == 0 || fx == 2){
                    if(fx == 0){
                        if(cntx.contains(x)){
                            auto it = std::upper_bound(cntx[x].begin(), cntx[x].end(), y);
                            if(it != cntx[x].end()){
                                y = min(y + op,*it - 1);
                            }else {
                                y += op;
                            }
                        }else {
                            y += op;
                        }
                    }

                    if(fx == 2){
                        if(cntx.contains(x)){
                            int res = get_less(cntx[x],y);
                            //cout << x <<"down:" << res << endl;
                            if(res >= 0 && (res = cntx[x][res]) < y){
                                //cout << " in "  << y - op << res << endl;
                                y = max(y - op,res + 1);
                            }else {
                                y -= op;
                            }
                        }else {
                            y -= op;
                        }
                    }
                }else {
                    //find y
                    if(fx == 1){
                        if(cnty.contains(y)){
                            
                            auto it = std::upper_bound(cnty[y].begin(), cnty[y].end(), x);
                            if(it != cnty[y].end()){
                                x = min(x + op,*it - 1);
                            }else {
                                x += op;
                            }
                        }else {
                            x += op;
                        }
                    }

                    if(fx == 3){
                        if(cnty.contains(y)){
                            int res = get_less(cnty[y],x);
                            if(res >= 0 && (res = cnty[y][res]) < x){
                                x = max(x - op,res + 1);
                            }else {
                                x -= op;
                            }
                        }else {
                            x -= op;
                        }
                    }

                }

            }

            res = max(res,x * x + y * y);

        }
        return res;
    }
};