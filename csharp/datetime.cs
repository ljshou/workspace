using System;

namespace Test 
{
	public class Test 
	{
		static void Main(string [] args) 
		{
			string date_str = "2015/08/10";
			DateTime date = DateTime.Parse(date_str);
			Console.WriteLine(date.ToString());
			Console.WriteLine(date);
			Console.Read();
		}
	}
}
