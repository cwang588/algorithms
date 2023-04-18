#include<iostream>
#include<string>
using namespace std;
class Box
{
public:
	Box(int h,int w,int len):height(h),width(w),lenth(len){}
	int volume();
private:
	int height;
	int width;
	int lenth;
};

int Box::volume()
{
	int b = height * width*lenth;
	return(b);
}

int main()
{
	Box a[3] = { Box(10,12,15),Box(14,15,16),Box(9,16,14) };
	cout << "volume of Box1 is " << a[0].volume()<< endl;
	cout << "volume of Box1 is " << a[1].volume()<< endl;
	cout << "volume of Box1 is " << a[2].volume()<< endl;
	//system("pause");
	return 0;

}
