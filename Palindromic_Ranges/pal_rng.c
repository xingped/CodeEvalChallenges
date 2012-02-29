#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char* argv[])
{
	// Begin file initialization
	if(argc != 2)
	{
		printf("Invalid arguments.\n");
		printf("Proper usage: pal_rng inputfile\n");
		return(1);
	}
	
	FILE *fin = fopen(argv[1], "r");
	
	if(fin == NULL)
	{
		printf("Could not open input file %s\n", argv[1]);
		return(2);
	}
	// End file initialization
	
	int gvn_min, gvn_max;
	int rng_min, rng_max;
	char buffer[20];
	int i, pal_cnt, rng_cnt;
	
	while(!feof(fin))
	{
		fscanf(fin, "%d %d ", &gvn_min, &gvn_max);
		
		rng_cnt = 0;
		
		/*
		 * Main algorithm for stepping through number range.
		 * Runtime: (n^3 + 3n^2 + 2n)/6
		 */
		
		// Start with range minimums at the given minimum
		for(rng_min = gvn_min; rng_min <= gvn_max; rng_min++)
		{
			// Create each range's maximum as every number between
			// the range minimum and the given maximum
			for(rng_max = rng_min; rng_max <= gvn_max; rng_max++)
			{
				pal_cnt = 0;
				
				// Test every number between range min and range max
				for(i = rng_min; i <= rng_max; i++)
				{
					if(is_pal(itoa(i, buffer, 10)))
						pal_cnt++;
				}
				
				if(pal_cnt % 2 == 0)
					rng_cnt++;
			}
			
		}
		
		printf("%d\n", rng_cnt);
	}
	
	fclose(fin);
	
	return(0);
}