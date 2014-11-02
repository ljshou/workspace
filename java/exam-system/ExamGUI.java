package com.exam;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import com.common.*;


public class ExamGUI implements ActionListener
{
	private JFrame frame;
	private Container contentPane;
	
	//north
	private JLabel examTimeLbl;//倒计时标签
	private JLabel informLbl;//信息提示标签
	

	
	//center
	private JLabel idLbl,num1Lbl,operLbl,num2Lbl;
	private JTextField userAnswerText;//用户答案
	private JButton newProBtn;//新题
	
	
	//south
	private JButton firstBtn,preBtn,nextBtn,lastBtn;//翻动按钮
	private JTextField pageText;
	private JButton pageBtn;//跳转
	private JButton startBtn,submitBtn;//开始，系统交卷
	private JLabel sysTimeLbl;//系统时间显示
	
	//--------------------------------------------------
	private User user;
	private Timer sysTimer;//系统时间显示控制
	private int currentId;//“当前”操作的题号
	private Timer examTimer;//倒计时控制
	

	
	public ExamGUI(User user)
	{
		this.user=user;
		if(user==null)
		{
			this.user=new User();
			this.user.setUserName("visitor");
		}
		frame=new JFrame(this.user.getUserName()+" Hello，welcome to Exam System！");
		frame.setBounds(350,300,500,250);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		contentPane=frame.getContentPane();
		initGUI();
		sysTimer=new Timer(1000,this);
		examTimer=new Timer(1000,this);
		sysTimer.start();
	}
	
	public void initGUI()
	{
		contentPane.setLayout(new BorderLayout());
		//(1)north
		//(1.1)倒计时
		JPanel pNorth1=new JPanel
			(new FlowLayout(FlowLayout.RIGHT));
		examTimeLbl=new JLabel("01:00:00");
		pNorth1.add(new JLabel("[time lest:]"));
		pNorth1.add(examTimeLbl);	
		//(1.2)信息提示
		JPanel pNorth2=new JPanel
			(new FlowLayout());
		informLbl=new JLabel
			("please click the Start!");
		pNorth2.add(new JLabel("[notice]:"));
		pNorth2.add(informLbl);
		
		//(1.3)整合Panel
		JPanel pNorth=new JPanel
			(new GridLayout(2,1));
		pNorth.add(pNorth1);
		pNorth.add(pNorth2);
		contentPane.add(pNorth,BorderLayout.NORTH);
		
		//(2)center
		JPanel pCenter=new JPanel(new FlowLayout());
		idLbl=new JLabel("id");
		num1Lbl=new JLabel("num1");
		operLbl=new JLabel("oper");
		num2Lbl=new JLabel("num2");
		userAnswerText=new JTextField(5);
		newProBtn=new JButton(" next");
		pCenter.add(idLbl);
		pCenter.add(new JLabel(" ). "));
		pCenter.add(num1Lbl);
		pCenter.add(operLbl);
		pCenter.add(num2Lbl);
		pCenter.add(new JLabel(" = "));
		pCenter.add(userAnswerText);
		pCenter.add(newProBtn);
		contentPane.add(pCenter,BorderLayout.CENTER);
		
		
		//(3)south
		//(3.1)
		JPanel pSouth1=new JPanel(new FlowLayout(FlowLayout.LEFT));
		firstBtn=new JButton("|<");
		preBtn=new JButton("<<");
		nextBtn=new JButton(">>");
		lastBtn=new JButton(">|");
		pageText=new JTextField(5);
		pageBtn=new JButton(" Go ");
		pSouth1.add(firstBtn);
		pSouth1.add(preBtn);
		pSouth1.add(nextBtn);
		pSouth1.add(lastBtn);
		pSouth1.add(new JLabel("    The"));
		pSouth1.add(pageText);
		pSouth1.add(new JLabel("th size"));
		pSouth1.add(pageBtn);
		
		//(3.2)操作按钮
		JPanel pSouth2=new JPanel(new FlowLayout(FlowLayout.RIGHT));
		sysTimeLbl=new JLabel("System Time");
		startBtn=new JButton("start");
		submitBtn=new JButton("submit");
		pSouth2.add(sysTimeLbl);
		pSouth2.add(startBtn);
		pSouth2.add(submitBtn);
		//(3.3)整合
		JPanel pSouth=new JPanel(new GridLayout(2,1));
		pSouth.add(pSouth1);
		pSouth.add(pSouth2);
		contentPane.add(pSouth,BorderLayout.SOUTH);

		setBtnFont
			(newProBtn,
					firstBtn,preBtn,nextBtn,lastBtn,
					pageBtn,startBtn,submitBtn);
		setLblFont
			(examTimeLbl,informLbl,idLbl,num1Lbl,
					operLbl,num2Lbl,sysTimeLbl);

		CommonService.setBtnEnabled
		(false,newProBtn,
				firstBtn,preBtn,nextBtn,lastBtn,
				pageBtn,submitBtn);
		CommonService.setTextEnabled
		(false,userAnswerText,pageText);
		CommonService.addBtnListener
		(this,newProBtn,firstBtn,preBtn,nextBtn,
				lastBtn,pageBtn,startBtn,submitBtn);
		CommonService.addTextListener(this,userAnswerText,pageText);
		
	}
	
