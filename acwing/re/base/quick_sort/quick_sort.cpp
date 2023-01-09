#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n;
int q[N];

void quick_sort(int q[],int l,int r){
    if(l >= r)return;
    int i = l - 1;
    int j = r + 1;
    //划定分界点
    int x = q[l + r >> 1];
    while(i < j){
        //在x左边应该寻找大于的数
        do{
            i++;
        }while(q[i] < x);
        //在x右边应该寻找小于的数
        do{
            j--;
        } while (q[j] > x);
        if(i < j)swap(q[i],q[j]);
    }
    /*
        注意分界点的问题：最后一轮的 i,j 不会进行交换
            即
                q[l....i - 1] <= x,q[i] >= x,[l,i-1]和[i,r]
                q[l....j] <= x,q[j + 1] >= x,[l,j]和[j + 1]
    */
    //递归处理
    quick_sort(q,l,j);
    quick_sort(q,j + 1,r);
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++)scanf("%d",&q[i]);
    quick_sort(q,0,n - 1);
    for(int i = 0;i < n;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
    
    return 0;
}