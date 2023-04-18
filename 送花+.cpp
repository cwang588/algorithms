#include<bits/stdc++.h>
using namespace std;
struct flower
{
	long long val,price;
	bool operator < (const flower &f)const
	{
		return price<f.price;
	}
};
set<flower>s;
int main()
{
	int t;
	long long tot1=0,tot2=0;
	while(1)
	{
		cin>>t;
		if(t==1)
		{
			long long w,c;
			cin>>w>>c;
			flower tmp=flower{w,c};
			s.insert(tmp);
		}
		else if(t==2)
		{
			if(s.size())s.erase(--s.end());
		}
		else if(t==3)
		{
			if(s.size())s.erase(s.begin());
		}
		else break;
	}
	for(set<flower>::iterator it=s.begin();it!=s.end();++it)tot1+=(*it).val,tot2+=(*it).price;
	cout<<tot1<<' '<<tot2<<endl;
	return 0;
}
