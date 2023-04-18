#include<bits/stdc++.h>
using namespace std;
class number{
public:
	number(int x,int y){
		int g=gcd(x,y);
		this->x=x/g,this->y=y/g;
		if(this->y<0){
			this->y*=-1;
			this->x*=-1;
		}
	}
	number operator + (const number &b)const{
		return number(x*b.y+y*b.x,y*b.y);
	}
	number operator - (const number &b)const{
		return number(x*b.y-y*b.x,y*b.y);
	}
	number operator * (const number &b)const{
		return number(x*b.x,y*b.y);
	}
	number operator / (const number &b)const{
		return number(x*b.y,y*b.x);
	}
	bool operator == (const number &b)const{
		return x==b.x&&y==b.y;
	}
	void print(){
		cout<<x;
		if(y>1)cout<<"/"<<y;
	}
private:
	int x,y;
	static int gcd(int a,int b){
		return b?gcd(b,a%b):a;
	}
	
};
int a[4],id[4];
int main() {
	cout<<(0x0F&0xED)<<1;
	return 0;
}
