#include <iostream>
#include <memory>
#include <list>
#include <array>

typedef struct{
    int size;
    char* ptr;
}HImg;

using namespace std;
std::array< shared_ptr<HImg>,4 > imagelist;

/*
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
*/

int main() 
{
    shared_ptr<HImg> img1( make_shared<HImg>() );
    shared_ptr<HImg> img2( make_shared<HImg>() );

    printf("img1 use_count=%d\n", img1.use_count());
    std::array< shared_ptr<HImg>,4 >::iterator iter;
    for(iter=imagelist.begin(); iter != imagelist.end(); iter++){
        printf("loop\n");
        *iter = img1;
    }

  //  test_push_reference(img1);

  //  test_pop_reference(img1);
  //  
    /*
     * for(auto iter2: imagelist){
        printf("loop2\n");
        int size = (*iter2)->size;
        printf("loop3\n");
        printf("use count=%d\n", iter2->use_count());
    }*/
    std::array< std::shared_ptr<HImg>, 4 >::iterator iter2;
    for(iter2 = imagelist.begin(); iter2 != imagelist.end(); iter2++){
        printf("loop2\n");
        int size = (*iter2)->size;                                                                                                                                                            
        printf("loop3\n");                                                                                                                                                                    
        printf("use count=%d\n", iter2->use_count());
    }

    return 0;
    
}
