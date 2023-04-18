#include<cstdio>
#include<iostream>
using namespace std;
int ans[]={1,9,41,109,205};
void print(__int128 x)

{

	if (!x) return ;

	if (x < 0) putchar('-'),x = -x;

	print(x / 10);

	putchar(x % 10 + '0');

}
inline __int128 read()

{

   int X=0,w=0; char ch=0;

   while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}

   while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();

   return w?-X:X;

}
void gaoshi(__int128 n)
{
	if(n<=4)
		cout<<ans[n];
	else
		print(14*n*n-6*n+5);
	cout<<endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		__int128 n=read();
		cout<<"Case #"<<i<<": ";
		gaoshi(n);
	}
	return 0;
} 
