#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
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
		int a=rand()%200-100,b=rand()%200-100,c=rand()%200-100,d=rand()%200-100;
		printf("%d %d %d %d\n",a,b,c,d);
		freopen(s2,"w",stdout);
		if(b>c&&d>a&&c+d>a+b&&c>0&&d>0&&a%2==0) cout<<"Valores aceitos"<<endl;
   	 else cout<<"Valores nao aceitos"<<endl;
	}
	return 0;
}
