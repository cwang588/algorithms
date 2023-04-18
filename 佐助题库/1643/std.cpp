#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
long long a[100],b[1005];
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
		printf("100\n");
		int ans=105,pos;
		for(int j=0;j<100;++j){
			int tmp=rand()%100;
			printf("%d ",tmp);
			if(tmp<ans){
				ans=tmp;
				pos=j;
			}
		}
		printf("\n");
		freopen(s2,"w",stdout);
		printf("Minimum value: %d\nPosition: %d\n",ans,pos);
	}
	return 0;
}
