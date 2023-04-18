#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int n=rand()%6+2,q=rand()%4+2;
	cout<<n<<' '<<q<<endl;
	for(int i=1;i<=q;++i)
	{
		int a=rand()%n+1,b=rand()%n+1;
		if(a>b)
			swap(a,b);
		cout<<a<<' '<<b<<endl;
	}
	return 0;
}
