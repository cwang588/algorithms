#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int n=5;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		printf("%d %d\n",rand()%15-7,rand()%15-7);
	
	return 0;
}
