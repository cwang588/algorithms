#include<bits/stdc++.h>
using namespace std;
string name[10000000005];
int cx[100005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>cx[i]>>name[i];
	int pos=1;
	for(int i=1;i<=m;++i)
	{
		int zy,num;
		cin>>zy>>num;
		if(cx[pos]==zy)
			pos-=num;
		else
			pos+=num;
		if(pos<=0)
			pos+=n;
		if(pos>n)
			pos-=n;
	}
	cout<<name[pos];
	return 0;
}
