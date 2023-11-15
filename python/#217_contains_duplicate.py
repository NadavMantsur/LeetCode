from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashSet = set()

        for num in nums:
            if num in hashSet:
                return True
            hashSet.add(num)
        return False

def main():
    sol = Solution()

    nums1 = [1, 2, 3, 1]
    result1 = sol.containsDuplicate(nums1)
    print(f"Test Case 1: {result1}")  # Expected output: True
    #f-string allow you to embed expressions inside string literals, using 
    # curly braces {}


if __name__ == "__main__":
    main()
# to determine whether the script is being run as the main program or if it is 
# being imported as a module into another script.