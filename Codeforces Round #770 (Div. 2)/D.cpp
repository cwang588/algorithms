#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int now=0,pos;
		set<int>s;
		for(int i=3;i<=n;++i){
			cout<<"? 1 2 "<<i<<"\n";
			fflush(stdout);
			int tmp;
			cin>>tmp;
			s.insert(tmp);
			if(tmp>=now){
				now=tmp;
				pos=i;
			}
		}
		bool ky=false;
		if(s.size()==1){
			int ans1,ans2;
			cout<<"? 1 3 4\n";
			fflush(stdout);
			cin>>ans1;
			cout<<"? 2 3 4\n";
			fflush(stdout);
			cin>>ans2;
			int Max=*s.begin();
			if(ans1<Max&&ans2<Max){
				cout<<"! 1 2\n";
				fflush(stdout);
				continue;
			}
			ky=true;
		}
		s.clear();
		now=0;
		int poss,ind=1;		
//		if(ky)pos=3;
		for(int i=1;i<=n;++i){
			if(i!=pos&&i!=ind){
				cout<<"? "<<ind<<" "<<pos<<" "<<i<<"\n";
				fflush(stdout);
				int tmp;
				cin>>tmp;
				s.insert(tmp);
				if(tmp>=now){
					now=tmp;
					poss=i;
				}
			}
		}
		if(s.size()==1){
			cout<<"! "<<ind<<" "<<pos<<"\n";
			fflush(stdout);
		}
		else{
			cout<<"! "<<pos<<" "<<poss<<"\n";
			fflush(stdout);
		}
	}
	
	
	return 0;
}