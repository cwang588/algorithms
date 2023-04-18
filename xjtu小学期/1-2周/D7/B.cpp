#include<bits/stdc++.h>
using namespace std;
char t[3000005],tt[2000005];
int L;
unsigned long long hash[2000005];
unsigned long long mod[2000005];
unsigned long long mi[2000005]={1,19260817};
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
	cin>>(tt+1);
	L=strlen(t+1);
	for(int i=1;i<=L;++i)
		t[i+L]=t[i];
	L*=2;
	init(L);
	int LL=strlen(tt+1);
	unsigned long long nowhash=0;
	for(int i=1;i<=L;++i)
		hash[i]=hash[i-1]*19260817+t[i];
	for(int i=1;i<=strlen(tt+1);++i)
		nowhash=nowhash*19260817+tt[i];	
	for(int i=1;i<=L-LL;++i)
	{
		if(calc(i,i+LL-1)==nowhash)
			return !printf("Yes");
	}
	for(int i=1;i<=L/2;++i)
	{
		char l;
		l=t[i];
		t[i]=t[L-i+1];
		t[L-i+1]=l;
	}
	for(int i=1;i<=L;++i)
		hash[i]=hash[i-1]*19260817+t[i];
	for(int i=1;i<=L-LL;++i)
	{
		if(calc(i,i+LL-1)==nowhash)
			return !printf("Yes");
	}
	printf("No");
	return 0;
}
