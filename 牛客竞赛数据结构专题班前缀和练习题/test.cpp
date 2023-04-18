#include<iostream>
using namespace std;
class A{
	public:
		void test(){
			func1();
		}
		virtual void func1(int a=1){
			cout<<"A"<<a<<"\n";
		}
};
class B:public A{
	public:
		void func1(int a=2){
			cout<<"B"<<a<<"\n";
		}
};
int main(){
	B *p=new B;
	p->test();
	return 0;
}