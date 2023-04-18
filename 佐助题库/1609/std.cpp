#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
double a[105][105];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int tmp=rand()%2;
		if(tmp)cout<<"S\n";
		else cout<<"M\n";
		for(int j=1;j<=12;++j){
			for(int k=1;k<=12;++k){
				a[j][k]=(double)(rand()%20000-10000)/100.0;
				printf("%.1f ",a[j][k]);
			}
			printf("\n");
		}
		freopen(s2,"w",stdout);
		freopen(s1,"r",stdin);
		char t;cin>>t;
		double tot=0.0;
		for(int o=1;o<=12;++o)
		for(int j=1;j<=12;++j)
		{
			double ttt;
			cin>>ttt;
			if(o<j)tot+=ttt;
		}
		if(!tmp)tot/=66.0;
		printf("%.1f\n",tot);
	}
	return 0;
}
