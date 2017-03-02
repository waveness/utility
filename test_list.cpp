#include <stdio.h>
#include <list>
#include <unistd.h>

using namespace std;

struct A{
        int a;
};
int main()
{
#if 0
    std::list< struct A> sa;
    struct A b;
    b.a = 10;
    sa.push_back(b);

    std::list< struct A >::iterator iter2;
    for(iter2 = sa.begin(); iter2 != sa.end(); iter2++){
       //printf("%d\n", (struct A)(*iter2).a);
       printf("%d\n", (*iter2).a);
    }
    return 0;
#else
    std::list< struct A*> sa;
    printf("before push null\n");
    sa.push_back(NULL);
    printf("after push null\n");
    sa.size();
    printf("after size %d\n", sa.size());
    while(1){
        int a;
        printf("%p\n", &a);
        sleep(1);
    }

    return 0;
#endif
}
