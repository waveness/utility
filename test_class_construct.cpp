#include <iostream>
#include <stdio.h>
using namespace std;

class Base{
    virtual void method(){std::cout << "from base" << std::endl;
		printf("=====\n");}

public:
    Base(){method();}
    virtual ~Base() {method();}
    void baseMethod() {method();}
};

int main()
{
    Base *bb = new Base();
    bb->baseMethod();
    delete bb; //important
    return 0;
}
