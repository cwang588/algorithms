
#include <iostream> 

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <iomanip>

#include <algorithm>

#include <climits>

#include <cstring>

#include <string>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <vector>

#include <list>

#define rep(i,m,n) for(int i=m;i<=n;i++)

#define rsp(it,s) for(set<int>::iterator it=s.begin();it!=s.end();it++)

const int inf_int = 2e9;

const long long inf_ll = 2e18;

#define inf_add 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define mp make_pair

#define fi first

#define se second

#define pi acos(-1.0)

#define pii pair<int,int>

#define Lson L, mid, rt<<1

#define Rson mid+1, R, rt<<1|1

const int maxn=5e2+10;

using namespace std;

typedef  vector<int> vi;

typedef  long long ll;

typedef  unsigned long long  ull; 

inline int read(){int ra,fh;char rx;rx=getchar(),ra=0,fh=1;

while((rx<'0'||rx>'9')&&rx!='-')rx=getchar();if(rx=='-')

fh=-1,rx=getchar();while(rx>='0'&&rx<='9')ra*=10,ra+=rx-48,

rx=getchar();return ra*fh;}

//#pragma comment(linker, "/STACK:102400000,102400000")

ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}

ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

const int N = 1e7+5;

 

int ss[100005];

string s,a,t;

int n;

string getstr(int x,int kk);

int ff = 1;

int main()

{

	while(cin >> n>>a)

	{

		ff = 1;

		for(int k=2;k<=16;k++)

		{

			t.clear();

			for(int i=1;i<=n;i++)

			{

				t+=getstr(i,k);

			}

			

			if(t.find(a)!=string::npos)

			{

				cout<<"yes"<<endl;

				ff  = 0 ;

				break;

			}

		}

		if(ff)

		{

			cout<<"no"<<endl;

		}

	}

    return 0;   

} 







string getstr(int x,int p)

{

	int m = 0;

	int c;

	string re;

	re.clear();

 	while (x!=0)//数制转换，结果存入数组s[m]  

    {  

        c=x%p;  

        x=x/p;  

        m++;ss[m]=c;   //将余数按顺序存入数组s[m]中  

    }  

     

    for(int k=m;k>=1;k--)//输出转换后的序列  

    {  

        if(ss[k]>=10) //若为十六进制等则输出相对应的字母  

            re+=(char)(ss[k]+55);  

        else         //否则直接输出数字  

            re+=(char)(ss[k]+'0');  

    }  

    return re;

}

