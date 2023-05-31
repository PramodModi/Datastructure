/*
Leetcode: 125: Valid Palindrom
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"

Output: true

Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"

Output: false

Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "

Output: true

Explanation: s is an empty string "" after removing non-alphanumeric characters. Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:

1 <= s.length <= 2 * 105

s consists only of printable ASCII characters.
*/

public class ValidPalindrom{
	public boolean validPalindrom(String s){
		int leftIndex = 0;
		int rightIndex = s.length() -1;

		while (leftIndex <= rightIndex){
			char leftChar = s.charAt(leftIndex);
			char rightChar = s.charAt(rightIndex);

			if(! Character.isLetterOrDigit(leftChar)){
				leftIndex += 1;
			}
			else if(! Character.isLetterOrDigit(rightChar)){
				rightIndex -= 1;
			}
			else{
				if(Character.toLowerCase(leftChar) != Character.toLowerCase(rightChar)){
					return false;
				}
				leftIndex += 1;
				rightIndex -= 1;
			}
		}
		return true;

	}

	public static void main(String [] args){
		ValidPalindrom c = new ValidPalindrom();
		String s = "A man, a plan, a canal: Panama";
		//String s = "race a car";
		System.out.println(s + " : is a palindrom? :" + c.validPalindrom(s));
	}
}