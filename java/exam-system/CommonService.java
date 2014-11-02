/*
 * 对考试系统提供公共的服务
 */
package com.common;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CommonService {
	
	//设置任意
	public static void setBtnEnabled
	(boolean flag,JButton...btns)
	{
		for(JButton btn:btns)
			btn.setEnabled(flag);
	}
	
	//
	public static void setTextEnabled
	(boolean flag,JTextField...texts)
	{
		for(JTextField text:texts)
			text.setEnabled(flag);
	}
	
	//为任意个数的按钮添加监听
	public static void addBtnListener
	(ActionListener listener,JButton...btns)
	{
		for(JButton btn:btns)
			btn.addActionListener(listener);
	}
	
	//为任意个数的文本添加监听
	public static void addTextListener
	(ActionListener listener,JTextField...texts)
	{
		for(JTextField text:texts)
			text.addActionListener(listener);
	}
	
	
	

	//字符串处理，去掉字符串两端及中间的空格，统一小写
	public static String handlerString
	(String str)
	{
		if(str==null)
			return "";
		char [] ch=str.toCharArray();
		StringBuffer buffer=new StringBuffer();
		for(int i=0;i<ch.length;i++)
		{
			if(ch[i]==' ')
				continue;
			buffer.append(ch[i]);
		}
			return new String(buffer).toLowerCase();
	}
	public static void main(String[] args) {
		System.out.println(handlerString(null).length());
		System.out.println(handlerString("    Tom").length());
		System.out.println(handlerString("   ds   j   DSS   ").length());		
	}

}
