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

static shared_ptr<HImg> g_sharedPtr;
void test_global_reference(void){

    g_sharedPtr = shared_ptr<HImg>( make_shared<HImg>() );
}
int main()
{
    shared_ptr<HImg> img1( make_shared<HImg>() );
    shared_ptr<HImg> img2( make_shared<HImg>() );
    g_sharedPtr = shared_ptr<HImg>( make_shared<HImg>() );

    printf("img1 use_count=%d\n", img1.use_count());
    printf("global shared ptr use_count=%d\n", g_sharedPtr.use_count());

    test_push_reference(img1);

    test_pop_reference(img1);

    printf("222:img1 use_count=%d\n", img1.use_count());

    printf("before clear : size = %d\n", imagelist.size());
    imagelist.clear();
    printf("after clear : size = %d\n", imagelist.size());

    test_global_reference();

    printf("global shared ptr use_count=%d\n", g_sharedPtr.use_count());

    if(g_sharedPtr != NULL)
      printf("before release global shared ptr use_count=%d\n", g_sharedPtr.use_count());
      g_sharedPtr.reset();
      printf("after global shared ptr use_count=%d\n", g_sharedPtr.use_count());

    if(g_sharedPtr == NULL){
      printf("after release global shared ptr use_count=%d\n", g_sharedPtr.use_count());
    }
    return 0;

}
