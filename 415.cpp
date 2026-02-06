/**
 * LeetCode Problem 415: Add Strings
 * Add two non-negative integers represented as strings without using BigInteger library
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Solution class for adding two numeric strings
 */
class Solution {
public:
    /**
     * Adds two non-negative integers represented as strings
     * 
     * Algorithm: Simulates digit-by-digit addition from right to left,
     * similar to how you would add numbers manually on paper.
     * 
     * @param num1 First non-negative integer as string
     * @param num2 Second non-negative integer as string
     * @return Sum of num1 and num2 as string
     * 
     * Time Complexity: O(max(m, n)) where m and n are lengths of num1 and num2
     * Space Complexity: O(max(m, n)) for result string
     */
    string addStrings(string num1, string num2) {
        // Validate input
        if (!isValidNumber(num1) || !isValidNumber(num2)) {
            return "0";
        }
        
        string result;
        result.reserve(max(num1.size(), num2.size()) + 1); // Optimize memory allocation
        
        int index1 = num1.size() - 1;  // Pointer for num1 (starting from rightmost digit)
        int index2 = num2.size() - 1;  // Pointer for num2 (starting from rightmost digit)
        int carry = 0;                  // Carry value for addition
        
        // Continue while there are digits to process or carry remaining
        while (index1 >= 0 || index2 >= 0 || carry > 0) {
            int digitSum = carry;
            
            // Add digit from num1 if available
            if (index1 >= 0) {
                digitSum += num1[index1] - '0';
                index1--;
            }
            
            // Add digit from num2 if available
            if (index2 >= 0) {
                digitSum += num2[index2] - '0';
                index2--;
            }
            
            // Append the ones digit to result
            result += (digitSum % 10) + '0';
            
            // Calculate carry for next iteration
            carry = digitSum / 10;
        }
        
        // Reverse the result since we built it backwards
        reverse(result.begin(), result.end());
        
        return result;
    }

private:
    /**
     * Validates that a string represents a valid non-negative integer
     * 
     * @param num String to validate
     * @return true if valid, false otherwise
     */
    bool isValidNumber(const string& num) {
        if (num.empty()) {
            return false;
        }
        
        for (char ch : num) {
            if (ch < '0' || ch > '9') {
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Main function to test the Solution
 */
int main() {
    string firstNumber, secondNumber;
    
    cout << "Enter two non-negative integers (separated by space): ";
    cin >> firstNumber >> secondNumber;
    
    Solution solver;
    string sum = solver.addStrings(firstNumber, secondNumber);
    
    cout << "Result: " << sum << '\n';
    
    return 0;
} 