#include<cstdio>
#include<cstring>
using namespace std;
char a[55];
int main()
{
	scanf("%s",&a);
	bool fu=false,even=false;
	int tot=0,l=strlen(a);
	if((a[l-1]-'0')%2==0)
		even=true;
	if(a[0]=='-')
	{
		fu=true;
		for(int i=1;i<l;++i)
			if(a[i]=='2')
				++tot;
		--l;
	}
	else
	{
		for(int i=0;i<l;++i)
			if(a[i]=='2')
				++tot; 
	}
	double ans=100.0*(double)tot/(double)l;
	if(fu)
		ans*=1.5;
	if(even)
		ans*=2.0;
	printf("%.2lf%%",ans);
	return 0;
}
