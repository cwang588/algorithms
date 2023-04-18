#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[105],b[105];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		for(int j=1;j<=100;++j)a[j]=rand()%100+1,b[j]=rand()%100+1,printf("%d %d\n",a[j],b[j]);
		printf("-1 0\n");
		freopen(s2,"w",stdout);
		for(int j=1;j<=100;++j){
			int tot=0;
			for(int k=min(a[j],b[j]);k<=max(a[j],b[j]);++k)printf("%d ",k),tot+=k;
			printf("Sum=%d\n",tot);			
		}
	}
	return 0;
}
