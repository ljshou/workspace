package com.exam;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Register {

	private JFrame frame;
	private Container contentPane;

	private JTextField userNameText;//用户名
	private JPasswordField
		userPwdText1,userPwdText2;//密码
	private JButton
	cleatBtn,okBtn,backBtn,exitBtn;
	
	public Register()
	{

		frame=new JFrame("Land:  ");
		frame.setBounds(350,300,300,150);
		//设置可改变大小
		frame.setResizable(false);
		//点击关闭按钮结束整个应用程序
		frame.setDefaultCloseOperation
		(JFrame.EXIT_ON_CLOSE);
		contentPane=frame.getContentPane();
		initGUI();
	}

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
		userPwdText1=new JPasswordField(8);
		p2.add(new JLabel("password:"));
		p2.add(userPwdText1);
	
		//（3）密码2
		JPanel p3=new JPanel(new FlowLayout());
		userPwdText2=new JPasswordField(8);
		p3.add(new JLabel("password:"));
		p3.add(userPwdText2);
	
		//（4）整合（1）（2）（3）
		JPanel pCenter=new JPanel
			(new GridLayout(3,1));
			pCenter.add(p1);
			pCenter.add(p2);
			pCenter.add(p3);
			contentPane.add(pCenter,
				BorderLayout.CENTER);
		
		//（5）操作按钮
			JPanel pSouth=
				new JPanel(new FlowLayout());
			cleatBtn=new JButton("clear");
			okBtn=new JButton("finish");
			backBtn=new JButton("back");
			exitBtn=new JButton("exit");
			pSouth.add(cleatBtn);
			pSouth.add(okBtn);
			pSouth.add(backBtn);
			pSouth.add(exitBtn);
			contentPane.add(pSouth,
					BorderLayout.SOUTH);
		}
	
		//启动方法
		public void go()
		{
			frame.setVisible(true);
		}
		
		public static void main(String[] args) {
			(new Register()).go();
		}
}