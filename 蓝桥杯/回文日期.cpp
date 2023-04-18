#include<bits/stdc++.h>
using namespace std;
vector<int>hw,nbhw;
int rev(int x){
	string tmp=to_string(x);
	reverse(tmp.begin(),tmp.end());
	return atoi(tmp.c_str());
}
bool check(int x){
	int now=rev(x),month=now/100,day=now%100;
	if(month==0||month>12||day==0||day>31)return false;
	if(month==2){
		if(x%100==0){
			if(x%400==0)return day<=29;
			else return day<=28;
		}
		else{
			if(x%4==0)return day<=29;
			else return day<=28;
		}
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)return day<=30;
	else return day<=31;
}
bool checknb(int x){
	int now=rev(x);
	return now/100==now%100;
}
void init(){
	for(int i=1000;i<=9999;++i){
		if(check(i)){
			hw.push_back(i*10000+rev(i));
			if(checknb(i))nbhw.push_back(i*10000+rev(i));
		}
	}
}
int main(){
	init();
	int n;
	cin>>n;
	cout<<*upper_bound(hw.begin(),hw.end(),n)<<"\n"<<*upper_bound(nbhw.begin(),nbhw.end(),n);
	
	return 0;
}