#include <iostream>
#include <string>
using namespace std;

/*
 * Function to check if a string is palindrome using recursion
 * Time Complexity: O(n/2) = O(n) - checks n/2 character pairs
 * Space Complexity: O(n/2) = O(n) - recursive call stack depth
 * @param s: input string
 * @param start: starting index
 * @param end: ending index
 * @return: true if palindrome, false otherwise
 */
bool checkPalindrome(string s, int start, int end){
    // Base case: empty string is palindrome
    if(s.empty()) return true;
    
    // Base case: when pointers meet or cross, string is palindrome
    if(start >= end) return true;
    
    // If characters don't match, not a palindrome
    if(s[start] != s[end]) return false;
    
    // Recursive call: move inward from both ends
    return checkPalindrome(s, start +1, end -1);
}

int main(){
    string s;
    cout << "Enter the string : ";
    cin >> s;
    
    // Check palindrome and output result
    checkPalindrome(s, 0, s.length()-1) ? cout << "true" : cout << "false";
    
    return 0;
}