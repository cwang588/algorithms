#include<bits/stdc++.h>
using namespace std;
char s[1005][105];
int x[5005],y[5005];
void work(int p,int q)
{
	int l1=strlen(s[p]),l2=strlen(s[q]);
	for(int i=0;i<l2;++i)
	{
		int num1,num2,tot;
		if(s[q][i]<='z'&&s[q][i]>='a')num1=(int)(s[q][i]-'a');
		else num1=(int)(s[q][i]-'A')+26;
		if(s[p][i%l1]<='z'&&s[p][i%l1]>='a')num2=(int)(s[p][i%l1]-'a');
		else num2=(int)(s[p][i%l1]-'A')+26;
		if(num1<num2)tot=num1+52-num2;
		else tot=num1-num2;
		if(tot<=25)s[q][i]=(char)('a'+tot);
		else s[q][i]=(char)('A'+tot-26);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;	
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>x[i]>>y[i];
	for(int i=1;i<=n;++i)cin>>s[i];	
	for(int i=m;i>=1;--i)work(x[i],y[i]);
	for(int i=1;i<=n;++i)cout<<s[i]<<endl;
	return 0;
}
