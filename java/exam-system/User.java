//用户类

package com.exam;

import java.util.*;

public class User {
	private Long id;
	private String userName;
	private String userPwd;
	
	
	private List<Problem> proList=
		new ArrayList<Problem>();
	//存放用户做过的所有题目
	
	public User(){}
	public User(String userName,
				String userPwd)
	{
		this.userName=userName;
		this.userPwd=userPwd;
	}
	
	@Override public String toString()
	{
		return id+"/"+userName+"/"+userPwd;
	}
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public String getUserPwd() {
		return userPwd;
	}
	public void setUserPwd(String userPwd) {
		this.userPwd = userPwd;
	}
	public List<Problem> getProList() {
		return proList;
	}
	public void setProList(List<Problem> proList) {
		this.proList = proList;
	}
	
	

}
