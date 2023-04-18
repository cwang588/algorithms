	#include<bits/stdc++.h>
	using namespace std;
	int main()
	{
		int l=1,r=10;
		int now=19260817;
		while(now)
		{
			int m=(l+r)>>1;
			if(m==r||m==l)
			{
				cout<<l<<endl;
				fflush(stdout);
				cin>>now;
				if(!now)
					return 0;
				else
				{
					cout<<r<<endl;
					fflush(stdout);
					cin>>now;
					return 0;
				}	
			}
			cout<<m<<endl;
			fflush(stdout);
			cin>>now;
			if(now==1)
				r=m;
			if(now==-1)
				l=m;
		}
		return 0;
	}
