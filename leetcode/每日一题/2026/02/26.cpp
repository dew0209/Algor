//https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26

class Solution {
public:
    void turn(deque<int>& q){
        int n = q.size();
        int x = q[n - 1];
        if(x == 0){
            q.pop_back();
        }else{
            int t = 1;
            for (int i = n - 1; i >= 0; i--) {
                t += q[i];
                q[i] = (t % 2);
                t /= 2;
            }
            if(t){
                q.push_front(t);
            }
        }
    }
    int numSteps(string s) {
        //拆成vector
        int n = s.size();
        deque<int> q;
        for(int i = 0;i < n;i++){
            q.push_back(s[i] - '0');
        }
        int res = 0;
        cout << q.size() << endl;
        while(q.size() != 1 || q[0] != 1){
            turn(q);
            res++;
        }
        return res;
    }
};