#include<bits/stdc++.h>
using namespace std;
int t[15][15];
int work(int a,int b,int c,int d)
{
	int now=0,re=0;
	now=t[now][a];
	now=t[now][b];
	now=t[now][c];
	now=t[now][d];
	for(int i=0;i<10;++i)
	{
		if(i!=a)
		{
			int tmp=0;
			tmp=t[tmp][i];
			tmp=t[tmp][b];
			tmp=t[tmp][c];
			tmp=t[tmp][d];
			if(t[tmp][now]==0)++re;
//			if(i!=b)
//			{
//				int tmpa=0;
//				tmpa=t[tmpa][b];
//				tmpa=t[tmpa][i];
//				tmpa=t[tmpa][c];
//				tmpa=t[tmpa][d];
//				if(t[tmpa][now]==0)++re;
//			}
//			if(b!=c)
//			{
//				int tmpb=0;
//				tmpb=t[tmpb][a];
//				tmpb=t[tmpb][c];
//				tmpb=t[tmpb][b];
//				tmpb=t[tmpb][d];
//				if(t[tmpb][now]==0)++re;
//			}
//			if(c!=d)
//			{
//				int tmpc=0;
//				tmpc=t[tmpc][a];
//				tmpc=t[tmpc][b];
//				tmpc=t[tmpc][d];
//				tmpc=t[tmpc][c];
//				if(t[tmpc][now]==0)++re;
//			}
		}
	}
	for(int i=0;i<10;++i)
	{
		if(i!=b)
		{
			int tmp=0;
			tmp=t[tmp][a];
			tmp=t[tmp][i];
			tmp=t[tmp][c];
			tmp=t[tmp][d];
			if(t[tmp][now]==0)++re;
//			if(a!=i)
//			{
//				int tmpa=0;
//				tmpa=t[tmpa][i];
//				tmpa=t[tmpa][a];
//				tmpa=t[tmpa][c];
//				tmpa=t[tmpa][d];
//				if(t[tmpa][now]==0)++re;
//			}
//			if(i!=c)
//			{
//				int tmpb=0;
//				tmpb=t[tmpb][a];
//				tmpb=t[tmpb][c];
//				tmpb=t[tmpb][i];
//				tmpb=t[tmpb][d];
//				if(t[tmpb][now]==0)++re;
//			}
//			if(c!=d)
//			{
//				int tmpc=0;
//				tmpc=t[tmpc][a];
//				tmpc=t[tmpc][i];
//				tmpc=t[tmpc][d];
//				tmpc=t[tmpc][c];
//				if(t[tmpc][now]==0)++re;
//			}
		}
	}
	for(int i=0;i<10;++i)
	{
		if(i!=c)
		{
			int tmp=0;
			tmp=t[tmp][a];
			tmp=t[tmp][b];
			tmp=t[tmp][i];
			tmp=t[tmp][d];
			if(t[tmp][now]==0)++re;
//			if(a!=b)
//			{
//				int tmpa=0;
//				tmpa=t[tmpa][b];
//				tmpa=t[tmpa][a];
//				tmpa=t[tmpa][i];
//				tmpa=t[tmpa][d];
//				if(t[tmpa][now]==0)++re;
//			}
//			if(b!=i)
//			{
//				int tmpb=0;
//				tmpb=t[tmpb][a];
//				tmpb=t[tmpb][c];
//				tmpb=t[tmpb][i];
//				tmpb=t[tmpb][d];
//				if(t[tmpb][now]==0)++re;
//			}
//			if(i!=d)
//			{
//				int tmpc=0;
//				tmpc=t[tmpc][a];
//				tmpc=t[tmpc][b];
//				tmpc=t[tmpc][d];
//				tmpc=t[tmpc][i];
//				if(t[tmpc][now]==0)++re;
//			}
		}
	}
	for(int i=0;i<10;++i)
	{
		if(i!=d)
		{
			int tmp=0;
			tmp=t[tmp][a];
			tmp=t[tmp][b];
			tmp=t[tmp][c];
			tmp=t[tmp][i];
			if(t[tmp][now]==0)++re;
//			if(a!=b)
//			{
//				int tmpa=0;
//				tmpa=t[tmpa][b];
//				tmpa=t[tmpa][a];
//				tmpa=t[tmpa][c];
//				tmpa=t[tmpa][i];
//				if(t[tmpa][now]==0)++re;
//			}
//			if(b!=c)
//			{
//				int tmpb=0;
//				tmpb=t[tmpb][a];
//				tmpb=t[tmpb][c];
//				tmpb=t[tmpb][b];
//				tmpb=t[tmpb][i];
//				if(t[tmpb][now]==0)++re;
//			}
//			if(c!=i)
//			{
//				int tmpc=0;
//				tmpc=t[tmpc][a];
//				tmpc=t[tmpc][b];
//				tmpc=t[tmpc][i];
//				tmpc=t[tmpc][c];
//				if(t[tmpc][now]==0)++re;
//			}
		}
	}
	for(int i=0;i<10;++i)
	{
		if(i!=now)
		{
			int tmp=0;
			tmp=t[tmp][a];
			tmp=t[tmp][b];
			tmp=t[tmp][c];
			tmp=t[tmp][d];
			if(t[tmp][i]==0)++re;
		}
	}
	if(a!=b)
	{
		int tmpa=0;
		tmpa=t[tmpa][b];
		tmpa=t[tmpa][a];
		tmpa=t[tmpa][c];
		tmpa=t[tmpa][d];
		if(t[tmpa][now]==0)++re;
	}
	if(b!=c)
	{
		int tmpb=0;
		tmpb=t[tmpb][a];
		tmpb=t[tmpb][c];
		tmpb=t[tmpb][b];
		tmpb=t[tmpb][d];
		if(t[tmpb][now]==0)++re;
	}
	if(c!=d)
	{
		int tmpc=0;
		tmpc=t[tmpc][a];
		tmpc=t[tmpc][b];
		tmpc=t[tmpc][d];
		tmpc=t[tmpc][c];
		if(t[tmpc][now]==0)++re;
	}
	if(d!=now)
	{
		int tmpd=0;
		tmpd=t[tmpd][a];
		tmpd=t[tmpd][b];
		tmpd=t[tmpd][c];
		tmpd=t[tmpd][now];
		if(t[tmpd][d]==0)++re;
	}
	return re;
}
int main()
{
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			scanf("%d",&t[i][j]);
	int ans=0;
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			for(int k=0;k<10;++k)
				for(int x=0;x<10;++x)
					ans+=work(i,j,k,x)>0?1:0;
	printf("%d\n",ans);
	return 0;
}
