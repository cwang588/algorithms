#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,x;
	cin>>t>>x;
	for(int Case=1;Case<=t;++Case){
		int w,e;
		cin>>w>>e;
		cout<<"Case #"<<Case<<": ";
//		if(e==0){
//			for(int i=1;i<=22;++i)cout<<"R";
//			for(int i=23;i<=60;++i)cout<<"S";
//		}
//		else if(e==w){
//			for(int i=1;i<=20;++i)cout<<"RSP";
//		}
//		else if(e==w/2){
//			for(int i=1;i<=9;++i)cout<<"R";
//			for(int i=1;i<=17;++i)cout<<"SP";
//		}
//		else{
//			for(int i=1;i<=15;++i)cout<<"R";
//			for(int i=1;i<=15;++i)cout<<"PS";
//		}
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=60;++i){
			int s1=e*cnt2+w*cnt3;
			int s2=e*cnt3+w*cnt1;
			int s3=e*cnt1+w*cnt2;
			if(s1>s2&&s1>s3)cout<<"R",++cnt1;
			if(s2>s1&&s2>s3)cout<<"S",++cnt2;
			if(s3>s1&&s3>s2)cout<<"P",++cnt3;
			if(s1==s2&&s1>s3){
				int tmp=rand()%2;
				if(tmp)cout<<"R",++cnt1;
				else cout<<"S",++cnt2;
			}
			if(s1==s3&&s1>s2){
				int tmp=rand()%2;
				if(tmp)cout<<"R",++cnt1;
				else cout<<"P",++cnt3;
			}
			if(s2==s3&&s2>s1){
				int tmp=rand()%2;
				if(tmp)cout<<"S",++cnt2;
				else cout<<"P",++cnt3;
			}
			else{
				int tmp=rand()%2;
				if(tmp==0)cout<<"R",++cnt1;
				else if(tmp==1)cout<<"S",++cnt2;
				else cout<<"P",++cnt3;
			}
		}
		cout<<"\n";
	}
	
	return 0;
}