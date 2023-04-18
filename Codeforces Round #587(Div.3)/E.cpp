#include<bits/stdc++.h>
using namespace std;
int calc(int x){
	int re=0;
	while(x){
		++re;
		x/=10;
	}
	return re;
}
long long mi(int x){
	long long re=0;
	while(x--)re*=10;
	return re;
}
long long calc1(int x){
	long long tot=0,now=0;
	int l=1,r=9;
	for(int i=1;i<=9;++i){
		long long cnt=r-l+1;
		tot+=cnt*now+(cnt+1)*cnt/2*i;
		if(tot>=x){
			while(l<r-1){
				int m=(l+r)>>1;
				if(tot-(mi(i)-1-m)*now-(m+mi(i))*(mi(i)-1-m)/2*i>x)r=m;
				else l=m;
			}
			return l;
		}
		now+=cnt*i;
		cnt*=10;
		l*=10,r=r*10+9;
	}	
	return -1;
}
int calc2(long long num,int x){
	long long tot=0;
	int l=1,r=9;
	for(int i=1;i<=9;++i){
		tot+=1ll*(r-l+1)*i;
		if(tot>=num){
			tot-=1ll*(r-l+1)*i;
			int tmp=l+(num-tot)/i;
		}
		l*=10,r=r*10+9;
	}
	return -1;
}
int main(){
	cout<<tot<<"\n";
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		int l=0,r=482720321;
		while(l<r-1){
			int m=(l+r)>>1;
			if(calc1(m)<n)l=m;
			else r=m;
		}
		cout<<calc2(n-calc1(r-1),r)<<'\n';
	}
	return 0;
}