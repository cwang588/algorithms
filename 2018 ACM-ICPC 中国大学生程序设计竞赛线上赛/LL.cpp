#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("db.txt","w",stdout);
	cout<<"int db[]={0,"<<endl;
	for(int i=1;i<=10000;++i)
	{
		int now=0;
		for(int j=0;j<=i;++j)
			now+=i|j;
		cout<<now<<',';
	}
	cout<<"};";
	return 0;
}
