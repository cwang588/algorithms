#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
unordered_map<string,int>mm;
struct matrix
{
	long long a[17][17];
	matrix()
	{
		memset(a,0,sizeof(a));
	}
	inline void build()
	{
		for(int i=1;i<=14;++i)
			a[i][i]=1;
	}
}t;
matrix operator *(const matrix &x,const matrix &y)
{
	matrix z;
	for(int k=1;k<=14;++k)
		for(int i=1;i<=14;++i)
			for(int j=1;j<=14;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
	return z;
}
void init(){
	t.a[1][3]=1;
	t.a[2][1]=1;
	t.a[3][2]=t.a[3][4]=1;
	t.a[4][3]=t.a[4][4]=1;
	t.a[5][3]=1;
	t.a[6][5]=1;
	t.a[7][13]=1;
	t.a[8][11]=1;
	t.a[9][12]=1;
	t.a[10][14]=t.a[10][6]=1;
	t.a[11][9]=1;
	t.a[12][7]=1;
	t.a[13][4]=t.a[13][8]=1;
	t.a[14][10]=1;
	mm["1"]=1;
	mm["2"]=2;
	mm["4"]=3;
	mm["6"]=4;
	mm["16"]=5;
	mm["26"]=6;
	mm["41"]=7;
	mm["42"]=8;
	mm["44"]=9;
	mm["46"]=10;
	mm["61"]=11;
	mm["62"]=12;
	mm["64"]=13;
	mm["66"]=14;
}
int main(){
	long long n;
	cin>>n;
	matrix ans;
	ans.build();
	init();
	long long m=n-1;
	while(m){
		if(m&1)
			ans=ans*t;
		t=t*t;
		m>>=1;
	}
	string s;
	cin>>s;
//	printf("%d\n",mm[s]);
	printf("%lld\n",ans.a[mm[s]][2]);
	return 0;
}
