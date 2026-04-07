//https://leetcode.cn/problems/walking-robot-simulation-ii/description/?envType=daily-question&envId=2026-04-07

class Robot {
public:
    int n;
    int m;
    int id = 0;
    int stepNum = 0;

    vector<int> getRes(){
        vector<int> res(3,0);
        if(id <= n - 1){
            res[0] = id;
            res[1] = 0;
            res[2] = 0;
        }else if(id <= n + m - 2){
            res[0] = n - 1;
            res[1] = id - (n - 1);
            res[2] = 1;
        }else if(id <= 2 * n + m - 3){
            res[0] = 2 * n + m - 3 - id;
            res[1] = m - 1;
            res[2] = 2;
        }else {
            res[0] = 0;
            res[1] = 2 * (n + m - 2) - id;
            res[2] = 3;
        }
        return res;
    }

    Robot(int width, int height) {
        n = width;
        m = height;
    }
    
    void step(int num) {
        id = (id + num) % (2 * (n + m - 2));
        stepNum += num;
    }
    
    vector<int> getPos() {
        vector<int> ans = getRes();
        vector<int> res(2,0);
        res[0] = ans[0];
        res[1] = ans[1];
        return res;
    }
    
    string getDir() {
        int fx = getRes()[2];
        if(fx == 0){
            if(id == 0 && stepNum){
                return "South";
            }
            return "East";
        }else if(fx == 1){
            return "North";
        }else if(fx == 2){
            return "West";
        }else if(fx == 3){
            return "South";
        }
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */