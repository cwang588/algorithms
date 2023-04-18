#include<bits/stdc++.h>
using namespace std;
int cnt[15];
char s[400005];
void print(){
	for(int i=9;i>=1;--i){
		while(cnt[i]--)cout<<i;
	}
}
void print0(){
	while(cnt[0]--)cout<<"0";
}
int main(){
	cin>>s+1;
	int n=strlen(s+1),mo=0;
	for(int i=1;i<=n;++i){
		++cnt[s[i]-'0'];
		mo=(mo+s[i]-'0')%3;
	}
	if(mo)return !printf("-1\n");
	if(cnt[0]>=3){
		cnt[0]-=3;
		print();
		cout<<"000";
		print0();
		return 0;
	}
	if(cnt[1]&&cnt[2]&&cnt[5]){
		cnt[1]--;
		cnt[2]--;
		cnt[5]--;
		print();
		cout<<"125";
		print0();
		return 0;
	}
	if(cnt[2]&&cnt[5]&&cnt[0]){
		cnt[2]--;
		cnt[5]--;
		cnt[0]--;
		print();
		cout<<"250";
		print0();
		return 0;
	}
	if(cnt[3]&&cnt[7]&&cnt[5]){
		cnt[3]--;
		cnt[7]--;
		cnt[5]--;
		print();
		cout<<"375";
		print0();
		return 0;
	}
	if(cnt[5]&&cnt[0]>=2){
		cnt[0]-=2;
		cnt[5]--;
		print();
		cout<<"500";
		print0();
		return 0;
	}
	if(cnt[6]&&cnt[2]&&cnt[5]){
		cnt[6]--;
		cnt[2]--;
		cnt[5]--;
		print();
		cout<<"625";
		print0();	
		return 0;
	}
	if(cnt[7]&&cnt[5]&&cnt[0]){
		cnt[7]--;
		cnt[0]--;
		cnt[5]--;
		print();
		cout<<"750";
		print0();
		return 0;
	}
	if(cnt[8]&&cnt[7]&&cnt[5]){
		cnt[8]--;
		cnt[7]--;
		cnt[5]--;
		print();
		cout<<"875";
		print0();
		return 0;
	}
	cout<<"-1";
	return 0;
}