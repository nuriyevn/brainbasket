/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <math.h>
#define true 1
#define false 0

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n )
{
     
     // TODO: implement a searching algorithm (linear)
//     for (int i = 0 ;i < n; i++)
  //   {
    //  if (values[i]==value)
     // {
     // return true;
    //  break ;
    //  }
//     }
     int middle_point = n / 2 ;
 if (values[middle_point]== value)
    {
        return true;
    }    
    while(values[middle_point] != value)
    {
        if (values[middle_point] < value)
        {
            middle_point = middle_point / 2  ; 
        }
        else if ( values[middle_point] > value)
        {
            middle_point = middle_point * 1.5 ;
        }
    }
 
    return false;
    
    
    //binary search 
     
    
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
       
        for (int i = 0; i < n; i++) 
        {
         for (int j = 0; j < n-1; j++) 
         {
             int temp = values[j+1];

				values[j+1] = values[j];

				values[j] = temp;
             }
         }
         
    return;
    
}