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
		int a=rand()%10,b=rand()%10;
		printf("%d.0\n%d.0\n",a,b);
		freopen(s2,"w",stdout);
		printf("MEDIA = %.5f\n",((double)a*3.5+(double)b*7.5)/11.0);
	}
	return 0;
}
