#include <iostream>
#include <string>
#include <limits>
#include <climits>
using namespace std;

// Function prototypes
void factorialCalculator(); // Calculates factorial using while loop
void numberPyramid(); // Displays number pyramid using nested for loops
void sumEvenOdd(); // Sums even/odd numbers using do-while loop
void reverseString(); // Reverses a string using while loop
void fibonacciSeries(); // Displays Fibonacci series using for loop
void palindromeCheck(); // Checks if a string is a palindrome using while loop
void goodbyeMessage(); // Displays goodbye message
int getValidatedInt(const string& prompt, int min = INT_MIN, int max = INT_MAX); // Validates integer input

int main() {
    int choice;
    do {
        // Display menu
        cout << "========= Interactive Utility Program =========\n";
        cout << "1. Factorial Calculator\n";
        cout << "2. Number Pyramid\n";
        cout << "3. Sum of Even or Odd Numbers\n";
        cout << "4. Reverse a String\n";
        cout << "5. Fibonacci Series\n";
        cout << "6. Palindrome Check\n";
        cout << "7. Exit\n";
        cout << "==============================================\n";
        choice = getValidatedInt("Enter your choice: ", 1, 7);

        switch (choice) {
            case 1: factorialCalculator(); break;
            case 2: numberPyramid(); break;
            case 3: sumEvenOdd(); break;
            case 4: reverseString(); break;
            case 5: fibonacciSeries(); break;
            case 6: palindromeCheck(); break;
            case 7: goodbyeMessage(); break;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}

// Function to get validated integer input
// Prompts user until a valid integer within [min, max] is entered
int getValidatedInt(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            cout << "Invalid input. Please enter a number";
            if (min != INT_MIN && max != INT_MAX)
                cout << " between " << min << " and " << max;
            cout << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// 1. Factorial Calculator (while loop)
// Calculates factorial of a positive integer using a while loop
void factorialCalculator() {
    int n = getValidatedInt("Enter a positive integer: ", 1);
    unsigned long long factorial = 1;
    int i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }
    cout << "Factorial of " << n << " is: " << factorial << endl;
}

// 2. Number Pyramid (for loop, nested loops)
// Displays a pyramid of numbers using nested for loops
void numberPyramid() {
    int rows = getValidatedInt("Enter number of rows: ", 1);
    for (int i = 1; i <= rows; ++i) {
        // Print spaces
        for (int j = 1; j <= rows - i; ++j)
            cout << " ";
        // Print numbers
        for (int k = 1; k <= i; ++k)
            cout << k << " ";
        cout << endl;
    }
}

// 3. Sum of Even or Odd Numbers (do-while loop)
// Sums even or odd numbers up to a limit using a do-while loop
void sumEvenOdd() {
    int choice;
    do {
        cout << "Choose:\n1. Sum of Even Numbers\n2. Sum of Odd Numbers\n";
        choice = getValidatedInt("Enter your choice (1 or 2): ", 1, 2);
    } while (choice != 1 && choice != 2);

    int n = getValidatedInt("Enter upper limit: ", 1);
    int sum = 0, i = 1;
    do {
        if (choice == 1 && i % 2 == 0)
            sum += i;
        else if (choice == 2 && i % 2 != 0)
            sum += i;
        i++;
    } while (i <= n);

    if (choice == 1)
        cout << "Sum of even numbers up to " << n << ": " << sum << endl;
    else
        cout << "Sum of odd numbers up to " << n << ": " << sum << endl;
}

// 4. Reverse a String (while loop)
// Reverses a string using a while loop, with input validation
void reverseString() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    // Validate non-empty input
    while (str.empty()) {
        cout << "Input cannot be empty. Please enter a string: ";
        getline(cin, str);
    }
    string reversed;
    int i = str.length() - 1;
    while (i >= 0) {
        reversed += str[i];
        i--;
    }
    cout << "Reversed string: " << reversed << endl;
}

// 5. Fibonacci Series (for loop)
// Displays the Fibonacci series up to N terms using a for loop
void fibonacciSeries() {
    int n = getValidatedInt("Enter number of terms for Fibonacci series: ", 1);
    unsigned long long a = 0, b = 1, next;
    cout << "Fibonacci series: ";
    for (int i = 1; i <= n; ++i) {
        cout << a;
        if (i < n) cout << ", ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// 6. Palindrome Check (while loop)
// Checks if a string is a palindrome using a while loop
void palindromeCheck() {
    string str;
    cout << "Enter a string to check for palindrome: ";
    getline(cin, str);
    // Validate non-empty input
    while (str.empty()) {
        cout << "Input cannot be empty. Please enter a string: ";
        getline(cin, str);
    }
    int left = 0, right = str.length() - 1;
    bool isPalindrome = true;
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }
    if (isPalindrome)
        cout << "'" << str << "' is a palindrome." << endl;
    else
        cout << "'" << str << "' is not a palindrome." << endl;
}

// 7. Exit Program
// Displays a goodbye message and exits
void goodbyeMessage() {
    cout << "Goodbye! Thank you for using the program." << endl;
}