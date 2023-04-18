#include <iostream>
#include <utility>
#include <vector>

template<typename... Args>
class MyTuple;

template<>
class MyTuple<> {
public:
    virtual void print() {};
};

template<typename T, typename... Args>
class MyTuple<T, Args...> : public MyTuple<Args...> {
public:
    explicit MyTuple(T t, Args... args) : MyTuple<Args...>(args...), element(std::move(t)) {};

    void print() override {
        std::cout << element << " ";
        MyTuple<Args...>::print();
    }

private:
    T element;
};

class stigmata {
private:
    static int id_cnt;
public:
    static int getId() {
        return id_cnt;
    }

public:
    int id;
    int value;

    explicit stigmata(int value) {
        id = stigmata::id_cnt++;
        this->value = value;
    }

    stigmata(const stigmata &other) {
        this->id = other.id;
        this->value = other.value;
    }

    stigmata(stigmata &&other) noexcept {
        this->value = other.value;
        this->id = other.id;
    }
};

int stigmata::id_cnt = 0;

template<typename a, typename b>
class MyPair {
private:
    a first;
    b second;
public:
    MyPair<a, b> make_pair(a x, b y) {
        first = x;
        second = y;
    }
};

void foo(int *b, int a, char *c) {
    if (a != 1) {
        printf("%d%s\n", 10/ *b,c);
        foo(b,a-1,",\\*^_^*/,");
    }else{
        printf("%d\n",c[0]);
    }
}
int main() {
//    auto test = MyTuple<int, char, double, std::string>(1, 'c', 2.0, "bkx");
//    test.print();
//    auto t1=stigmata(2);
//    auto t2=stigmata(std::move(t1));
//    std::cout<<t1.value<<" "<<t2.value<<"\n";
//    std::cout<<t1.id<<" "<<t2.id<<"\n";
//    std::vector<MyTuple<double, std::string, int, char, bool> > test;
//    test.emplace_back(1.0,"bkx",114514,'k',false);
//    test[0].print();
//    int** x = new int*[4];
//    for(int i=0;i<3;++i){
//        x[i]=new int[3];
//    }
    int a=2;
    foo(&a,a," unit");
    a--;
    foo(&a,a," unit");
    return 0;
}
