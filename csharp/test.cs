#define DEBUG

using System;
using System.Collections;
using System.Diagnostics;


namespace Test 
{
	public class A 
	{
		// private construction
		A() {
			Console.WriteLine("Construction called");
		}
		public static A create() {
			return new A();
		}
	}

	public class TestProperty 
	{
		decimal currentPrice;
		public TestProperty(decimal price) {
			currentPrice = price;
		}

		public decimal CurrentPrice {
			get {
				Console.WriteLine("return value");
				return currentPrice;
			}
			set {
				Console.WriteLine("Setting value");
				currentPrice = value;
			}
		}
	}

	public class Test 
	{
		static void Main(string[] args)
		{
			//Debug.Assert(1 == 2);
			Console.WriteLine("hello world");
			Console.ReadKey();
		}
	}
}