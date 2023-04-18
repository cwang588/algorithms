#include<bits/stdc++.h>
using namespace std;
int a[3005][35];
int main()
{
	freopen("data.txt","w",stdout);
	for(int i=1;i<=3000;++i)
	{
		int num=0;
		for(int j=1;j<=min(i-1,30);++j)
			if(i%j==0)
				a[i][++num]=j;
		a[i][0]=num;
	}
	for(int i=1;i<=3000;++i)
	{
		cout<<'{';
		for(int j=0;j<a[i][0];++j)
			cout<<a[i][j]<<',';
		cout<<a[i][a[i][0]]<<"},"<<endl;
	}
	return 0;
}
