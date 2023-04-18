#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[100][105],b[1005];
char db[]={'C','R','F'};
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int t=rand()%2;
		if(t)printf("M\n");
		else printf("S\n");
		int tot=0;
		for(int j=0;j<12;++j){
			for(int k=0;k<12;++k){
				a[j][k]=rand()%20;
				printf("%d.0 ",a[j][k]);
				if(j+k<=10&&j<k)tot+=a[j][k];
			}
			printf("\n");
		}
		freopen(s2,"w",stdout);
		double ans=tot;
		if(t)ans/=30.0;
		printf("%.1f\n",ans);
	}
	return 0;
}
