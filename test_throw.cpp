#include <iostream>

class A{
public:
    A(){};
    ~A(){throw "abc";}
};

int test()
{
try{
   A a;
   }catch(char* a){ 
        std::cout << a;
   }   

}

int main(int argc, char *argv[])
{
    try{
        test();
   throw "def";
    }catch(char * b)
    {
        std::cout << b;
    }
}

