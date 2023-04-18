#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL)); 
	int n=rand()%10+5;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%20+3<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%2;
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%2;
	cout<<endl;	
	return 0;
}
