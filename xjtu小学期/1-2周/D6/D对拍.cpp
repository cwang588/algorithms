#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time);
	int n=rand()%20+5;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%100<<' ';
	return 0;
}
