package com.ch01;

public class ArrayTest
{
	public static void main(String args[])
	{
		int array []=new int[100];
		int sum=0;

		for(int i=0;i<100;i++)
		{
			array[i]=i+1;
			sum+=array[i];
			System.out.print(array[i]+" ");
		}
		System.out.println("hello，道兄");
		System.out.println("sum:"+sum);
	}
}
