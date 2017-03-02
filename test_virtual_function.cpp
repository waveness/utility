#include <iostream>
using namespace std;

class A  
{  
public:  
    virtual void foo()  
    {  
        cout<<"A::foo() is called"<<endl;  
    } 
    void normal_fun(){
        cout<<"A::normal_fun() is called"<<endl;
    }    
};  
class B:public A  
{  
    public:  
        void foo()  
        {  
            cout<<"B::foo() is called"<<endl;  
        }  
        void normal_fun(){
            cout<<"B::normal_fun() is called"<<endl;
        }
};  
int main(void)  
{  
    A *a = new B();
    a->foo();   // �����a��Ȼ��ָ��A��ָ�룬���Ǳ����õĺ���(foo)ȴ��B��! 
    a->normal_fun();
    ((B*)a)->normal_fun();
    return 0;  
}  
