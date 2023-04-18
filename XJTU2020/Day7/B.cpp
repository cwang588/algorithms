#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
void init()
{
	m["Beijing"]=8;
	m["Washington"]=-5;
	m["London"]=0;
	m["Moscow"]=3;
}
int main()
{
	int t;
	cin>>t;
	init();
	for(int Case=1;Case<=t;++Case)
	{
		int x,y;
		scanf("%d:%d",&x,&y);
		string tmp;
		cin>>tmp;
		if(tmp=="PM")x+=12;
		string city1,city2;
		cin>>city1>>city2;
		x+=m[city2]-m[city1];
		cout<<"Case "<<Case<<": ";
		if(x>=24)
		{
			cout<<"Tomorrow ";
			if(x>24)x-=24;
		}
		else if(x<=0)cout<<"Yesterday ",x+=24;
		else cout<<"Today ";
		if(x>12&&x<24)printf("%02d:%02d PM\n",x-12,y);
		else printf("%02d:%02d AM\n",x==24?x-12:x,y);
	}
	return 0;
}
