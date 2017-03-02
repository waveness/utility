#include <stdio.h>

#define MAX_SIZE 100

typedef struct{
    int key;
    int value;
}acc;

acc* find_inhalf(acc* bufarry, int num, int wantkey){
    int low=1;
    int high = num;
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(mid == low){
            if(bufarry[mid].key == wantkey)
                return &bufarry[mid];
            if(bufarry[mid-1].key <= wantkey && bufarry[mid].key > wantkey)
                return &bufarry[mid-1];
            return NULL;
        }
        if(bufarry[mid-1].key > wantkey){
            high = mid;
        }else if(bufarry[mid-1].key < wantkey){
            low = mid;
        }else{
            return &bufarry[mid-1];
        }
    }
    return NULL;
}

int main(){
    acc buf[MAX_SIZE];
    for(int i=0; i<MAX_SIZE; i++){
        buf[i].key=i+1;
        buf[i].value=i;
    }
    int want = 1.5;
    acc* pdata = find_inhalf(buf, MAX_SIZE, want);
    if(pdata){
        printf("find one key=%d, vale=%d\n", pdata->key, pdata->value);
    }else{
        printf("do not find");
    }
    return 0;
}
