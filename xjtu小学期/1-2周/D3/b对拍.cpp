#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))

#define MAXN 1001000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

struct RECORD
{
	int data,indx;
} record[MAXN];
int n;
int data[MAXN];
int a[MAXN];
 
bool cmp(RECORD r1,RECORD r2)
{
	return r1.data<r2.data;
}

INL int lowbit(int x)
{
	return x&-x;
}

void add(int pos,int x)
{
	for (;pos<=n;pos+=lowbit(pos))
		a[pos]+=x;
}

int query(int pos)
{
	int sum=0;
	for (;pos;pos-=lowbit(pos))
		sum+=a[pos];
	return sum;
}

int main()
{
	cin>>n;
	RPT(i,1,n+1)
	{
		scanf("%d",&record[i].data);
		record[i].indx=i;
	}
	sort(record+1,record+n+1,cmp);
	data[record[1].indx]=1;
	int tem=1;
	RPT(i,2,n+1)
	{
		if (record[i].data>record[i-1].data)
			tem++;
		data[record[i].indx]=tem;
	}
	LL ans=0;
	DRPT(i,n,0)
	{
		ans+=query(data[i]-1);
		add(data[i],1);
	}
	cout<<ans;
	return ~~(0^_^0);
}

