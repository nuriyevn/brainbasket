// quarter : 25c , dime: 10c , nickel:5c , penny: 1c
#import <stdio.h>
#import <cs50.h>
#import <math.h>

int main (void)
{
    
    printf ("How much i owe you ?\n");
    float f;
    float x; 
    float a,b,c,d,q,g,p;
    float m;
    float h,y,u;
     int get, get1, get2,get3, firstsum , secondsum , thirdsum; 
   a=0.25;
   b=0.1;
   c=0.05;
   d=0.01;
do 
{
 f=GetFloat() ;
} while (f<0.0) ;
float roundf (float f);
// do round 
 for (int j = 0; j <=f*4  ; j++)
 {
      y = a*j;
     x= f - y ;
     if (x<0.25)
     {
         break ;
     }
 }
 if (x==0.0)
 {
   get = y/a;
  printf("%d\n",get);
 }
 else if (x>0.0 && x<0.25)
 {
 for (int i =0 ; i<=f*10; i++)
    {
 
     u = b*i ;
     m = x - u ;
     if (m<0.1)
 {
     break;
 }
    
     
    }
 if (m==0.0)
 {
   get1 = u/b ;
  firstsum = y/a+get1;
  printf("%d\n",firstsum);
 }
 else if (m>0.0)
 {
 for (int k=0 ; k<=f*20;k++)
 {
      g = c*k;
      h = m - g;
     if (h<0.05)
     {
         break;
     }
     
 }
  if (h==0.0)
  {
   get2=g/c ;
    secondsum = y/a+u/b + get2 ;
  printf ("%d\n", secondsum) ;
  }
  
  else if (h>0.0)
  {
  for (int l=0; l<=f*100;l++)
  {
       p = d*l; 
       q = h-p ;
       if(q<=0.0)
      {
          get3=p/d;
            thirdsum = y/a+u/b+g/c+get3;
          printf("%d\n",thirdsum);
          break;
      }
      
  }   
  }
 }
}
}
