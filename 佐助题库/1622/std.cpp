#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
long long a[105],b[105];
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int cnt=0;
		for(int j=1;j<=6;++j){
			int tmp=rand()%200-100;
			while(!tmp)tmp=rand()%200-100;
			cout<<tmp<<endl;
			if(tmp>0)++cnt;
		}
		freopen(s2,"w",stdout);
		printf("%d positive numbers\n",cnt);
	}
	return 0;
}
