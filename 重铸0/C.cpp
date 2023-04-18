#include<bits/stdc++.h>
using namespace std;
char s[105];
double calc1(int x){
	return sqrt((x-0.5)*(x-0.5)+(1-sqrt(3)/2)*(1-sqrt(3)/2));
}
double calc2(int x){
	double xita=acos(-1)/2+atan((sqrt(3)-1)/(2.0*x))+acos(0.5/sqrt(x*x+(sqrt(3)/2-0.5)*(sqrt(3)/2-0.5)));
	xita=acos(-1)-xita;
	return xita*0.5-0.5+sqrt(x*x+(sqrt(3)/2-0.5)*(sqrt(3)/2-0.5)-0.25);
}
int main(){
	//for(int i=1;i<=20;++i)cout<<calc2(i)+10-i<<endl;
	int n;
	cin>>n>>(s+1);
	int scnt1=0,scnt2=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='T')++scnt1;
		else break;
	}
	for(int i=n;i>=1;--i){
		if(s[i]=='T')++scnt2;
		else break;
	}
	double ans;
	if(scnt1+scnt2>=n)ans=n*2+1;
	else if(scnt1&&scnt2){
		ans=scnt1+scnt2+2;
		for(int i=scnt1+1;i<=n-scnt2;++i)ans+=2;
		if(s[scnt1+1]=='C')ans+=calc2(scnt1);
		else ans+=calc1(scnt1);
		if(s[n-scnt2]=='C')ans+=calc2(scnt2);
		else ans+=calc1(scnt2);
	}
	else if(scnt1){
		ans=scnt1+1;
		if(s[scnt1+1]=='C')ans+=calc2(scnt1);
		else ans+=calc1(scnt1);
		for(int i=scnt1+1;i<n;++i)ans+=2;
		if(s[n]=='C')ans+=acos(-1)/2+1;
		else ans+=3;
	} 
	else if(scnt2){
		ans=scnt2+1;
		if(s[n-scnt2]=='C')ans+=calc2(scnt2);
		else ans+=calc1(scnt2);
		for(int i=2;i<=n-scnt2;++i)ans+=2;
		if(s[1]=='C')ans+=acos(-1)/2+1;
		else ans+=3;
	}
	else{
		ans=(n-2)*2;
		if(s[1]=='C')ans+=acos(-1)/2+1;
		else ans+=3;
		if(s[n]=='C')ans+=acos(-1)/2+1;
		else ans+=3;
	}
	printf("%.13lf\n",ans);
	return 0;
}
