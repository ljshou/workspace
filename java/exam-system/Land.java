/*
 *  考试系统－登录界面
 */
package com.exam;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import com.common.*;


public class Land implements ActionListener{
	private JFrame frame;
	private Container contentPane;
	
	private JTextField userNameText;//用户名
	private JPasswordField userPwdText;//密码
	
	private JButton
		cleatBtn,newBtn,okBtn,exitBtn;
	
	//构造器：外框（顶级容器）的初始化
	public Land()
	{
		frame=new JFrame("Land:  ");
		frame.setBounds(350,300,350,150);
		//设置可改变大小
		frame.setResizable(false);
		//点击关闭按钮结束整个应用程序
		frame.setDefaultCloseOperation
		(JFrame.EXIT_ON_CLOSE);
		contentPane=frame.getContentPane();
		initGUI();
	}
	//小组件的初始化，事件处理等
	public void initGUI()
	{
		//边界式布局
		contentPane.setLayout
			(new BorderLayout());
		//（1）用户名
		JPanel p1=new JPanel(new FlowLayout());
		userNameText=new JTextField(8);
		p1.add(new JLabel("name:      "));
		p1.add(userNameText);
		
		//（2）密码
		JPanel p2=new JPanel(new FlowLayout());
		userPwdText=new JPasswordField(8);
		p2.add(new JLabel("password:"));
		p2.add(userPwdText);
		
		//（3）整合（1）（2）
		JPanel pCenter=
			new JPanel(new GridLayout(2,1));
			pCenter.add(p1);
			pCenter.add(p2);
			contentPane.add(pCenter,
					BorderLayout.CENTER);
		
		//（4）操作按钮
		JPanel pSouth=
			new JPanel(new FlowLayout());
		cleatBtn=new JButton("clear");
		newBtn=new JButton("register");
		okBtn=new JButton("finish");
		exitBtn=new JButton("exit");
		pSouth.add(cleatBtn);
		pSouth.add(newBtn);
		pSouth.add(okBtn);
		pSouth.add(exitBtn);
		contentPane.add(pSouth,
				BorderLayout.SOUTH);
		
		//添加监听
		CommonService.addBtnListener(this,
				cleatBtn,newBtn,okBtn,exitBtn);
		CommonService.addTextListener(this,
				userNameText,userPwdText);
	}
	
	//集中式事件处理
	public void actionPerformed(ActionEvent e)
	{
		//清空按钮
		if(e.getSource()==cleatBtn)
		{
			userNameText.setText("");
			userPwdText.setText("");
			//获得焦点
			userNameText.grabFocus();
			return;
		}
		
		//新注册按钮
		if(e.getSource()==newBtn)
		{
			(new Register()).go();
			frame.hide();
			return;
		}
		
		
		//用户名文本
		if(e.getSource()==userNameText)
		{
			String userNameStr=
				CommonService.handlerString
				(userNameText.getText());
		//修复输入文本
		userNameText.setText(userNameStr);
		//用户未输入有效字符
			if(userNameStr.length()==0)
			{
				userNameText.grabFocus();
				return;
			}
			userPwdText.grabFocus();
			return;
		}
		
		//密码文本及确定按钮
		if(e.getSource()==userPwdText||
				e.getSource()==okBtn)
		{
			String userNameStr=
				CommonService.handlerString
				(userNameText.getText());
			
			//未输入有效用户名
			if(userNameStr.length()==0)
			{
				userNameText.setText("");
				userPwdText.setText("");
				userNameText.grabFocus();
				return;
			}
			
			String userPwdStr=
				CommonService.handlerString
				(userPwdText.getText());
			
			//未输入有效密码
			if(userPwdStr.length()==0)
			{
				userPwdText.setText("");
				userPwdText.grabFocus();
				return;
			}
			//*********登录验证功能*******:
			boolean flag=
				UserService.load
				(userNameStr, userPwdStr);
			if(flag)
			{
				User user=new User
				(userNameStr,userPwdStr);
				(new ExamGUI(user)).go();
				frame.hide();
			}
			else
				System.out.println("error!");
			
		}
		
		
		
		
		if(e.getSource()==exitBtn)
		{
			System.exit(0);
		}
	}
	
	//启动方法
	public void go()
	{
		frame.setVisible(true);
	}
	public static void main(String[] args) {
		(new Land()).go();
	}

}
