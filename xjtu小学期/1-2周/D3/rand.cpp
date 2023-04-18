#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL)); 
	int t=rand()%10+1;
	cout<<t<<endl;
	for(int i=1;i<=t;++i)
		cout<<rand()%15+1<<' ';
	return 0;
}
