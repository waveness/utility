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


class Base{ 
public: 
  Base(){ 
    std::cout << "in Base" << std::endl; 
  } 
  virtual ~Base() { 
    std::cout << "in Base ~" << std::endl; 
  } 
  virtual void method(){ 
    std::cout << "from base" << std::endl; 
  } 
  void baseMethod() { 
    method(); 
  } 
}; 
class Child : public Base{ 
public:
  Child(){
    std::cout << "in Child\n" << std::endl;
  }
  ~Child(){ 
    std::cout << "in Child ~\n" << std::endl; 
  }
  void method(){ 
    std::cout << "from Child" << std::endl; 
  }
};


int main(void)
{  
#if 0
    A *a = new B();
    a->foo();   // �����a��Ȼ��ָ��A��ָ�룬���Ǳ����õĺ���(foo)ȴ��B��! 
    a->normal_fun();
    ((B*)a)->normal_fun();
    return 0;
#else
    Base *bb = new Child(); 
    bb->baseMethod(); 
    delete bb; 
    return 0; 
#endif
}  
