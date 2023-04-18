#include<bits/stdc++.h>
using namespace std;
vector<int>a,b;
int main(){
	int t;
	cin>>t;
	while(t--){
		a.clear();
		b.clear();
		int n,m;
		cin>>n>>m;
		long long tmp=m;
		if(n>m){
			cout<<"0"<<endl;
			continue;
		}
		while(n){
			a.push_back(n&1);
			n>>=1;
		}
		while(m){
			b.push_back(m&1);
			m>>=1;
		}
		long long ans=0,now=1;
		int pos=114514;
		bool ky=false;
		for(int i=a.size()-1;i>=0;--i){
			if(!b[i]&&a[i]){
				ky=true;
				pos=i;
				break;
			}
		}
		if(ky){
			for(int i=b.size()-1;i>=0;--i){
				ans=ans*2;
				if(i<pos)continue;
				if(b[i]&&(i>=a.size()||!a[i]))++ans;
			}
		}
		else{
			for(int i=0;i<b.size();++i){
				if(!b[i]){
					pos=i;
					break;
				}
			}
			if(pos==114514){
				ans=tmp+1;
			}
			else{
				for(int i=0;i<b.size();++i){
					if(i==pos){
						if(i>=a.size()||!a[i])ans+=now;
					}
					else if(i>pos){
						if(b[i]){
							if(i>=a.size()||!a[i])ans+=now;
						}
					}
					else;
					now=now*2;
				}
			}
		}
		cout<<ans<<endl;
	
	}
	
	return 0;
}
