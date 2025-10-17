/* File primes.c */

#include <stdio.h>
#include <stdlib.h>

/* Finds all prime numbers in a given range */

/* A number is prime if its only divisors are 1 and itself */

int main(int argc, char **argv)
{
	int minnum, maxnum, num, divisor, is_prime, count = 0;
	if (argc != 3) {
		printf("Usage: %s <minnum> <maxnum>\n", argv[0]);
		return 1;
	}
	minnum = atoi(argv[1]);
	maxnum = atoi(argv[2]);
	for (num = minnum ; num <= maxnum ; num++) {
		is_prime = 1;       // Consider num as prime
		if ((num != 2 && num % 2 == 0) || (num != 3 && num % 3 == 0)) {
			is_prime = 0;
		}
		else {
			for (divisor = 5 ; divisor * divisor <= num ; divisor += 6) {
				// Check for divisors up to the square root
				if (num % divisor == 0 || num % (divisor + 2) == 0) {
					is_prime = 0;   // num is not prime
					break;
				}
			}
		}
		if (is_prime == 1) {   // num is prime
//			printf("%d is prime\n", num);
			count++;
		}
	}
	printf("\nFound %d prime numbers\n", count);
	return 0;
}
