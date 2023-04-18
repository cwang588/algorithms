#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[105],b[105];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=0;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		printf("45\n");
		freopen(s2,"w",stdout);
		a[1]=0,a[2]=1;
		for(int j=3;j<=45;++j){
			a[j]=a[j-1]+a[j-2];
		}
		for(int j=1;j<=45;++j)printf("%d ",a[j]);
	}
	return 0;
}
