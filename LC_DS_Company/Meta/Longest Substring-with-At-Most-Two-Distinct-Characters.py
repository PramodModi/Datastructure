# Problem: longest substring that contains at most two distinct characters
"""
Description:
Given a string s, return the length of the longest substring that contains at most two distinct characters.

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.

Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.

Constraints:

1 <= s.length <= 105
s consists of English letters.
"""
from prompt_toolkit.key_binding.bindings.named_commands import unix_word_rubout


def lengthOfLongestSubstringTwoDistinct(s):
    max_length = 0
    temp = {}
    unique_chars = 0
    left, right = 0,0
    while right < len(s):
        c = s[right]
        temp[c] = temp.get(c, 0) + 1
        if temp[c] == 1:
            unique_chars += 1
        while unique_chars > 2:
            c = s[left]
            if c in temp:
                temp[c] -= 1
                if temp[c] == 0:
                    unique_chars -= 1
            left += 1
        max_length = max(max_length, right -left + 1)
        right += 1

    return max_length

s = "eceba"
print(lengthOfLongestSubstringTwoDistinct(s))

s = "ccaabbb"
print(lengthOfLongestSubstringTwoDistinct(s))

