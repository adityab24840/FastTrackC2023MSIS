#include <stdio.h>

// Function to sort an array in ascending order
void sort_array_ascending(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// Function to sort an array in descending order
void sort_array_descending(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// Function to print an array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find minimum and maximum elements in an array
void find_max_min(int array[], int size, int *max, int *min) {
    *max = *min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > *max)
            *max = array[i];
        if (array[i] < *min)
            *min = array[i];
    }
}

// Function for set union
void set_union(int A[], int B[], int sizeA, int sizeB) {
    printf("A union B: ");
    // Print elements of set A
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", A[i]);
    }
    // Print elements of set B that are not in set A
    for (int i = 0; i < sizeB; i++) {
        int isCommon = 0;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                isCommon = 1;
                break;
            }
        }
        if (!isCommon) {
            printf("%d ", B[i]);
        }
    }
    printf("\n");
}

// Function for set intersection
void set_intersection(int A[], int B[], int sizeA, int sizeB) {
    printf("A intersection B: ");
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                break;
            }
        }
    }
    printf("\n");
}

// Function for set difference
void set_difference(int A[], int B[], int sizeA, int sizeB) {
    printf("A - B: ");
    for (int i = 0; i < sizeA; i++) {
        int isDifferent = 1;
        for (int j = 0; j < sizeB; j++) {
            if (A[i] == B[j]) {
                isDifferent = 0;
                break;
            }
        }
        if (isDifferent) {
            printf("%d ", A[i]);
        }
    }
    printf("\n");

    printf("B - A: ");
    for (int i = 0; i < sizeB; i++) {
        int isDifferent = 1;
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                isDifferent = 0;
                break;
            }
        }
        if (isDifferent) {
            printf("%d ", B[i]);
        }
    }
    printf("\n");
}

