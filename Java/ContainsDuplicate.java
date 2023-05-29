/*
Leetcode : 217. Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true

Example 2:

Input: nums = [1,2,3,4]

Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

Constraints:

1 <= nums.length <= 105

-109 <= nums[i] <= 109
*/

import java.util.*;
public class ContainsDuplicate{
	public boolean isDuplicate(int[] nums){
		HashSet <Integer> m = new HashSet<>();
		for(int n : nums){
			if(m.add(n) == false)
				return true;
		}
		return false;
	}

	public static void main(String[] args){
		ContainsDuplicate c = new ContainsDuplicate();
		int [] nums = {1,1,1,3,3,4,3,2,4,2};
		//int [] nums = {1,2,3,4};
		boolean res = c.isDuplicate(nums);
		System.out.println(res);
	}
}
