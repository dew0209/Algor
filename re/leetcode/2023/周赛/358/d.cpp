题目链接：https://leetcode.cn/problems/apply-operations-to-maximize-score/

方法一：单调栈

思考：一个数x，这个数如果是最大的，对结果能够贡献几次？

....  x .....
 a个      b个
答案应该是 (a + 1) * (b + 1)个
左边：都是小于x的数
右边：都是小于等于x的数。这里的比较是指质数分数
所以我们要找到左边第一个大于等于x的数，右边第一个大于x的数   (右边为什么没有等号？因为相等的情况下，取下标最小的，那么还是x)
设区间为 l   idx(指x的下标)   r
那么左边：idx - l + 1 - 2(l和idx的数都不能用) + 1(左边不选) = idx - l
右边：r - idx + 1 - 2 + 1 = r - idx
那么对答案的贡献值就是：(idx - l) * (r - idx)


const int N = 100010,MOD = 1e9 + 7;

typedef long long LL;

int q[N];
int top;
int cnt[N];

class Solution {
public:
    //埃氏筛法
    void init(){
        for(int i = 2;i < N;i++){
            if(cnt[i] == 0){
                for(int j = i;j < N;j += i){
                    cnt[j]++;
                }
            }
        }
    }
    //快速幂
    LL qmi(LL a,LL b,LL mod){
        LL res = 1 % MOD;
        while(b){
            if(b & 1)res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        init();
        int n = nums.size();
        vector<int> l(n,-1);
        vector<int> r(n,n);
        top = 0;
        for(int i = 0;i < n;i++){
            //左边找第一个大于等于nums[i]的数
            while(top > 0 && cnt[nums[q[top]]] < cnt[nums[i]])top--;
            if(top > 0)l[i] = q[top];
            q[++top] = i;
        }
        top = 0;
        for(int i = n - 1;i >= 0;i--){
            //右边找第一个大于nums[i]的数
            while(top > 0 && cnt[nums[q[top]]] <= cnt[nums[i]])top--;
            if(top > 0)r[i] = q[top];
            q[++top] = i;
        }
        vector<int> id(n,0);
        //初始化0,1,2,3,.....,n - 1
        iota(id.begin(),id.end(),0);
        //我们每次选数，一定要从最大的数（这里最大的指的就是数的大小，不是指质数分数最大的数）
        sort(id.begin(),id.end(),[&](const int i,const int j){
            return nums[i] > nums[j];
        });
        int res = 1;
        for(int i : id){
            LL tol = (i - l[i]) * (r[i] - i);
            LL sum = min(tol,(LL)k);
            res = res * qmi(nums[i],sum,MOD) % MOD;
            k -= sum;
            if(k <= 0)break;
        }
        return res;
    }
};