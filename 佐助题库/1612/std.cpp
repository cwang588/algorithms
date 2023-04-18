#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
double a[105][105];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int Max=0,pos;
		for(int j=1;j<=100;++j){
			int tmp=rand()%50000+1;
			if(tmp>Max){
				Max=tmp;
				pos=j;
			}
			printf("%d\n",tmp);
		}
		freopen(s2,"w",stdout);
		printf("%d\n%d\n",Max,pos);
	}
	return 0;
}
