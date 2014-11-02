/*
 * 服务于用户模块：登录验证，注册功能
 */
package com.exam;

import java.util.*;


public class UserService {
	private static Set<User> set;
	
	private static int currentID=0;
	
	static
	{
		set=new HashSet<User>();
		//超级用户：test用："admin","admin"
		User user=new User("admin","admin");
		set.add(user);
	}
	
	//登录验证
	public static boolean load(String userName,
						       String userPwd)
	{
		for(User user:set)
		{
			if(user.getUserName().equals(userName)&&
					user.getUserPwd().equals(userPwd))
				return true;
		}
		return false;
	}
	
	
	//存在UserName－>true;
	public static boolean load(String userName)
	{
		for(User user:set)
		{
			if(user.getUserName().equals(userName))
				return true;
		}
		return false;
	}
	
	
	//注册
	/*
	 * 注册成功：1
	 * 用户名重复：0
	 * 发生其他的意外错误：－1
	 * 
	 */
	public static int add(String userName,String userPwd)
	{
		try
		{
			//(1)用户名已被使用
			if(load(userName))
				return 0;
			
			//(2)注册
			User user=new User(userName,userPwd);
			currentID++;
			user.setId(new Long(currentID));
			set.add(user);
			return 1;
			
		}catch(Exception e)
		{
			//(3)意外错误
			return -1;
		}
	}
	
	//test:
	public static void print()
	{
		for(User user:set)
			System.out.println(user);
		System.out.println("******print end******");
	}

	
	
	public static void main(String[] args) 
	{
		print();
		System.out.println(add("admin","111"));
		System.out.println(add("tom","123"));
		System.out.println(add("jack","000"));
		print();
		System.out.println(load("admin","admin"));
		System.out.println(load("admin","admin1"));
	}

}
