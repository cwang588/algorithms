#include<bits/stdc++.h>
using namespace std;
int re(int x)
{
	int tot=0;
	int t=x;
	while(t)
	{
		tot=tot*10+t%10;
		t/=10;
	}
	return tot;
}
int main()
{
	freopen("db.txt","w",stdout);
	for(int i=1;i<=10000;++i)
	{
		int j=re(i);
		cout<<i<<' '<<(i-j)/9<<endl;
	}
	
	return 0;
} 
