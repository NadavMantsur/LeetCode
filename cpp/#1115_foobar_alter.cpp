// 1115. Print FooBar Alternately

// The same instance of FooBar will be passed to two different threads:
// thread A will call foo(), while thread B will call bar().
// Modify the given program to output "foobar" n times.

#include <iostream>
#include <thread>
#include <functional>   //function
#include <mutex>                

using namespace std;

class FooBar
{
public:
    FooBar(int n)
    {
        this->n = n;
        barMtx.lock();
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; ++i)
        {
            fooMtx.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            barMtx.unlock();
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; ++i)
        {
            barMtx.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            fooMtx.unlock();
        }
    }

private:
    int n;
    mutex fooMtx;
    mutex barMtx;
};

void printFoo()
{
    cout << "foo";
}

void printBar()
{
    cout << "bar";
}

int main()
{
    int n = 5;
    FooBar fb(n);
    thread t1(&FooBar::foo, &fb, printFoo);
    thread t2(&FooBar::bar, &fb, printBar);
    t1.join();
    t2.join();
    cout << endl;
    return 0;
}