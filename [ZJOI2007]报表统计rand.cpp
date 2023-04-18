#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(0));
	int n,m;
	n=rand()%20+5;
	m=rand()%50+5;
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;++i)cout<<rand()<<" ";
	cout<<endl;
	for(int i=1;i<=m;++i)
	{
		int t=rand()%3;
		if(!t)cout<<"INSERT "<<rand()%n+1<<" "<<rand()<<endl;
		else if(t==1)cout<<"MIN_GAP\n";
		else cout<<"MIN_SORT_GAP\n";
	}
	return 0;
}
