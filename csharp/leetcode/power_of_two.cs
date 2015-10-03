using System;

public class Solution {
    public bool IsPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
}

public class Test 
{
   static void Main()
   {
   		Solution s = new Solution();
   		Console.WriteLine(s.IsPowerOfTwo(1));
   		Console.WriteLine(s.IsPowerOfTwo(2));
   		Console.WriteLine(s.IsPowerOfTwo(3));
   		Console.WriteLine(s.IsPowerOfTwo(4));	
   		Console.ReadKey();
   }
}