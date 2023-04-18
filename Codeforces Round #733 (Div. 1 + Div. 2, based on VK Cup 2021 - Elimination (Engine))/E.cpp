#include<bits/stdc++.h>
using namespace std;
int cnt[50];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		string s;
		cin>>s;
		for(int i=0;i<s.length();++i)++cnt[s[i]-'a'+1];
		int num=0,Min=2147483647,one=2147483647;
		for(int i=1;i<=26;++i){
			if(cnt[i]){
				++num;
				Min=min(Min,i);
			}
			if(cnt[i]==1)one=min(one,i);
		}
		if(num==1){
			cout<<s<<endl;
			continue;
		}
		if(one<2147483647){
			cout<<(char)(one+'a'-1);
			--cnt[one];
			for(int i=1;i<=26;++i){
				while(cnt[i]){
					cout<<(char)(i+'a'-1);
					--cnt[i];
				} 
			}
			cout<<endl;
		}
		else{
			if(2*(cnt[Min]-2)<=s.length()-2){
				for(int i=1;i<=2;++i){
					cout<<(char)(Min+'a'-1);
					--cnt[Min];
				}
				for(int i=1;i<=26;++i){
					if(i==Min)continue;
					while(cnt[i]){
						cout<<(char)(i+'a'-1);
						--cnt[i];
						if(cnt[Min]){
							--cnt[Min];
							cout<<(char)(Min+'a'-1);
						}
					}
				}
				cout<<endl;
			}
			else{
				cout<<(char)(Min+'a'-1);
				--cnt[Min];
				int sec=0,thr=0;
				for(int i=Min+1;i<=26;++i){
					if(cnt[i]){
						sec=i;
						break;
					}
				}
				for(int i=sec+1;i<=26;++i){
					if(cnt[i]){
						thr=i;
						break;
					}
				}
				if(!thr){
					while(cnt[sec]){
						cout<<(char)(sec+'a'-1);
						--cnt[sec];
					}
					while(cnt[Min]){
						cout<<(char)(Min+'a'-1);
						--cnt[Min];
					}
				}
				else{
					cout<<(char)(sec+'a'-1);
					--cnt[sec];
					while(cnt[Min]){
						cout<<(char)(Min+'a'-1);
						--cnt[Min];
					}
					cout<<(char)(thr+'a'-1);
					--cnt[thr];
					for(int i=1;i<=26;++i){
						while(cnt[i]){
							cout<<(char)(i+'a'-1);
							--cnt[i];
						} 
					}
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
