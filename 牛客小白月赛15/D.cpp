#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
struct fs
{
	long long a,b;//a/b
};
void jia(fs x,fs y)
{
	long long p=x.a*y.b+x.b*y.a,q=x.b*y.b;
	long long c=gcd(p,q);
	cout<<p/c<<' '<<q/c<<endl;
}
void cheng(fs x,fs y)
{
	long long p=x.a*y.a,q=x.b*y.b;
	long long c=gcd(p,q);
	cout<<p/c<<' '<<q/c<<endl;
}
void chu(fs x,fs y)
{
	long long p=x.a*y.b,q=x.b*y.a;
	long long c=gcd(p,q);
	cout<<p/c<<' '<<q/c<<endl;	
}
void jian(fs x,fs y)
{
	long long p=x.a*y.b-x.b*y.a,q=x.b*y.b;	
	bool fu=false;
	if(p==0)
	{
		cout<<"0 0"<<endl;
		return;
	}
	if(p<0&&q>0||p>0&&q<0)
		fu=true;
	p=abs(p);
	q=abs(q);
	long long c=gcd(p,q);
	p/=c;
	q/=c;
	if(fu)
		p*=-1;
	cout<<p<<' '<<q<<endl;
}
int main()
{
	fs x,y;
	cin>>x.a>>x.b>>y.a>>y.b;
	jia(x,y);
	jian(x,y);
	cheng(x,y);
	chu(x,y);
	return 0;
}
