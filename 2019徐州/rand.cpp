#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int n=rand()%10+5,q=rand()%10+5;
	cout<<n<<' '<<q<<endl;
	for(int i=1;i<=q;++i)
	{
		int x=rand()%2+1,y=rand()%n+1;
		cout<<x<<' '<<y<<endl;
	}
	return 0;
}
