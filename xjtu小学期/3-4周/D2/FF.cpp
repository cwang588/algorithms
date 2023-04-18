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

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;
 	
int n;
int c[MAXN];
int s,t;
void binprint(int x)
{
	RPT(i,0,n)
		if (x & (1<<i))
			putchar('1');
		else
			putchar('0');
} 

int cal(int x)
{
	int ans=0;
	RPT(i,0,n)
		if (x & (1<<i))
			ans+=c[i];
	return ans;
}

int dp[1000000];
int lst[1000000];
int output(int x)
{
	if (x==lst[x])
	{
		printf("  ");
		binprint(x);
	}
	else
	{
		output(lst[x]);
		printf("->");
		binprint(x);
	}
	cout<<endl;
}

int main()
{
	MST(dp,INF);
	cin>>n;
	RPT(i,0,n)
		cin>>c[i];
	char c;
	RPT(i,0,n)
	{
		cin>>c;
		s|=(1<<i) * (c-'0');
	}
	//binprint(s);
	RPT(i,0,n)
	{
		cin>>c;
		t|=(1<<i) * (c-'0');
	}
	queue<int> q;
	q.push(s);
	dp[s]=0;
	lst[s]=s;
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		RPT(i,0,n)
		{
			int to=pos ^ (1<<i);
			int v=cal(to);
			if (dp[to]>dp[pos]+v)
			{
				dp[to]=dp[pos]+v;
				lst[to]=pos;
				q.push(to);
			}
		}
	}
	cout<<dp[t]<<endl;
//	output(t);
	return ~~(0^_^0);
}

