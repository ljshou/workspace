#include "unp.h"

int main(int argc,char **argv)
{
	//如果程序参数格式不正确
	if (argc != 2)
	{
		err_quit("usage: a.out <IPaddress>");
	}

	//创建一个TCP套接字，返回sockfd作为套接字描述符
	int sockfd;
	if ((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		err_sys("socket error");
	}

	/*
	指定服务器的IP地址与端口
	*/
	struct sockaddr_in servaddr;
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(9999);//解释见服务器程序
	//inet_pton("呈现形式到数值")，把ASCII命令行参数转换为合适的格式
	//argv[1]代表服务器IP地址
	if (inet_pton(AF_INET,argv[1],&servaddr.sin_addr) < 0)
	{
		err_quit("inet_pton err for %s",argv[1]);
	}

	/*
	建立与服务器的连接
	connect函数应用于一个TCP套接字时，将与由他的第二个参数只想的套接字地址结构
	指定的服务器建立一个TCP连接。
	在unp.h头文件中，将SA定义为struct sockaddr。
	*/
	if (connect(sockfd,(SA *)&servaddr,sizeof(servaddr)) < 0)
	{
		err_sys("connect error");
	}

	/*
	读入并输出服务器的应答：
	**使用TCP时必须小心，因为TCP是一个没有记录边界的字节流协议
	*/
	int n;
	char recvline[MAXLINE + 1];
	//如果数据量很大，我们不能保证一次read就可一返回服务器的所有应答。
	//当read返回0(对端关闭连接)或者负值(发生错误)时，终止循环。
	while ((n = read(sockfd,recvline,MAXLINE)) > 0)
	{
		recvline[n] = 0;
		if (fputs(recvline,stdout) == EOF)
		{
			err_sys("fputs error");
		}
	}
	if (n < 0)
	{
		err_sys("read error");
	}

	/*
	exit终止程序运行，UNIX在一个进程终止时总是关闭该进程所有打开的
	描述符，我们的TCP套接字就此关闭！
	*/
	exit(0);
}

