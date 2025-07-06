# Problem: Minimum Remove to Make Valid Parentheses
"""LeetCode : 1249
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

Description :
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions )
so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:

    Input: s = "lee(t(c)o)de)"
    Output: "lee(t(c)o)de"
    Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

    Input: s = "a)b(c)d"
    Output: "ab(c)d"
Example 3:

    Input: s = "))(("
    Output: ""
    Explanation: An empty string is also valid.


Constraints:

1 <= s.length <= 105
s[i] is either '(' , ')', or lowercase English letter.

"""

# Approach 1:
# Using Stack
def minRemoveToMakeValid(s):
    stack = []
    open = 0
    close = 0
    for i in range(len(s)):
        c = s[i]
        if c == "(":
            open += 1
        elif c == ")":
            close += 1
        if close > open:
            close -= 1
        else:
            stack.append(c)
    res = []
    while stack:
        c = stack.pop()
        if c == "(" and open > close:
            open -= 1
        else:
            res.append(c)
    return "".join(res[::-1])

s = "lee(t(c)o)de)"
print(minRemoveToMakeValid(s))

## Approach 2:
# Without using stack
def minRemoveToMakeValid1(s):
    open = 0
    s_list = list(s)
    for i in range(len(s_list)):
        c = s_list[i]
        if c == "(":
            open += 1
        elif c == ")":
            if open == 0:
                s_list[i] = "*"
            else:
                open -=1
    for i in range(len(s_list)-1, -1, -1):
        c = s_list[i]
        if c == "(" and open > 0:
            open -=1
            s_list[i] = "*"
    p = 0
    for i in range(len(s_list)):
        if s_list[i] != "*":
            s_list[p] = s_list[i]
            p += 1
    return "".join(s_list[:p])


s = "lee(t(c)o)de)"
print(minRemoveToMakeValid1(s))

s = "a)b(c)d"
print(minRemoveToMakeValid1(s))

s = "))(("
print(minRemoveToMakeValid1(s))