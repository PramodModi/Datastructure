/*
Leetcode 20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.

Open brackets must be closed in the correct order.

Every close bracket has a corresponding open bracket of the same type.

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Constraints:

1 <= s.length <= 104

s consists of parentheses only '()[]{}'.
*/

import java.util.*;
public class ValidParentheses{
	public boolean validParentheses(String s){
		Map<Character, Character> temp = new HashMap<>();
		temp.put(')', '(');
		temp.put('}', '{');
		temp.put(']', '[');

		Stack<Character> stack = new Stack<>();

		for(char k : s.toCharArray()){
			if(!temp.containsKey(k)){
				stack.push(k);
			}
			else{
				if(stack.isEmpty() || stack.pop() != temp.get(k)){
					return false;
				}
			}
		}
		return true;
	}

	public static void main(String [] args){
		ValidParentheses c = new ValidParentheses();
		String s = "()[]{}";
		System.out.println(c.validParentheses(s));
	}
}