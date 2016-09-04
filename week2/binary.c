#include <stdio.h>
#include <cs50.h>


int main()
{
	
	
	//const int system = 2;
	
	int count, i, ncount, n;
	int bits[32];
	int d = 1;
	
	// length of the binary number
	count = 0;
	n = GetInt(); // in decimal 
	//system = GtInt(); // 
	
	do
	{
		d = d * 2;
		count++;
	}
	while (d*2 < n);
	ncount = count;

	// Flagging bits
	
	
	while (count != 0)
	{
		if (n / d > 0)
		{
			bits[count] = n / d;
			n = n % d;
			
		} 
		else
		{
			bits[count] = n / d;
		}
	
		d = d / 2;
		count--;
	}
	
	// printing binary number
	for (i = ncount; i >= 0; i-- )
	{
		printf("%d", bits[i]);
	}
	
	printf("\n");

}
