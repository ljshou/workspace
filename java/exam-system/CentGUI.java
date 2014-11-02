//统计分数
package com.exam;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import com.common.*;

public class CentGUI implements ActionListener
{
	private JFrame frame;
	private Container contentPane;
	
	//north
	private JLabel centLbl;//显示分数
	
	//center:每页5条记录
	private JLabel idLbl []=new JLabel[5];//序号
	private JTextField proIdText []=new JTextField[5];//题号
	private JTextField problemText []=new JTextField[5];//题目
	private JLabel userAnswerLbl []=new JLabel[5];//用户答案
	private JLabel answerLbl []=new JLabel[5];//正确答案
	private JLabel proCentLbl []=new JLabel[5];//分数
	
	
	
	//south
	private JButton firstBtn,preBtn,nextBtn,lastBtn;//题页
	private JTextField pageText;
	private JButton pageBtn;//跳转
	private JButton exitBtn;//退出
	//---------------------------------------------------
	private User user;
	private int currentId;//当前操作页码
	
	
	public CentGUI(User user)
	{
		this.user=user;
		if(user==null)
		{
			//System.exit(0);
			this.user=new User();
			this.user.setUserName("visitor");
		}
	
		frame=new JFrame(this.user.getUserName()+"Cent static:  ");
		frame.setBounds(350,300,700,300);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		contentPane=frame.getContentPane();
		initGUI();
	}

	public void initGUI()
	{
		contentPane.setLayout(new BorderLayout());
		//north
		JPanel pCenter=new JPanel(new FlowLayout());
		centLbl=new JLabel("score");
		centLbl.setFont(new Font("",Font.BOLD,18));
		pCenter.add(centLbl);
		contentPane.add(pCenter,BorderLayout.NORTH);
		//center
		JPanel p=new JPanel(new GridLayout(6,6));
		p.add(new JLabel("*Number*"));
		p.add(new JLabel("*Size*"));
		p.add(new JLabel("*Problem*"));
		p.add(new JLabel("*Your answer*"));
		p.add(new JLabel("*Right answer*"));
		p.add(new JLabel("*Score*"));
		
		for(int i=0;i<5;i++)
		{
			idLbl[i]=new JLabel("id");
			proIdText[i]=new JTextField("proId");
			problemText[i]=new JTextField("problem");
			userAnswerLbl[i]=new JLabel("userA");
			answerLbl[i]=new JLabel("answer");
			proCentLbl[i]=new JLabel("cent");
			p.add(idLbl[i]);
			p.add(proIdText[i]);
			p.add(problemText[i]);
			p.add(userAnswerLbl[i]);
			p.add(answerLbl[i]);
			p.add(proCentLbl[i]);
			
			idLbl[i].setFont(new Font("",Font.BOLD,16));
			proIdText[i].setFont(new Font("",Font.BOLD,16));
			problemText[i].setFont(new Font("",Font.BOLD,12));
			userAnswerLbl[i].setFont(new Font("",Font.BOLD,16));
			answerLbl[i].setFont(new Font("",Font.BOLD,16));
			proCentLbl[i].setFont(new Font("",Font.BOLD,14));
		}
		contentPane.add(p,BorderLayout.CENTER);
		
		//south
		JPanel pSouth=new JPanel(new FlowLayout());
		firstBtn=new JButton("First page");
		preBtn=new JButton("Previous page");
		nextBtn=new JButton("Next page");
		lastBtn=new JButton("Last page");
		pageText=new JTextField(5);
		pageBtn=new JButton(" Go");
		exitBtn=new JButton("Exit");
		pSouth.add(firstBtn);
		pSouth.add(preBtn);
		pSouth.add(nextBtn);
		pSouth.add(lastBtn);
		pSouth.add(new JLabel(" the"));
		pSouth.add(pageText);
		pSouth.add(new JLabel(" th page"));
		pSouth.add(pageBtn);
		pSouth.add(exitBtn);
		contentPane.add(pSouth,BorderLayout.SOUTH);
		CommonService.addBtnListener
				(this,firstBtn,preBtn,nextBtn,lastBtn,pageBtn,exitBtn);
		pageText.addActionListener(this);
		
		pageText.setEnabled(false);
		pageBtn.setEnabled(false);
		
		int maxPage=getMaxPage();
		if(maxPage>0)
		{
			currentId=1;
			showCurrentPage();
		}
	}
	//显示当前的页面
	public void showCurrentPage()
	{
		for(int i=0;i<5;i++)
		{
			idLbl[i].setText("");
			proIdText[i].setText("");
			problemText[i].setText("");
			userAnswerLbl[i].setText("");
			answerLbl[i].setText("");
			proCentLbl[i].setText("");
		}
		int maxIndex=
			user.getProList().size();
		if(currentId*5<maxIndex)
			maxIndex=currentId*5;
		java.util.List<Problem> subProList=
			user.getProList().subList
			((currentId-1)*5,maxIndex);
		int i=0;
		for(Problem p:subProList)
		{
			idLbl[i].setText("  "+((currentId-1)+(i+1)));
			proIdText[i].setText("  "+p.getId());
			problemText[i].setText("  "+p.toString());
			int userAnswer=p.getUserAnswer();
			if(userAnswer==-1)
				userAnswerLbl[i].setText("no answer!");
			else
				userAnswerLbl[i].setText("   "+userAnswer);
			answerLbl[i].setText("  "+p.getAnswer());
			if(userAnswer==-1)
			{
				proCentLbl[i].setText("you give up/0");
			}
			else if(userAnswer==p.getAnswer())
			{
				proCentLbl[i].setText("correct/10");
			}
			else
			{
				proCentLbl[i].setText("false/0");
			}
			i++;
		}
		
		setBtn();
	}
	//刷新翻动按钮及跳转状态
	public void setBtn()
	{
		int maxPage=getMaxPage();
		if(maxPage>1)
		{
			pageText.setEnabled(true);
			pageBtn.setEnabled(true);
			pageText.grabFocus();
		}
		if(currentId==1&&maxPage>1)
		{
			CommonService.setBtnEnabled(false,firstBtn,preBtn);
			CommonService.setBtnEnabled(true,nextBtn,lastBtn);
		}
		else if(currentId>1&&currentId<maxPage)
		{
			CommonService.setBtnEnabled(true,firstBtn,preBtn,nextBtn,lastBtn);
		}
		else if(currentId==maxPage&&maxPage>1)
		{
			CommonService.setBtnEnabled(true,firstBtn,preBtn);
			CommonService.setBtnEnabled(false,nextBtn,lastBtn);
		}
		else
		{
			CommonService.setBtnEnabled(false,firstBtn,preBtn,nextBtn,lastBtn);
		}
		
	}
		
	
	
	//获取最大的页码
	public int getMaxPage()
	{
		int size=user.getProList().size();
		//满页
		if(size%5==0)
			return size/5;
		//半页
		return size/5+1;
	}
	
	//集中式事件处理
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==firstBtn){}
		if(e.getSource()==preBtn){}
		if(e.getSource()==nextBtn){}
		if(e.getSource()==lastBtn){}
		if(e.getSource()==pageText){}
		if(e.getSource()==pageBtn){}
		if(e.getSource()==exitBtn){}
		
	}
	
	public void go()
	{
		frame.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		(new CentGUI(null)).go();

	}

}
