#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 110000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,k;
int a[MAXN],b[MAXN],c[MAXN];
LL sum1,sum2;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>k;
		sum1=0;
		sum2=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i]%k;
			sum1+=a[i]/k;
			sum2+=a[i];
		}
		if (sum1>=n-1)
		{
			cout<<k+sum2<<endl;
			continue;
		}
		sum1=(n-1)-sum1;
		sort(b,b+n,greater<int>() );
		sum2=n*k;
		for (int i=sum1;i<n;i++)
			sum2+=b[i];
		cout<<sum2<<endl;
		MRK(); 
	}
	return ~~(0^_^0);
}

