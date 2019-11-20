#include <stdio.h>
#include <stdint.h>

//typedef struct __attribute((packed))  A {
typedef struct  A {
    uint32_t var1;
    uint32_t var2;
    uint32_t var3;
    uint32_t var4;
    uint32_t var5;
} A ;


//typedef struct __attribute__((packed)) B {
typedef struct B {
    uint32_t var1;
    uint32_t var2;
    uint32_t var3;
    uint64_t var4;
} B;


int main()
{
    printf("sizeof(A): {%ld} \n", sizeof(A));
    printf("sizeof(b): {%ld} \n", sizeof(B));

    return 0;
}
