#include <iostream>
using namespace std;

class Base{
public:
  enum FatherEnum{
    TEST_ONE,
    TEST_TWO
  };

  enum CommonEnum{
    COMM_ONE,
    COMM_TWO
  };

  explicit Base(){
    priv_para = 100;
    std::cout << "in Base" << std::endl;
  }
  ~Base() {
    std::cout << "in Base ~" << std::endl;
  }
  virtual void method(){
    std::cout << "from base" << std::endl;
  }
  void baseMethod() {
    method();
  }
  int Init(int b){
    cout << "in Base Init() ~~" << std::endl;
  }
private:
  int priv_para;
};
class Child : public Base{
public:
  enum ClirdEnum{
    TEST_CHILD_ONE,
    TEST_CHILD_TWO
  };
  enum CommonEnum{
    COMM_ONE,
    COMM_TWO
  };

  Child(){
    std::cout << "in Child\n" << std::endl;
  }
  ~Child(){
    std::cout << "in Child ~\n" << std::endl;
  }
  void method(){
    // int a = priv_para; // can not access parent private member
    std::cout << "from Child" << std::endl;
  }
  int Init(int b){
    cout << "in Child Init() ~~" << std::endl;
  }
};


int main(void)
{
  Base *bb = new Child();
  bb->baseMethod();
  bb->Init(0);
  ((Child*)bb)->Init(1);
  ((Child*)bb)->baseMethod();
  cout << "Father ENUM TWO = " << Base::TEST_TWO << ", Child ENMU ONE = " << Child::TEST_CHILD_ONE <<
    ", Father COMM TWO = " << Base::COMM_TWO << ", Child COMM ONE = " << Child::COMM_TWO << std::endl;
  delete bb; // ~Base not virtual, will memory leak bacause ~Child not called
  //delete (Child*)bb; // work ok
  return 0;
}
