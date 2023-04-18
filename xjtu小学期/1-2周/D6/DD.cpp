#include<bits/stdc++.h>
using namespace std;
int a[555];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		sort(a+1,a+1+i);
		if(i%2)
			cout<<a[i/2+1]<<endl;
	}
	
	return 0;
}
