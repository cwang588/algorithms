#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
int a[30],t[30];
int n;
set<unsigned long long>s;
void calc()
{
	unsigned long long now=0;
	for(int i=0;i<24;++i)
		now=now*19260817+(unsigned long long)a[i];
	s.insert(now);
}
void op1()
{
	for(int i=0;i<24;++i)
		t[i]=a[i];
	a[0]=t[1];
	a[1]=t[3];
	a[2]=t[0];
	a[3]=t[2];
	a[6]=t[4];
	a[8]=t[6];
	a[23]=t[8];
	a[4]=t[23];
	a[7]=t[5];
	a[9]=t[7];
	a[22]=t[9];
	a[5]=t[22];
	calc();
}
void op2()
{
	for(int i=0;i<24;++i)
		t[i]=a[i];
	a[0]=t[2];
	a[2]=t[3];
	a[3]=t[1];
	a[1]=t[0];
	a[6]=t[8];
	a[8]=t[23];
	a[23]=t[4];
	a[4]=t[6];
	a[7]=t[9];
	a[9]=t[22];
	a[22]=t[5];
	a[5]=t[7];
	calc();
}
void op3()
{
	for(int i=0;i<24;++i)
		t[i]=a[i];
	a[0]=t[6];
	a[2]=t[12];
	a[6]=t[16];
	a[12]=t[18];
	a[16]=t[20];
	a[18]=t[22];
	a[20]=t[0];
	a[22]=t[2];
	a[4]=t[5];
	a[5]=t[11];
	a[10]=t[4];
	a[11]=t[10];
	calc();
}
void op4()
{
	for(int i=0;i<24;++i)
		t[i]=a[i];
	a[0]=t[20];
	a[2]=t[22];
	a[6]=t[0];
	a[12]=t[2];
	a[16]=t[6];
	a[18]=t[12];
	a[20]=t[16];
	a[22]=t[18];
	a[4]=t[10];
	a[5]=t[4];
	a[10]=t[11];
	a[11]=t[5];
	calc();
}
void op5()
{
	for(int i=0;i<24;++i)
		t[i]=a[i];
	a[2]=t[8];
	a[3]=t[14];
	a[8]=t[17];
	a[14]=t[16];
	a[17]=t[11];
	a[16]=t[5];
	a[11]=t[2];
	a[5]=t[3];
	a[6]=t[7];
	a[7]=t[13];
	a[12]=t[6];
	a[13]=t[12];
	calc();
}
void op6()
{
	for(int i=0;i<24;++i)
		t[i]=a[i];
	a[2]=t[11];
	a[3]=t[5];
	a[8]=t[2];
	a[14]=t[3];
	a[17]=t[8];
	a[16]=t[14];
	a[11]=t[17];
	a[5]=t[16];
	a[6]=t[12];
	a[7]=t[6];
	a[12]=t[13];
	a[13]=t[7];
	calc();
}
void dfs(int now,int pre1,int pre2)
{
	if(now==n+1)
		return;
	if(pre1!=1||pre2!=1)
	{
		op1();
		dfs(now+1,1,pre1);
		op2();
	}
	if(pre1!=2||pre2!=2)
	{
		op2();
		dfs(now+1,2,pre1);
		op1();
	}
	if(pre1!=3||pre2!=3)
	{
		op3();
		dfs(now+1,3,pre1);
		op4();
	}
	if(pre1!=4||pre2!=4)
	{
		op4();
		dfs(now+1,4,pre1);
		op3();
	}
	if(pre1!=5||pre2!=5)
	{
		op5();
		dfs(now+1,5,pre1);
		op6();
	}
	if(pre1!=6||pre2!=6)
	{
		op6();
		dfs(now+1,6,pre1);
		op5();
	}
}
int main()
{
	while(cin>>n)
	{
		s.clear();
		for(int i=0;i<24;++i)
			scanf("%d",&a[i]);
		calc();
		dfs(1,0,0);
		printf("%lld\n",(long long)s.size());
	}
	return 0;
}
