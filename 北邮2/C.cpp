#include<cstdio>
using namespace std;
int xx1,xx2,yy1,yy2;
int xxx1,xxx2,yyy1,yyy2,xxx3,xxx4,yyy3,yyy4;
int n;
int a[5];
void dfsl(int l,int r)
{
	if(l==r)
	{
		xx1=l;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d 1 %d %d\n",l,m,n);
	fflush(stdout);
	scanf("%d",&t);
	if(t==0)
		dfsl(m+1,r);
	else if(t==2)
		dfsl(l,m);
	else
		dfsl(l,m);
}
void dfsd(int l,int r)
{
	if(l==r)
	{
		yy2=l;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? 1 %d %d %d\n",m+1,n,r);
	fflush(stdout);
	scanf("%d",&t);
	if(t==0)
		dfsd(l,m);
	else if(t==2)
		dfsd(m+1,r);
	else
		dfsd(m+1,r);
}
void dfsu(int l,int r)
{
	if(l==r)
	{
		yy1=l;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? 1 %d %d %d\n",l,n,m);
	fflush(stdout);
	scanf("%d",&t);
	if(t==0)
		dfsu(m+1,r);
	else if(t==2)
		dfsu(l,m);
	else
		dfsu(l,m);
}
void dfsr(int l,int r)
{
	if(l==r)
	{
		xx2=l;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d 1 %d %d\n",m+1,r,n);
	fflush(stdout);
	scanf("%d",&t);
	if(t==0)
		dfsr(l,m);
	else if(t==2)
		dfsr(m+1,r);
	else
		dfsr(m+1,r);
}
void dfsx1(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",l,yy1,l,yy1);
		fflush(stdout);
		scanf("%d",&t);
		xxx2=l+t-1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",l,yy1,m,yy1);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsx1(l,m);
	else
	{
		printf("? %d %d %d %d\n",m,yy1,m,yy1);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsx1(m+1,r);
		else
			dfsx1(l,m);
	}
}
void dfsy1(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",xx1,l,xx1,l);
		fflush(stdout);
		scanf("%d",&t);
		yyy2=l+t-1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",xx1,l,xx1,m);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsy1(l,m);
	else
	{
		printf("? %d %d %d %d\n",xx1,m,xx1,m);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsy1(m+1,r);
		else
			dfsy1(l,m);
	}
}
void dfsx2(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",l,yy2,l,yy2);
		fflush(stdout);
		scanf("%d",&t);
		xxx2=l+t-1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",l,yy2,m,yy2);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsx2(l,m);
	else
	{
		printf("? %d %d %d %d\n",m,yy2,m,yy2);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsx2(m+1,r);
		else
			dfsx2(l,m);
	}
}
void dfsy2(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",xx1,l,xx1,l);
		fflush(stdout);
		scanf("%d",&t);
		yyy1=l-t+1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",xx1,m+1,xx1,r);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsy2(m+1,r);
	else
	{
		printf("? %d %d %d %d\n",xx1,m,xx1,m);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsy2(l,m);
		else
			dfsy2(m+1,r);
	}
}
void dfsx3(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",l,yy1,l,yy1);
		fflush(stdout);
		scanf("%d",&t);
		xxx3=l+t-1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",m+1,yy1,r,yy1);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsx3(l,m);
	else
	{
		printf("? %d %d %d %d\n",m,yy1,m,yy1);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsx3(l,m);
		else
			dfsx3(m+1,r);
	}
}
void dfsy3(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",xx2,l,xx2,l);
		fflush(stdout);
		scanf("%d",&t);
		yyy4=l+t-1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",xx2,l,xx2,m);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsy3(l,m);
	else
	{
		printf("? %d %d %d %d\n",xx2,m,xx2,m);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsy3(m+1,r);
		else
			dfsy3(l,m);
	}
}
void dfsx4(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",l,yy2,l,yy2);
		fflush(stdout);
		scanf("%d",&t);
		xxx3=l-t+1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",m+1,yy2,r,yy2);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsx4(l,m);
	else
	{
		printf("? %d %d %d %d\n",m,yy2,m,yy2);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsx4(l,m);
		else
			dfsx4(m+1,r);
	}
}
void dfsy4(int l,int r)
{
	if(l==r)
	{	
		int t;
		printf("? %d %d %d %d\n",xx2,l,xx2,l);
		fflush(stdout);
		scanf("%d",&t);
		yyy3=l-t+1;
		return;
	}
	int m=(l+r)>>1;
	int t;
	printf("? %d %d %d %d\n",xx2,m+1,xx2,r);
	fflush(stdout);
	scanf("%d",&t);
	if(t==2)
		dfsy4(l,m);
	else
	{
		printf("? %d %d %d %d\n",xx2,m,xx2,m);
		fflush(stdout);
		scanf("%d",&t);	
		if(t)
			dfsy4(l,m);
		else
			dfsy4(m+1,r);
	}
}
int main()
{
	scanf("%d",&n);
	dfsl(1,n);
	dfsr(1,n);
	dfsd(1,n);
	dfsu(1,n);	
	printf("? %d %d %d %d\n",xx1,yy1,xx1,yy1);
	fflush(stdout);
	scanf("%d",&a[1]);
	printf("? %d %d %d %d\n",xx1,yy2,xx1,yy2);
	fflush(stdout);
	scanf("%d",&a[2]);
	printf("? %d %d %d %d\n",xx2,yy1,xx2,yy1);
	fflush(stdout);
	scanf("%d",&a[3]);
	printf("? %d %d %d %d\n",xx2,yy2,xx2,yy2);
	fflush(stdout);
	scanf("%d",&a[4]);	
	if(a[1]&&a[4])
	{
		xxx1=xx1;
		xxx4=xx2;
		yyy1=yy1;
		yyy4=yy2;
		dfsx1(xx1,xx2);
		dfsy1(yy1,yy2);
		dfsx4(xx1,xx2);
		dfsy4(yy1,yy2);		
	}
	else
	{
		xxx1=xx1;
		xxx4=xx2;
		yyy2=yy2;
		yyy3=yy1;
		dfsx2(xx1,xx2);
		dfsy2(yy1,yy2);
		dfsx3(xx1,xx2);
		dfsy3(yy1,yy2);	
	}
	printf("! %d %d %d %d %d %d %d %d",xxx1,yyy1,xxx2,yyy2,xxx3,yyy3,xxx4,yyy4);
	return 0;
}
