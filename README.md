# IS2101 - Arithmetic Operations in C

This project contains three C programs implementing fundamental arithmetic algorithms:

1. **Sequential Multiplication** (`a_Sequential_Multiplication.c`)
2. **Restoring Division** (`b_Restoring_Division.c`)
3. **Non-Restoring Division** (`c_NonRestoring_Division.c`)

Each program demonstrates step-by-step binary arithmetic operations.

---

## 📂 Folder Structure

IS2101-ArithmeticOps-NNM24IS228/
│── a_Sequential_Multiplication.c
│── b_Restoring_Division.c
│── c_NonRestoring_Division.c
│── Output/
│ ├── SequentialMultiplication_output.png
│ ├── RestoringDivision_output.png
│ ├── NonRestoringDivision_output.jpeg
│── README.md

---

## ⚙️ Compilation & Execution

Use GCC to compile the programs.

### 1. Sequential Multiplication
```bash
gcc a_Sequential_Multiplication.c -o a_Sequential_Multiplication.exe
.\a_Sequential_Multiplication.exe

2. Restoring Division
gcc c_NonRestoring_Division.c -o c_NonRestoring_Division.exe
.\c_NonRestoring_Division.exe

3. Non Restoring Division
gcc c_NonRestoring_Division.c -o c_NonRestoring_Division.exe
.\c_NonRestoring_Division.exe

📥 Inputs & 📤 Outputs
1. Sequential Multiplication

Inputs: Multiplicand, Multiplier, Bit-size

Outputs: Step-by-step shift/add operations and final product
📸 Example:
![Sequential Multiplication Output](./Output/SequentialMultiplication_output.png)



2. Restoring Division

Inputs: Dividend, Divisor

Outputs: Step-by-step restoring division process, Quotient, Remainder

📸 Example:
![Restoring Division Output](./Output/RestoringDivision_output.png)


3. Non-Restoring Division

Inputs: Dividend, Divisor

Outputs: Step-by-step non-restoring division process, Quotient, Remainder

📸 Example:![Non-Restoring Division Output](./Output/NonRestoringDivision_output.jpeg)


✅ Sample Results

13 ÷ 3 (Non-Restoring Division) → Quotient = 4, Remainder = 1

73 ÷ 4 (Restoring Division) → Quotient = 18, Remainder = 1

12 × 2 (Sequential Multiplication) → Product = 24