#include <chrono>
#include <iostream>
#include <memory>

// compiler cmder
// g++ -O3 -std=c++11 test_sharedptr_timecost.cpp -o test_sharedptr_o3
static const long long numInt= 10000000;

int test_1() {
  for ( long long i=0 ; i < numInt; ++i){
    int* tmp(new int(i));
    delete tmp;
  }
  return 0;
}
int test_2() {
  for ( long long i=0 ; i < numInt; ++i){
    std::shared_ptr<int> tmp(new int(i));
  }
  return 0;
}
int test_3() {
  for ( long long i=0 ; i < numInt; ++i){
    std::shared_ptr<int> tmp(std::make_shared<int>(i));
  }
  return 0;
}
int test_4() {
  for ( long long i=0 ; i < numInt; ++i){
    std::unique_ptr<int> tmp(new int(i));
  }
  return 0;
}
#if 0
// need support c++14
int test_5() {
  for ( long long i=0 ; i < numInt; ++i){
    std::unique_ptr<int> tmp(std::make_unique<int>(i));
  }
  return 0;
}
#endif
int main() {
  auto start = std::chrono::system_clock::now();
  test_1();
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "test_1 time native: " << dur.count() << " seconds" << std::endl;

  start = std::chrono::system_clock::now();
  test_2();
  dur= std::chrono::system_clock::now() - start;
  std::cout << "test_2 time native: " << dur.count() << " seconds" << std::endl;

  start = std::chrono::system_clock::now();
  test_3();
  dur= std::chrono::system_clock::now() - start;
  std::cout << "test_3 time native: " << dur.count() << " seconds" << std::endl;

  start = std::chrono::system_clock::now();
  test_4();
  dur= std::chrono::system_clock::now() - start;
  std::cout << "test_4 time native: " << dur.count() << " seconds" << std::endl;

  return 0;
}
