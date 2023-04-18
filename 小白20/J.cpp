#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[100005];
char b[100005];
int pos[30][100005];
void init()
{
	int l=strlen(a);
	for(int i=0;i<l;++i)
		pos[a[i]-'a'][++pos[a[i]-'a'][0]]=i;
	return;
}
int main()
{
	cin>>a;
	int n;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i)
	{
		memset(b,' ',sizeof(b));
		cin>>b;
		bool pp=true;
		int ll=strlen(b),now=-1;
		for(int j=0;j<ll;++j)
		{
			bool you=false;
			for(int k=1;k<=pos[b[j]-'a'][0];++k)
			{
				if(pos[b[j]-'a'][k]>now)
				{
					now=pos[b[j]-'a'][k];
					you=true;
					break;
				}
			}
			if(!you)
			{
				pp=false;
				break;
			}
		}
		if(pp)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
