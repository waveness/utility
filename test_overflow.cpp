#include <iostream>
#include <stdio.h>

void upper_overflow(){
  unsigned char un_max = 0xFF;
  char n_max = 0x7F;
  printf("signed int8 max value: %d\n", n_max);
  printf("unsigned uint8 max value: %d\n", un_max);
  printf("after +1 :\n");
  n_max += 1;
  un_max += 1;
  printf("n_max value: %d\n", n_max);
  printf("un_max value: %d\n", un_max);
}
void down_overflow(){
  unsigned char un_val = 0x0;
  char n_val = 0x0;
  printf("n_val value: %d\n", n_val);
  printf("un_val value: %d\n", un_val);
  printf("after -1 :\n");
  n_val -= 1;
  un_val -= 1;
  printf("n_val value: %d\n", n_val);
  printf("un_val value: %d\n", un_val);
}

void test_default_overflow(){
    std::cout << 0u-2u;
    printf("===>0x%x\n", 10u-20u);
}
int main()
{
    upper_overflow();
    down_overflow();
    return 0;
}
