//ACC Week 5 pro1
//1st program

#include <stdio.h>

long long fast_exponentiation(long long base, long long exponent, long long modulus) {
    long long result = 1;

    while (exponent > 0) {
        // If the current exponent bit is 1, multiply the result by the base modulo modulus
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        // Square the base and reduce modulo modulus
        base = (base * base) % modulus;

        // Divide the exponent by 2
        exponent /= 2;
    }

    return result;
}

int main() {
    long long base, exponent, modulus, result;

    printf("Enter base: ");
    scanf("%lld", &base);

    printf("Enter exponent: ");
    scanf("%lld", &exponent);

    printf("Enter modulus: ");
    scanf("%lld", &modulus);

    // Calculate base^exponent mod modulus using fast exponentiation
    result = fast_exponentiation(base, exponent, modulus);

    printf("Result: %lld\n", result);

    return 0;
}
