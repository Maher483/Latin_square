#include <iostream>
#include <set>
using namespace std;

const int MAX_SIZE = 10;

bool isValid(int square[MAX_SIZE][MAX_SIZE], int order, int row, int col, int num) {
    // Check if 'num' is not present in the current row and column
    for (int i = 0; i < order; ++i) {
        if (square[row][i] == num || square[i][col] == num) {
            return false;
        }
    }
    return true;
}

void solveLatinSquare(int square[MAX_SIZE][MAX_SIZE], int order, int row, int col) {
    if (row == order - 1 && col == order) {
        // Print the Latin square
        for (int i = 0; i < order; ++i) {
            for (int j = 0; j < order; ++j) {
                cout << square[i][j] << " ";
            }
            cout << std::endl;
        }
        cout << std::endl;
        return;
    }

    // Move to the next row if the current column is at the end
    if (col == order) {
        row++;
        col = 0;
    }

    for (int num = 1; num <= order; ++num) {
        if (isValid(square, order, row, col, num)) {
            square[row][col] = num;
            solveLatinSquare(square, order, row, col + 1);
            square[row][col] = 0;  // Backtrack
        }
    }
}

void generateLatinSquare(int order) {
    // Check for valid order
    if (order <= 0 || order > MAX_SIZE) {
        cout << "Invalid order\n";
        return;
    }

    // Initialize an empty square
    int latinSquare[MAX_SIZE][MAX_SIZE] = { 0 };

    // Start solving from the first cell
    solveLatinSquare(latinSquare, order, 0, 0);
}

void CheckLatinSquare(int** mat, int size)
{
     
    // Array of 'size' sets corresponding to each row.
    set<int>* rows = new set<int>[size];

    // Array of 'size' sets corresponding to each column.
    set<int>* cols = new set<int>[size];

    // Number of invalid elements
    int invalid = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            rows[i].insert(mat[i][j]);
            cols[j].insert(mat[i][j]);

            if (mat[i][j] > size || mat[i][j] <= 0)
            {
                invalid++;
            }
        }
    }

    // Number of rows with repetitive elements.
    int numrows = 0;

    // Number of columns with repetitive elements.
    int numcols = 0;

    // Checking size of every row and column
    for (int i = 0; i < size; i++)
    {
        if (rows[i].size() != static_cast<size_t>(size))
        {
            numrows++;
        }
        if (cols[i].size() != static_cast<size_t>(size))
        {
            numcols++;
        }
    }

    if (numcols == 0 && numrows == 0 && invalid == 0)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    // Free allocated memory
    delete[] rows;
    delete[] cols;
}

int main() {
    int ch;
    bool flage = true;
start:
    cout << "\t\t******** Welcome in Latin Squars Wrold ********\n";
    cout << "Select the opration you want:\n";
    cout << "1-Generate Latin Squares in Experimental Design \n";
    cout << "2-Cheak latin square validation\n";
    cin >> ch;
 switch (ch) {
    case 1: {
        while (flage == true) {
            system("cls");
            int numbers;
            char ch2;
            cout << "Enter the number of variabls:";
        start2:
            cin >> numbers;
            if (numbers >= 5)
            {
        warning:
                cout << "\t\tWARNING!!\n";
                cout << "It will be alot of possible latin squares are you sure to continue? Yes (y), No(n)\n";
                cin >> ch2;
                if (ch2 == 'n') {

                    system("cls");
                    cout << "Enter the number of variabls (if you want to exit enter '0'):";
                    cin >> numbers;
                    if (numbers == 0) {
                        flage = false;

                    }
                    else {
                        generateLatinSquare(numbers);
                        goto start;
                    }
                }
                else if (ch2 == 'y') {
                    system("cls");

                    generateLatinSquare(numbers);
                    goto start;

                }
                else {
                    cout << "Enter a valid number!!";
                    goto warning;
                }



            }//end of first if stat
            else if (numbers < 1) {
                cout << "Enter a valid number!!";
                goto start2;

            }
            else if (numbers < 5 && numbers >= 1)
            {
                system("cls");

                generateLatinSquare(numbers);
                goto start;
            }


        }//end of while loop
        break;
    }
    case 2: 
    {
        int size;
        cout << "Enter the size of the Latin square: ";
        cin >> size;
        int** Matrix = new int* [size];
        for (int i = 0; i < size; ++i) {
            Matrix[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                cout << "Enter element at position (" << i << ", " << j << "): ";
                cin >> Matrix[i][j];
            }
        }
        // Function call
        CheckLatinSquare(Matrix, size);
        // Free allocated memory
        for (int i = 0; i < size; ++i) {
            delete[] Matrix[i];
        }
        delete[] Matrix;
        goto start;
        break;
    }
    default: {
        if (ch > 2 && ch < 1) {
            cout << "Enter a valid number!!";
            goto start;
            break;
        }
    }

 }
    return 0;
}


