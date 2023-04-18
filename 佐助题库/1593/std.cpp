#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int l=rand()%1000+1,r=rand()%1000+1;
		if(l>r)swap(l,r);
		freopen(s1,"w",stdout);
		cout<<l<<' '<<r<<endl;
		freopen(s2,"w",stdout);
		int ans=0;
		for(int j=l;j<=r;++j)ans+=j;
		cout<<ans<<endl;
	}
	return 0;
}
