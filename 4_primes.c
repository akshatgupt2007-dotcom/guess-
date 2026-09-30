#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* Returns true if n is a prime number. */
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    int limit, count = 0;

    printf("Print all prime numbers up to: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter a number >= 2.\n");
        return 1;
    }

    printf("Primes up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nTotal primes found: %d\n", count);
    return 0;
}
