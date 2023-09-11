//ACC W5-Pro3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the modular inverse using the extended Euclidean algorithm
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
          }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to perform RSA encryption
int encrypt(int plaintext, int e, int n) {
    int ciphertext = 1;

    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }

    return ciphertext;
}

// Function to perform RSA decryption
int decrypt(int ciphertext, int d, int n) {
    int plaintext = 1;

    for (int i = 0; i < d; i++) {
        plaintext = (plaintext * ciphertext) % n;
    }

    return plaintext;
}

int main() {
    int p, q, n, phi, e, d, plaintext, ciphertext, decrypted_text;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        printf("Enter a value for e (1 < e < %d and gcd(e, %d) = 1): ", phi, phi);
        scanf("%d", &e);
    } while (e <= 1 || e >= phi || gcd(e, phi) != 1);

    // Calculate d as the modular inverse of e modulo phi
    d = mod_inverse(e, phi);

    printf("Public Key (n, e): (%d, %d)\n", n, e);
    printf("Private Key (d): %d\n", d);

    printf("Enter the plaintext to encrypt: ");
    scanf("%d", &plaintext);

    ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted Text: %d\n", ciphertext);

    decrypted_text = decrypt(ciphertext, d, n);
    printf("Decrypted Text: %d\n", decrypted_text);

    return 0;
}
