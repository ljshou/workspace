using System;
using System.Collections;

namespace Test 
{
	public class Test 
	{
		static void Main(string[]args)
		{
			Console.WriteLine("Please Input an integer");
			int x = Convert.ToInt16(Console.ReadLine());
			Console.WriteLine("x = {0}", x);
			Console.WriteLine("test");

			int [] array = new int[5] {1, 2, 3, 4, 5};
			int [] b = array; //referrence
			b[0] = 1000;
			Console.WriteLine("array[0] is {0}", array[0]);

			Array.Sort(array);

			Console.WriteLine("Print array after sort");
			foreach (int i in array) 
			{
				Console.Write(i + " ");
			}
			Console.Write('\n');

			ArrayList al = new ArrayList();
			al.Add("hello");
			al.Add(1);

			Console.Write(al[0] + " ");
			Console.Write(al[1] + " ");
			Console.WriteLine();
			Console.ReadKey();
		}
	}
}