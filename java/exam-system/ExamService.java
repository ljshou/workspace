/*
 * 服务于考试
 */

package com.exam;

import java.util.*;

public class ExamService {
	
	//为某一用户提供不重复的题目
	public static Problem getProblem(User user)
	{
		int operValue=(int)(Math.random()*4);
		int num1=-1,num2=-1;
		char oper='+';
		switch(operValue)
		{
		
		//+
		case 0:
		{
			num1=(int)(Math.random()*1001);
			num2=(int)(Math.random()*(1001-num1));
			oper='+';
		}break;
		
		//-
		case 1:
		{
			num1=(int)(Math.random()*1001);
			num2=(int)(Math.random()*(1001-num1));
			num1=num1+num2;	
			oper='-';
		}break;
		
		//*
		case 2:
		{
			num1=(int)(Math.random()*(1000.0/32));
			num2=(int)(Math.random()*(1000.0/32));
			oper='*';
		}break;
		
		///整除
		case 3:
		{
			num1=(int)(Math.random()*(1000.0/32));
			num2=(int)(Math.random()*(1000.0/32))+1;
			num1=num1*num2;
			oper='/';
		}break;
		}
		
		Problem problem=
			new Problem(num1,num2,oper);
		
		List<Problem> proList=
			user.getProList();
		boolean flag=false;
		for(Problem p:proList)
		{
			if(p.equals(problem))
			{
				flag=true;
				break;
			}
		}
		if(flag)
			return getProblem(user);
		problem.setId(new Long(proList.size()+1));
		proList.add(problem);
		return problem;
	}

		

	public static void main(String[] args)
	{
		//［0，1000］
		User user=new User();
		for(int i=0;i<100;i++)
		{
			System.out.println(getProblem(user));
		}
		
		
	}

}
