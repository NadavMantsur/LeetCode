using System;   //Length

public class Solution {
    public void ReverseString(char[] s) {
        int left = 0;
        int right = s.Length - 1;

        while (left < right){
            Swap(ref s[left], ref s[right]);
            ++left;
            --right;
        }
    }

    private void Swap(ref char a, ref char b) {
        char temp = a;
        a = b;
        b = temp;
    }
}

class Program {
    static void Main() {
        Solution sol = new Solution();

        char[] input = {'h', 'e', 'l', 'l', 'o'};
        Console.WriteLine("Original Array: " + new string(input));

        sol.ReverseString(input);
        Console.WriteLine("Reversed Array: " + new string(input));
    }
}