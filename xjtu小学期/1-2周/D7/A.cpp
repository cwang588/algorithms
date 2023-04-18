#include<bits/stdc++.h>
using namespace std;
set<unsigned long long>s;
char t[10005];
int L;
unsigned long long hash[10005];
unsigned long long mod[10005];
unsigned long long mi[10005]={1,19260817};
unsigned long long calc(int l,int r)
{
	return hash[r]-hash[l-1]*mi[r-l+1];
}
void init(int n)
{
	for(int i=2;i<=n;++i)
		mi[i]=mi[i-1]*19260817;
}
int main()
{
	cin>>(t+1);
	L=strlen(t+1);
	init(L);
	for(int i=1;i<=L;++i)
		hash[i]=hash[i-1]*19260817+t[i];
	for(int i=1;i<=L;++i)
		for(int j=1;j+i-1<=L;++j)
		{	
			unsigned long long tt=calc(j,j+i-1);
			s.insert(tt);
		}
	cout<<s.size();
	return 0;
}
