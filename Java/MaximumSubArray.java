/*
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]

Output: 6

Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]

Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]

Output: 23

Constraints:

1 <= nums.length <= 105

-104 <= nums[i] <= 104
*/

import java.util.*;
public class MaximumSubArray{
	public int maxSum(int[] nums){
		int maxsum = Integer.MIN_VALUE;
		int sum = 0;

		for(int n : nums){
			sum = Math.max(n, sum+n);
			maxsum = Math.max(maxsum, sum);
		}
		return maxsum;
	}

	public int[] printSubArray_MaxSum(int[] nums){
		int maxsum = nums[0];
		int sum = nums[0];
		int startIndex = 0;
		int endIndex = 0;
		int start = 0;
		for(int i =1; i< nums.length; i++){
			int n = nums[i];
			if(n > sum+n) {
				start = i;
				sum = n;
			}
			else{
				sum = sum +n;
			}
			if(maxsum < sum){
				maxsum = sum;
				startIndex = start;
				endIndex = i;
			}

		}
		return new int[]{maxsum, startIndex, endIndex};
	}

	public static void main(String[] args){
		MaximumSubArray c = new MaximumSubArray();
		int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
		//int[] nums = {5,4,-1,7,8};
		System.out.println(c.maxSum(nums));
		int[] res = c.printSubArray_MaxSum(nums);
		int[] subarray = Arrays.copyOfRange(nums, res[1], res[2]+1);
		System.out.println("maxSum = " + res[0]);
		System.out.println("SubArray = "+ Arrays.toString(subarray));
	}
}