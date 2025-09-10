#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to print binary with fixed bits
void printBinary(int num, int bits) {
    unsigned mask = 1u << (bits - 1);
    for (int i = 0; i < bits; i++) {
        printf("%d", (num & mask) ? 1 : 0);
        mask >>= 1;
    }
}

// Non-Restoring Division Algorithm (positive integers only)
void nonRestoringDivision(int dividend, int divisor) {
    // Calculate number of bits needed
    int bits = (int)floor(log2(dividend)) + 2;  // +1 for safety
    int A = 0;          // Accumulator (remainder)
    int Q = dividend;   // Dividend (will hold quotient)
    int M = divisor;    // Divisor
    int n = bits;

    printf("\n[Using %d bits]\n", n);
    printf("Initial State:\n");
    printf("A = "); printBinary(A, n + 1);
    printf("   Q = "); printBinary(Q, n);
    printf("   M = "); printBinary(M, n);
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        printf("Step %d:\n", i + 1);

        // Left shift (A,Q)
        A = (A << 1) | ((Q >> (n - 1)) & 1);
        Q = (Q << 1) & ((1 << n) - 1);

        printf(" After shift:   A = "); printBinary(A, n + 1);
        printf("   Q = "); printBinary(Q, n); printf("\n");

        // If A >= 0 → A = A - M, else A = A + M
        if (A >= 0) {
            A = A - M;
            if (A >= 0) Q |= 1;  // Set LSB of Q = 1
            printf(" A >= 0 → A = A - M\n");
        } else {
            A = A + M;
            if (A >= 0) Q |= 1;  // Set LSB of Q = 1
            printf(" A < 0  → A = A + M\n");
        }

        printf(" After op:      A = "); printBinary(A, n + 1);
        printf("   Q = "); printBinary(Q, n); printf("\n\n");
    }

    // Final correction if A < 0
    if (A < 0) {
        A = A + M;
    }

    printf("Final Quotient  Q = "); printBinary(Q, n); printf(" (%d)\n", Q);
    printf("Final Remainder A = "); printBinary(A, n + 1); printf(" (%d)\n", A);
}

int main() {
    int dividend, divisor;
    printf("Enter Dividend: ");
    scanf("%d", &dividend);
    printf("Enter Divisor : ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Error: Division by zero not allowed.\n");
        return 1;
    }
    if (dividend < 0 || divisor < 0) {
        printf("Error: Only positive integers supported.\n");
        return 1;
    }

    nonRestoringDivision(dividend, divisor);
    return 0;
}
