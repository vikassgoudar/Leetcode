/*
https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
*/

long long countSubarrays(int* nums, int numsSize, int k) {
  int start = 0;
  int end = 0;
  long long ans = 0;
  int count = 0;
  int max = nums[0];
    

  for (int i = 0; i< numsSize; i++){
    if (nums[i] > max){
      max = nums[i];
    }
  }

  while (end < numsSize){
    if (nums[end] == max){
      count++;
    }
        
    if (count == k){
      while (count == k){
        ans += 1 + (numsSize - 1 - end);
          start++;
          if (nums[start-1] == max){
            count--;
          }
      }
    }
    end++;
  }
  return ans;
}