	//显示当前操作的题目
	public void showCurrentProblem()
	{
		Problem problem=user.getProList().get(currentId-1);
		
		idLbl.setText(problem.getId()+"");
		num1Lbl.setText(problem.getNum1()+"");
		operLbl.setText(problem.getOper()+"");
		num2Lbl.setText(problem.getNum2()+"");
		int answerValue=problem.getUserAnswer();
		if(answerValue==-1)
			userAnswerText.setText("");
		else
			userAnswerText.setText(answerValue+"");
		
		
		//刷新按钮状态
		setBtn();
		
	}
	
	//设置翻动按钮及跳转状态
	public void setBtn()
	{
		int size=user.getProList().size();
		//可以跳转
		if(size>1)
		{
			pageText.setEnabled(true);
			pageBtn.setEnabled(true);
		}
		if(currentId==1&&size>1)
		{
			CommonService.setBtnEnabled(false,firstBtn,preBtn);
			CommonService.setBtnEnabled(true, nextBtn,lastBtn);
		}
		else if(currentId>1&&currentId<size)
		{
			CommonService.setBtnEnabled(true, firstBtn,preBtn,nextBtn,lastBtn);
		}
		else if(currentId==size&&size>1)
		{
			CommonService.setBtnEnabled(true,firstBtn,preBtn);
			CommonService.setBtnEnabled(false, nextBtn,lastBtn);
		}
		else
		{
			CommonService.setBtnEnabled(false, firstBtn,preBtn,nextBtn,lastBtn);
		}
	}
	
	//保存当前题目
	//true->跳转->放弃，有效范围的答案
	//false->不跳转->非法字符，或超出范围的答案
	public boolean saveCurrentProblem()
	{
		String answerStr=
			CommonService.handlerString(userAnswerText.getText());
		//(1)放弃
		if(answerStr.length()==0)
		{
			informLbl.setText("You give up the "+currentId+"th size");
			user.getProList().get(currentId-1).setUserAnswer(-1);
			return true;
		}
		//(2)
		try
		{
			int answerValue=Integer.parseInt(answerStr);
			//（2）答案是否在有效范围
			if(answerValue<0||answerValue>1000)
			{
				informLbl.setText("You answer beyonds available range![0,1000]");
				return false;
			}
			//(3)正常保存
			user.getProList().get(currentId-1).setUserAnswer(answerValue);
			return true;
			
		}catch(Exception e)
		{
			//(4)非法字符
			informLbl.setText("You answer contains informed string");
			return false;
		}
	}
	
