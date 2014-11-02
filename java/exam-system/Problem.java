package com.exam;

public class Problem
{
	private Long id;
	private int num1,num2,answer,userAnswer=-1;
	//-1:初始状态为放弃
	private char oper;
	
	public Problem(){}
	public Problem(int num1,
					int num2,
					char oper)
	{
		this.num1=num1;
		this.num2=num2;
		this.oper=oper;
		setAnswer();
	}
	
	
	
	@Override public String toString()
	{
		return num1+"  " +oper+"   "+num2+"=";
	}
	
	//两道题目是否相同的比较规则
	@Override public boolean equals(Object o)
	{
		Problem problem=(Problem)o;
		if(oper!=problem.getOper())
			return false;
		if(oper=='+'||oper=='*')
		{
			return (num1==problem.getNum1()&&
					num2==problem.getNum2())||
					(num1==problem.getNum2()&&
					num2==problem.getNum1());
		}
		if(oper=='-'||oper=='/')
		{
			return (num1==problem.getNum1()&&
					num2==problem.getNum2());
		}
		return false;
	}
	
	
	
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public int getNum1() {
		return num1;
	}
	public void setNum1(int num1) {
		this.num1 = num1;
	}
	public int getNum2() {
		return num2;
	}
	public void setNum2(int num2) {
		this.num2 = num2;
	}
	public int getAnswer() {
		return answer;
	}
	
	
	public void setAnswer()
	{
		answer=num1+num2;
		if(oper=='-')
			answer=num1-num2;
		if(oper=='*')
			answer=num1*num2;
		if(oper=='/')
			answer=num1/num2;
	}
	
	
	public int getUserAnswer() {
		return userAnswer;
	}
	public void setUserAnswer(int userAnswer) {
		this.userAnswer = userAnswer;
	}
	public char getOper() {
		return oper;
	}
	public void setOper(char oper) {
		this.oper = oper;
	}
	

	
}
