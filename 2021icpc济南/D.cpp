#include <bits/stdc++.h>
using namespace std;
#define rep(i,aa,bb) for(long long i=aa;i<(bb);++i)

long long a[300005];
int n;
long long b[300005];
long long c[300005];
long long ans=-1;
long long RR=2e13;
long long LCR(long long k)
{
	long long LS,sum=0,sum2=0,kp;
	b[1]=0;
	for(int i=2;i<=n;i++)b[i]=b[i-1]+k;
	for(int i=1;i<=n;i++)c[i]=b[i]-a[i];
	sort(c+1,c+1+n);
	if(n%2==1){
		LS=c[(n+1)/2];
		for(int i=1;i<=n;i++){
			c[i]-=LS;
			sum+=abs(c[i]);
		}
		kp=sum;
	}
	else{
		LS=c[n/2];
		for(int i=1;i<=n;i++)sum+=abs(c[i]-LS);
		kp=sum;
		LS=c[n/2+1];
		for(int i=1;i<=n;i++)sum2+=abs(c[i]-LS);	
		if(sum2>=0)kp=min(sum,sum2);
	}
	if(ans<0&&kp>=0)ans=kp;
	else{
		if(kp>=0)ans=min(ans,kp);
	}
	return kp;
}
long long TS(long long aa,long long bb)
{
	while(bb-aa>=5){
		long long mid=(aa+bb)/2;
		long long LS1=LCR(mid);
		long long LS2=LCR(mid+1);
		if(LS1>=0&&LS2>=0){
			if(LS1>LS2)aa=mid;
			else bb=mid+1;			
		}
		else{
			if(LS2>=0){
				aa=mid;
			}
			else{
				if(LS1>=0)bb=mid+1;
				else{
					if(mid>0)bb=mid+1;
					else aa=mid;
				}
			}
		}
	}
	rep(i,aa-10,bb+12)if(LCR(aa)>LCR(i))aa=i;
	return aa;
}
int main()
{
	int i,j,k,ll=-1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i!=1&&a[i]!=a[i-1])ll=1;
	}
	if(n==1||ll==-1)printf("0\n");
	else{
		TS(-RR,RR);
		printf("%lld\n",ans);
	}
	return 0;
}