	//集中式事件处理
	public void actionPerformed(ActionEvent e)
	{
		//产生新题
		if(e.getSource()==userAnswerText||
				e.getSource()==newProBtn)
		{
			if(!saveCurrentProblem())
			{
				userAnswerText.setText("");
				userAnswerText.grabFocus();
				return;
			}
			ExamService.getProblem(user);
			currentId=user.getProList().size();
			showCurrentProblem();
			userAnswerText.setText("");
			userAnswerText.grabFocus();
			return;
		}

		if(e.getSource()==firstBtn)
		{
			if(!saveCurrentProblem())
			{
				userAnswerText.setText("");
				userAnswerText.grabFocus();
				return;
			}
			currentId=1;
			showCurrentProblem();
		}
		
		if(e.getSource()==preBtn)
		{
			if(!saveCurrentProblem())
			{
				userAnswerText.setText("");
				userAnswerText.grabFocus();
				return;
			}
			currentId--;
			showCurrentProblem();
		}
		
		if(e.getSource()==nextBtn)
		{
			if(!saveCurrentProblem())
			{
				userAnswerText.setText("");
				userAnswerText.grabFocus();
				return;
			}
			currentId++;
			showCurrentProblem();
		}
		
		
		if(e.getSource()==lastBtn)
		{
			if(!saveCurrentProblem())
			{
				userAnswerText.setText("");
				userAnswerText.grabFocus();
				return;
			}
			currentId=user.getProList().size();
			showCurrentProblem();
		}
		
		//跳转
		if(e.getSource()==pageText||
				e.getSource()==pageBtn)
		{
			String valueStr=
				CommonService.handlerString(pageText.getText());
			
			//（1）输入空格的判断
			if(valueStr.length()==0)
  			{
  				informLbl.setText("Please input available string instead of !");
  				pageText.setText("");
  				pageText.grabFocus();
  				return;
  			}
  			
  		    try
  		    {
  			int value=Integer.parseInt(valueStr);
            // System.out.println(value);
  			int size=user.getProList().size();
  			//(2)题号超出范围的判断 
  			if(value<1||value>size)
  			{
  				informLbl.setText("Your inputing beyongs the range[1,"+size+"]！");
  				pageText.setText("");
  				pageText.grabFocus();
  				return;
  			}
  			
  			if(!saveCurrentProblem())
  			{
  				userAnswerText.setText("");
  				userAnswerText.grabFocus();
  				return;
  			}
  			//(3)正常跳转，刷新currentId
  			currentId=value;
  			showCurrentProblem();
  			pageText.setText("");
			pageText.grabFocus();
			return;
  			}catch(Exception e1)
  			{
  				//(4)非法字符输入
  				informLbl.setText("You inputing contains informed string!");
  				pageText.setText("");
  				pageText.grabFocus();
  		    }
  			int value=Integer.parseInt(valueStr);
			System.out.println(value);
		}
		
		if(e.getSource()==pageBtn){}
		
		if(e.getSource()==startBtn)
		{
			newProBtn.setEnabled(true);
			startBtn.setEnabled(false);
			userAnswerText.setEnabled(true);
			userAnswerText.grabFocus();
			ExamService.getProblem(user);
			currentId=1;
			showCurrentProblem();
			examTimer.start();
			
			return;
		}
		
		if(e.getSource()==submitBtn)
		{
			saveCurrentProblem();
			(new CentGUI(user)).go();
			examTimer.stop();
			sysTimer.stop();
			frame.hide();
			return;
		}
		
		//倒计时
		if(e.getSource()==examTimer)
		{
			String str=examTimeLbl.getText();
			String subStr []=str.split(":");
			int value []=new int[3];
			for(int i=0;i<3;i++)
			{
				//将字符串转换成整数
				value[i]=Integer.parseInt(subStr[i]);
			}
			
			//考试结束的判断
			if(value[0]==0&&
					value[1]==0&&
					value[2]==0)
			{
				saveCurrentProblem();
				(new CentGUI(user)).go();
				examTimer.stop();
				sysTimer.stop();
				frame.hide();
				return;
			}
			
			//考试开始一段时间交卷按钮可以使用
			if(value[0]==0&&
					value[1]==59&&
					value[2]==55)
			{
				submitBtn.setEnabled(true);
			}
			
			//距离考试结束一段时间自动提醒
			if(value[0]==0&&
					value[1]==59&&
					value[2]==50)
			{
				informLbl.setText("The exam will be over!");
			}
			
			//倒计时计算
			value[2]--;
			if(value[2]<0)
			{
				value[2]=59;
				value[1]--;
				if(value[1]<0)
				{
					value[1]=59;
					value[0]--;
				}
			}
			
			
			//字符串连接
			for(int i=0;i<3;i++)
			{
				if(value[i]>10)
					subStr[i]=value[i]+"";
				else
					subStr[i]="0"+value[i];
			}
			examTimeLbl.setText
			(subStr[0]+":"+subStr[1]+":"+subStr[2]);
			
		}
		
		//时间显示
		
		if(e.getSource()==sysTimer)
		{
			sysTimeLbl.setText
				(new java.util.Date().toLocaleString());
		}
	}
	
	
	
	public void setBtnFont(JButton...btns)
	{
		for(JButton btn:btns)
				btn.setFont(new Font("",Font.BOLD,18));
	}
	
	public void setLblFont(JLabel...lbls)
	{
		for(JLabel lbl:lbls)
			lbl.setFont(new Font("",Font.BOLD,18));
	}
	
	
	public void go()
	{
		frame.setVisible(true);
	}
	

	public static void main(String[] args) 
	{
		(new ExamGUI(null)).go();
	}

}