// Function to remove duplicate entries in an array
int remove_duplicates(int array[], int size) {
    int newSize = 1;
    for (int i = 1; i < size; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < newSize; j++) {
            if (array[i] == array[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            array[newSize] = array[i];
            newSize++;
        }
    }
    return newSize;
}

// Function for linear search
int linear_search(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}

// Function for binary search
int binary_search(int array[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

// Function to find sum of product of consecutive numbers
int sum_of_product(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size - 1; i++) {
        sum += array[i] * array[i + 1];
    }
    return sum;
}

// Function to reverse a string
void reverse_string(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// Function to check if a string is palindrome
int is_palindrome(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to concatenate two strings
void concatenate_strings(char str1[], char str2[]) {
    int length1 = 0, length2 = 0;
    while (str1[length1] != '\0') {
        length1++;
    }
    while (str2[length2] != '\0') {
        length2++;
    }

    for (int i = 0; i < length2; i++) {
        str1[length1 + i] = str2[i];
    }
    str1[length1 + length2] = '\0';
}

// Function to construct and display a matrix
void construct_matrix(int matrix[][5], int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int matrix[][5], int rows, int cols) {
    printf("Matrix contents:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find transpose of a matrix
void transpose_matrix(int matrix[][5], int rows, int cols, int result[][5]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to find sum of each column in a matrix
void sum_of_columns(int matrix[][5], int rows, int cols, int sum[]) {
    for (int j = 0; j < cols; j++) {
        sum[j] = 0;
        for (int i = 0; i < rows; i++) {
            sum[j] += matrix[i][j];
        }
    }
}

// Function to check if a matrix is sparse
int is_sparse(int matrix[][5], int rows, int cols) {
    int zeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    return (zeroCount > (rows * cols) / 2);
}


int main() {
    int choice;

    do {
        printf("\n-----------------------------\n");
        printf("1. Sort Array\n");
        printf("2. Swap Numbers\n");
        printf("3. Find Min/Max in Array\n");
        printf("4. Set Operations\n");
        printf("5. Remove Duplicates from Array\n");
        printf("6. Linear Search\n");
        printf("7. Binary Search\n");
        printf("8. Sum of Product of Consecutive Numbers\n");
        printf("9. Find Length of String\n");
        printf("10. Format Date\n");
        printf("11. Convert to Uppercase\n");
        printf("12. Reverse String\n");
        printf("13. Check Palindrome\n");
        printf("14. Concatenate Strings\n");
        printf("15. Construct and Display Matrix\n");
        printf("16. Transpose Matrix\n");
        printf("17. Sum of Each Column in Matrix\n");
        printf("18. Check Sparse Matrix\n");
        printf("0. Exit\n");
        printf("-----------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Sort Array
                int n;
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                int arr[n];
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                sort_array_ascending(arr, n);
                printf("Sorted Array (Ascending): ");
                print_array(arr, n);

                sort_array_descending(arr, n);
                printf("Sorted Array (Descending): ");
                print_array(arr, n);
                break;
            }
            case 2: {
                // Swap Numbers
                int num1, num2;
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
                swap(&num1, &num2);
                printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
                break;
            }
            case 3: {
                // Find Min/Max in Array
                int n;
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                int arr[n];
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                int min, max;
                find_max_min(arr, n, &max, &min);
                printf("Maximum: %d, Minimum: %d\n", max, min);
                break;
            }
            case 4: {
                // Set Operations
                int sizeA, sizeB;
                printf("Enter the number of elements for set A: ");
                scanf("%d", &sizeA);
                int setA[sizeA];
                printf("Enter elements for set A:\n");
                for (int i = 0; i < sizeA; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &setA[i]);
                }

                printf("Enter the number of elements for set B: ");
                scanf("%d", &sizeB);
                int setB[sizeB];
                printf("Enter elements for set B:\n");
                for (int i = 0; i < sizeB; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &setB[i]);
                }

                printf("Set A: ");
                print_array(setA, sizeA);
                printf("Set B: ");
                print_array(setB, sizeB);

                printf("A union B: ");
                set_union(setA, setB, sizeA, sizeB);
                printf("\n");

                printf("A intersection B: ");
                set_intersection(setA, setB, sizeA, sizeB);
                printf("\n");

                printf("A - B: ");
                set_difference(setA, setB, sizeA, sizeB);
                printf("\n");

                printf("B - A: ");
                set_difference(setB, setA, sizeB, sizeA);
                printf("\n");
                break;
            }
            case 5: {
                // Remove Duplicates from Array
                int n;
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                int arr[n];
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                int newSize = remove_duplicates(arr, n);
                printf("Array with duplicates removed: ");
                print_array(arr, newSize);
                break;
            }
            case 6: {
                // Linear Search
                int n;
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                int arr[n];
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                int target;
                printf("Enter the element to search: ");
                scanf("%d", &target);
                int index = linear_search(arr, n, target);
                if (index != -1) {
                    printf("%d found at index %d\n", target, index);
                } else {
                    printf("%d not found\n", target);
                }
                break;
            }
                  case 7: {
                // Binary Search
                int size;
                printf("Enter the number of elements (must be sorted): ");
                scanf("%d", &size);
                int sortedArr[size];
                printf("Enter sorted elements:\n");
                for (int i = 0; i < size; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &sortedArr[i]);
                }
                int target;
                printf("Enter the element to search: ");
                scanf("%d", &target);
                int index = binary_search(sortedArr, size, target);
                if (index != -1) {
                    printf("%d found at index %d\n", target, index);
                } else {
                    printf("%d not found\n", target);
                }
                break;
            }
            case 8: {
                // Sum of Product of Consecutive Numbers
                int n;
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                int numArr[n];
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &numArr[i]);
                }
                int sumProduct = sum_of_product(numArr, n);
                printf("Sum of product of consecutive numbers: %d\n", sumProduct);
                break;
            }
            case 9: {
                // Find Length of String
                char inputStr[100];
                printf("Enter a string: ");
                scanf("%s", inputStr);
                int length = 0;
                while (inputStr[length] != '\0') {
                    length++;
                }
                printf("Length of the string: %d\n", length);
                break;
            }
            case 10: {
                // Format Date
                int day, month, year;
                printf("Enter day, month, and year: ");
                scanf("%d %d %d", &day, &month, &year);
                switch (month) {
                    case 1: printf("%dth January, %d\n", day, year); break;
                    case 2: printf("%dth February, %d\n", day, year); break;
                    case 3: printf("%dth March, %d\n", day, year); break;
                    case 4: printf("%dth April, %d\n", day, year); break;
                    case 5: printf("%dth May, %d\n", day, year); break;
                    case 6: printf("%dth June, %d\n", day, year); break;
                    case 7: printf("%dth July, %d\n", day, year); break;
                    case 8: printf("%dth August, %d\n", day, year); break;
                    case 9: printf("%dth September, %d\n", day, year); break;
                    case 10: printf("%dth October, %d\n", day, year); break;
                    case 11: printf("%dth November, %d\n", day, year); break;
                    case 12: printf("%dth December, %d\n", day, year); break;
                    default: printf("Invalid month\n");
                }
                break;
            }
            case 11: {
                // Convert to Uppercase
                char inputString[100];
                printf("Enter a string: ");
                scanf("%s", inputString);
                for (int i = 0; inputString[i] != '\0'; i++) {
                    if (inputString[i] >= 'a' && inputString[i] <= 'z') {
                        inputString[i] = inputString[i] - 32;
                    }
                }
                printf("Converted string: %s\n", inputString);
                break;
            }
            case 12: {
                // Reverse String
                char reverseStr[100];
                printf("Enter a string: ");
                scanf("%s", reverseStr);
                reverse_string(reverseStr);
                printf("Reversed string: %s\n", reverseStr);
                break;
            }
            case 13: {
                // Check Palindrome
                char palindromeStr[100];
                printf("Enter a string: ");
                scanf("%s", palindromeStr);
                if (is_palindrome(palindromeStr)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            }
            case 14: {
                // Concatenate Strings
                char str1[100], str2[100];
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                concatenate_strings(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            }
            case 15: {
                // Construct and Display Matrix
                int matrix[5][5];
                construct_matrix(matrix, 5, 5);
                printf("Constructed Matrix:\n");
                display_matrix(matrix, 5, 5);
                break;
            }
               case 16: {
                // Transpose Matrix
                int rows, cols;
                printf("Enter the number of rows and columns: ");
                scanf("%d %d", &rows, &cols);
                int matrix[rows][cols];
                printf("Enter matrix elements:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Enter element at row %d, column %d: ", i + 1, j + 1);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                int transpose[cols][rows];
                transpose_matrix(matrix, rows, cols, transpose);

                printf("Original Matrix:\n");
                display_matrix(matrix, rows, cols);
                printf("Transposed Matrix:\n");
                display_matrix(transpose, cols, rows);
                break;
            }
            case 17: {
                // Sum of Each Column in Matrix
                int rows, cols;
                printf("Enter the number of rows and columns: ");
                scanf("%d %d", &rows, &cols);
                int matrix[rows][cols];
                printf("Enter matrix elements:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Enter element at row %d, column %d: ", i + 1, j + 1);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                int colSum[cols];
                sum_of_columns(matrix, rows, cols, colSum);
                printf("Sum of each column:\n");
                for (int i = 0; i < cols; i++) {
                    printf("Column %d: %d\n", i + 1, colSum[i]);
                }
                break;
            }
            case 18: {
                // Check Sparse Matrix
                int rows, cols;
                printf("Enter the number of rows and columns: ");
                scanf("%d %d", &rows, &cols);
                int matrix[rows][cols];
                printf("Enter matrix elements:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Enter element at row %d, column %d: ", i + 1, j + 1);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                if (is_sparse(matrix, rows, cols)) {
                    printf("The matrix is sparse.\n");
                } else {
                    printf("The matrix is not sparse.\n");
                }
                break;
            }
            case 0: // Exit
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
