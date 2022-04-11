#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int n,i,j,k,ans,aim;
int a[200],b[200],Max[200];
int fa[200][25];

int main()
{
	scanf("%d",&n);
	for(i=n;i>=1;--i)scanf("%d",&a[i]),a[i+n]=a[i];
	for(i=1;i<=n+n;++i)
	{
		a[i]=i+a[i];
		if(a[i]>n+n)a[i]=n+n;
	}
    for(int i = 0;i < 20;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
	for(i=n+n;i>=1;--i)
	{
		for(j=a[i];j;j-=j&-j){
            if(a[Max[j]]>a[b[i]])b[i]=Max[j];
        }
		for(j=i;j<=n+n;j+=j&-j)if(a[i]>a[Max[j]])Max[j]=i;
		if(!b[i])b[i]=i;
	}
	for(i=n+n;i>=1;--i)
	for(fa[i][0]=b[i],j=0;j<=20;++j)fa[i][j+1]=fa[fa[i][j]][j];
	for(i=1;i<=n;++i)
	{
		aim=i+n-1;
		for(k=i,j=20;j>=0;--j)if(a[fa[k][j]]<aim)k=fa[k][j],ans+=1<<j;
		++ans;if(a[k]<aim)++ans;
	}
	printf("%d\n",ans);
}