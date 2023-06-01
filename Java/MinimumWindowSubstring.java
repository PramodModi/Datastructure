/*
Leet code 76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"

Output: "BANC"

Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"

Output: "a"

Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"

Output: ""

Explanation: Both 'a's from t must be included in the window. Since the largest window of s only has one 'a', return empty string.

Constraints:

m == s.length

n == t.length

1 <= m, n <= 105

s and t consist of uppercase and lowercase English letters.
*/

import java.util.*;
public class MinimumWindowSubstring{
	public String minWindowSubstring(String s, String t){
		if(t.length() > s.length()){
			return " ";
		}

		Map<Character, Integer> temp = new HashMap<>();
		for(char c : t.toCharArray()){
			temp.put(c, temp.getOrDefault(c, 0) + 1);
		}


		int left = 0;
		int right = 0;
		int minLength = Integer.MAX_VALUE;
		int minLeftIndex = 0;
		int minRightIndex = 0;
		int remainingChars = temp.size();

		while(right < s.length()){
			char c = s.charAt(right);
			if(temp.containsKey(c)){
				temp.put(c, temp.get(c)  - 1);
				if(temp.get(c) == 0){
					remainingChars -= 1;
				}
			}
			while (remainingChars == 0){
				c = s.charAt(left);
				if(temp.containsKey(c)){
					temp.put(c, temp.get(c) + 1);
					if(temp.get(c) == 1){
						remainingChars += 1;
					}
				}
				if(right - left + 1 < minLength){
					minLength = right-left+1;

					minLeftIndex = left;
					minRightIndex = right;
				}
				left += 1;

			}
			right += 1;

		}
		return s.substring(minLeftIndex, minRightIndex+1);
	}

	public static void main(String[] args){
		MinimumWindowSubstring c = new MinimumWindowSubstring();
		String s = "ADOBECODEBANC";
		String t = "ABC";

		String ret = c.minWindowSubstring(s, t);
		System.out.println(ret);
	}
}
