#include <iostream>
#include <memory>
#include <list>

typedef struct{
    int size;
    char* ptr;
}HImg;

using namespace std;
std::list< shared_ptr<HImg> > imagelist;

void test_push_reference(shared_ptr<HImg>& sp){
    printf("before push: use_count=%d\n", sp.use_count());
    imagelist.push_back(sp);
    printf("after push: use_count=%d\n", sp.use_count());
}

void test_pop_reference(shared_ptr<HImg>& data){
    shared_ptr<HImg> sp = imagelist.front();
    printf("after front, use cont=%d\n", sp.use_count()); 
//    imagelist.pop_front();
  //  printf("after pop front, use count = %d\n", sp.use_count());  
   // sp.reset();
    sp = nullptr;
    printf("[%d]after reset front, use count = %d\n", sp == nullptr, sp.use_count());  
}

int main() 
{
    shared_ptr<HImg> img1( make_shared<HImg>() );
    shared_ptr<HImg> img2( make_shared<HImg>() );

    printf("img1 use_count=%d\n", img1.use_count());

    test_push_reference(img1);

    test_pop_reference(img1);

    printf("222:img1 use_count=%d\n", img1.use_count());

    printf("before clear : size = %d\n", imagelist.size());
    imagelist.clear();
    printf("after clear : size = %d\n", imagelist.size());

    return 0;
    
}
