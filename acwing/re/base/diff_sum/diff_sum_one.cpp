#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define fi first
#define se second
#define pk pop_back
#define pb push_back

typedef long long LL;

using namespace std;

const int N = 100010;

//二分
template <typename T> T binary_search_l(T q[],T l,T r,T target){while(l < r){int mid = l + r >> 1;if(q[mid] >= target)r = mid;else l = mid + 1;}return r;}
template <typename T> T binary_search_r(T q[],T l,T r,T target){while(l < r){int mid = l + r + 1 >> 1;if(q[mid] <= target)l = mid;else r = mid - 1;}return l;}
//lowbit
template <typename T> T lowbit(T n){T res = 0;for(T i = n;i;i -= i & (-i))res++;return res;}
//前缀和一维二维
template <typename T> void sum_one_one(T q[],T len){for(int i = 1;i <= len;i++)q[i] += q[i - 1];}
template <typename T> void sum_one_two(T q[],T s[],T len){for(int i = 1;i <= len;i++)s[i] += q[i] + s[i - 1];}
void sum_two_one(int q[][1010],int n,int m){for(int i = 1;i <= n;i++)for(int j = 1;j <= m;j++)q[i][j] += q[i][j - 1] + q[i - 1][j] - q[i - 1][j - 1];}
int sum_two_get(int q[][1010],int x1,int y1,int x2,int y2){return q[x2][y2] - q[x2][y1 - 1] - q[x1 - 1][y2] + q[x1 - 1][y1 - 1];}
void sum_two_two(int q[][1010],int s[][1010],int n,int m){for(int i = 1;i <= n;i++)for(int j = 1;j <= m;j++)s[i][j] = q[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];}
//差分一维二维
void init_diff(int a[],int b[],int n){for(int i = 1;i <= n;i++)b[i] = a[i] - a[i - 1];}

int n,m,q;
char ca[N];
int tmp[N];
int c[N];
int res[N];
int a[N],b[N];

//快速排序,归并排序
template <typename T> void quick_sort(T q[],T l,T r){if(l >= r)return;T x = q[l + r >> 1];T i = l - 1;T j = r + 1;while(i < j){do{i++;}while(q[i] < x);do{j--;}while(q[j] > x);if(i < j)swap(q[i],q[j]);}quick_sort(q,l,j);quick_sort(q,j+1,r);}
template <typename T> void merge_sort(T q[],T l,T r){if(l >= r)return;T mid = l + r >> 1;merge_sort(q,l,mid);merge_sort(q,mid + 1,r);int k = 0;int i = l;int j = mid + 1;while(i <= mid && j <= r){if(q[i] < q[j])tmp[k++] = q[i++];else tmp[k++] = q[j++];}while(i <= mid)tmp[k++]=q[i++];while(j <= r)tmp[k++]=q[j++];for(int t = l,k = 0;t <= r;t++)q[t]=tmp[k++];}

//高精度加减(附带比较函数)乘除
template <typename T> vector<T> big_add(vector<T> a,vector<T> b){vector<T> c;T t = 0;for(int i = 0;i < a.size() || i < b.size();i++){if(i < a.size())t += a[i];if(i < b.size())t += b[i];c.pb(t % 10);t /= 10;}if(t)c.pb(t);return c;}
template <typename T> int substract_cmp(T a[],T b[]){int n = strlen(a);int m = strlen(b);if(n != m)return n < m;for(int i = 0;i < n;i++){if(a[i] != b[i])return a[i] < b[i];}return 0;}
template <typename T> vector<T> big_substract(vector<T> a,vector<T> b){vector<T> c;T t = 0;for(int i = 0;i < a.size();i++){t = a[i] - t;if(i < b.size())t -= b[i];c.pb((t + 10) % 10);t = t < 0;}while(c.size() > 1 && c.back() == 0)c.pop_back();reverse(c.begin(),c.end());return c;}
template <typename T> vector<T> big_mul(vector<T> a,T b){vector<T> c;LL t = 0;for(int i = 0;i < a.size();i++){t += a[i] * b;c.pb(t % 10);t /= 10;}while(t){c.pb(t % 10);t /= 10;}while(c.size() > 1 && c.back() == 0)c.pop_back();reverse(c.begin(),c.end());return c;}
template <typename T> vector<T> big_div(vector<T> a,T b,T &r){vector<T> c;for(int i = 0;i < a.size();i++){r = r * 10 + a[i];c.pb(r / b);r %= b;}reverse(c.begin(),c.end());while(c.size() > 1 && c.back() == 0)c.pop_back();reverse(c.begin(),c.end());return c;}

int main(){
    scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
    init_diff(a,b,n);
    while(q--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        b[l] += c;
        b[r + 1] -= c;
    }
    sum_one_one(b,n);
    for(int i = 1;i <= n;i++)printf("%d ",b[i]);
    printf("\n");
    return 0;
}