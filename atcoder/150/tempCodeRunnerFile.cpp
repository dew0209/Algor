#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 400010;

int n;
int a[N],b[N];
int xa[N],xb[N];
int ne[N];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++)cin >> b[i];
	for(int i = 1;i <= n;i++){
		xb[i] = b[i] ^ b[(i + 1) > n ? i + 1 - n : i + 1];
		xa[i] = xa[i + n] = a[i] ^ a[(i + 1) > n ? i + 1 - n : i + 1];//将环断成链
	}
	//求next数组
	for(int i = 2,j = 0;i <= n;i++){
		while(j && xb[j] != xb[j + 1])j = ne[j];
		if(xb[i] == xb[j + 1])j++;
		ne[i] = j;
	}
	for(int i = 1;i <= n;i++){
		cout << xb[i] << ' ' ;
	}
	cout << endl;
	for(int i = 1;i <= 2*n;i++){
		cout << xa[i] << ' ' ;
	}
	cout << endl;
	//匹配的过程
	vector<int> res;
	for(int i = 1,j = 0;i < 2 * n;i++){
		while(j && xa[i] != xb[j + 1])j = ne[j];
		if(xa[i] == xb[j + 1])j++;
		if(j == n){
			//找到了
			//cout << (i - n + 1) % n << ' ' << (a[(i - n + 1) % n] ^ b[1]) << endl;
			//cout << i - n << ' ' << (b[1] ^ a[1 + i - n]) << endl;
			j = ne[j];
			res.push_back(i - n);
		}
	}
	sort(res.begin(),res.end());
	for(auto x : res){
		cout << x << ' ' << (b[1] ^ a[1 + x]) << endl;
	}
	return 0;
}