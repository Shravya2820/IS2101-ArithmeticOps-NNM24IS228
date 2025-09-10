#include <stdio.h>
#include <stdint.h>

// Convert n-bit two's complement binary to signed int
int toSigned(int val, int bits) {
    int mask = 1 << (bits - 1);
    return (val & mask) ? val - (1 << bits) : val;
}

// Print n-bit binary
void printBin(int val, int bits) {
    for (int i = bits - 1; i >= 0; i--)
        putchar((val >> i) & 1 ? '1' : '0');
}

int main() {
    int M, Q, n;
    printf("Enter multiplicand: "); scanf("%d", &M);
    printf("Enter multiplier  : "); scanf("%d", &Q);
    printf("Enter bit-size n  : "); scanf("%d", &n);

    int mask = (1 << n) - 1;
    int A = 0, count = n;

    // mask into n bits (two's complement form)
    M &= mask;
    Q &= mask;

    printf("\nInitial: A="); printBin(A, n);
    printf(" Q="); printBin(Q, n); printf("\n");

    while (count--) {
        if (Q & 1) {
            A = (A + M) & mask;
            printf("Add M -> A="); printBin(A, n); printf("\n");
        }
        // shift (A,Q) pair
        int newQ = (Q >> 1) | ((A & 1) << (n - 1));
        int sign = (A >> (n - 1)) & 1;
        A = (A >> 1) | (sign << (n - 1));
        Q = newQ & mask;

        printf("Shift  -> A="); printBin(A, n);
        printf(" Q="); printBin(Q, n); printf("\n");
    }

    int result = ((A << n) | Q);
    int signedRes = toSigned(result, 2 * n);

    printf("\nFinal Product = %d\n", signedRes);
    return 0;
}
