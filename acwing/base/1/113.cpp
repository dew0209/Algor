// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int n) {
        vector<int> res;
        res.push_back(1);
        for(int i = 2;i <= n;i++){
            int l = 0,r = res.size() - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(compare(res[mid],i))l = mid;
                else r = mid - 1;
            }
            //cout << l << endl;
            res.push_back(i);
            for(int j = res.size() - 2;j > r;j--)swap(res[j],res[j + 1]);
            if(!compare(res[r],i))swap(res[r],res[r + 1]);
        }
        return res;
    }
};

作者：一只可爱严
        链接：https://www.acwing.com/activity/content/code/content/1853371/
来源：AcWing
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。