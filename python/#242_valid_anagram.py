from typing import List

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): 
            return False
        
        #Creating a Dictionary
        hashMap = {}

        for c in s:
            hashMap[c] = hashMap.get(c, 0) + 1
            # if the key c is not already present in the dictionary, it sets the
            # default value to 0 before incrementing.

        for c in t:
            hashMap[c] = hashMap.get(c, 0) - 1 

        for key in hashMap:
            if hashMap[key] != 0:
                return False
        
        return True


def main():
    sol = Solution()

    s = "anagram"
    t = "nagaram"

    result1 = sol.isAnagram(s, t)
    print(f"Test Case 1: {result1}")  # Expected output: True


if __name__ == "__main__":
    main()