#include<bits/stdc++.h>
using namespace std;

class ringBuffer {
public:
	ringBuffer(int size)
	{
		++size;
		begin_=end_=0;
		array_=(int *)malloc(size*sizeof(int));
		size_=size;
	}

	~ringBuffer(){
		free(array_);
	}
	
	bool empty(){
		return begin_==end_;
	}
	bool full(){
		return (end_+1)%size_==begin_;
	}
	bool pop(int& value){
		if(empty())return false;
		value=array_[begin_];
		begin_=(begin_+1)%size_;
		return true;
	}
	bool push(int value){
		if(full())return false;
		array_[end_]=value;
		++end_;
		end_%=size_;
		return true;
	}
	int length(){
		return (end_-begin_+size_)%size_;
	}

private:
	int begin_;
	int end_;
	int size_;
	int* array_;
};
