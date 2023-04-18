#include<bits/stdc++.h>
using namespace std;
class A{
public:
	int a;
	virtual int getx()=0;
};
class B:A{
public:
	int b;
	int getx(){
		return b;
	}
};
int main(){
	B x;
	x.b=19260817;
	A y=x;
	cout<<y.getx()<<"\n";
	return 0;
}