#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void show(int a[], int l, string text);

int main(int argc, string argv[])
{
    int numz[] = {6,5,7,8,2,9,3,1,4};
    int len = sizeof(numz) / sizeof(int);
    
    int temp;
    
    int decreaseLoop = 0;
    
    int swap = -1;
    
    if (len > 1)
    {
        while (swap != 0)
        {
            swap = 0;
            for (int i=0; i < len - 1 - decreaseLoop; i++)
            {
                if (numz[i] > numz[i + 1])
                {
                    temp = numz[i];
                    numz[i] = numz[i + 1];
                    numz[i + 1] = temp;
                    swap++;
                }
            }
            
            decreaseLoop++;
        }
    }
    else
    {
        printf("nothing to sort\n");
    }
   
   show(numz, len, "sorted: ");
}

void show(int a[], int l, string text)
{
    printf("%s", text);
    for (int j=0; j < l; j++)
    {
        printf("%d", a[j]);
    }
    
    printf("\n");
}