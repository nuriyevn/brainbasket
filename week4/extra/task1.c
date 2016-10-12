#include <stdio.h>

#include "hello.h"
#include "sum.h"

int main()
{
    hello();
    
    int result;
    int x, y;
    printf("enter the first number\n");
    scanf("%d", &x);
    
    printf("enter the second number\n");
    scanf("%d", &y);
    
    result = sum(x, y);
    
    printf("sum = %d\n", result);
    
    return 0;
}