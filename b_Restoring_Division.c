#include <stdio.h>
#include <stdlib.h>

// Print binary with fixed number of bits
void printBinary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Restoring Division Algorithm (positive integers only)
void restoringDivision(int dividend, int divisor, int bitSize) {
    int A = 0;          // Remainder register
    int Q = dividend;   // Dividend register (will hold quotient)
    int M = divisor;    // Divisor
    int count = bitSize;

    printf("\nInitial State:\n");
    printf("A = "); printBinary(A, bitSize);
    printf("  Q = "); printBinary(Q, bitSize);
    printf("  M = "); printBinary(M, bitSize);
    printf("\n\n");

    while (count > 0) {
        // Left shift (A,Q)
        int combined = (A << bitSize) | Q;
        combined <<= 1;
        A = (combined >> bitSize) & ((1 << bitSize) - 1);
        Q = combined & ((1 << bitSize) - 1);

        // Subtract divisor
        A = A - M;

        if (A < 0) {
            // Restore A, set Q0 = 0
            A = A + M;
            Q = Q & (~1);
        } else {
            // Set Q0 = 1
            Q = Q | 1;
        }
        count--;
    }

    int quotient = Q;
    int remainder = A;

    printf("Final Quotient (Decimal): %d\n", quotient);
    printf("Final Quotient (Binary) : "); printBinary(quotient, bitSize); printf("\n");

    printf("Final Remainder (Decimal): %d\n", remainder);
    printf("Final Remainder (Binary) : "); printBinary(remainder, bitSize); printf("\n");
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

    restoringDivision(dividend, divisor, 8); // using 8-bit
    return 0;
}
