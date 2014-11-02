#include "unp.h"
#include <time.h>

int main(int argc,char **argv)
{
    int listenfd,connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    /*
    创建一个网际(AF_INET)字节流(SOCK_STREAM)套接字，
    并以listenfd返回其描述符。
    */
    listenfd = Socket(AF_INET,SOCK_STREAM,0);

    /*
    通过填写一个网际套接字地址结构并调用bind函数，将服务器的一个端口
    绑定到所创建的套接字上。
    */
    bzero(&servaddr,sizeof(servaddr));//bzero将整个结构体清零
    servaddr.sin_family = AF_INET;//将地址族设置为AF_INET
    /*
    INADDR_ANY：指定IP地址为INADDR_ANY，这样要是服务器主机
    有多个网络接口，服务器进程就可一在任意网路接口上接受连接。
    */
    servaddr.sin_addr.s_addr =htonl(INADDR_ANY);
	/*
	将服务器开放的端口设定为9999，原文中设定的是13，
	如果按照原文的示例，则该程序运行时需要获取root权限，才能申请使用13号端口
	但是在将服务器开放端口设为9999之后，需要在客户端程序的访问端口处，
	改为9999，不然会出现访问受限的情况！
	网际套接字地址结构中IP地址和端口号这两个成员必须使用特定格式，
	为此我们使用htons("主机到网络短整数")去转换二进制端口号。
	*/
    servaddr.sin_port = htons(9999);

    Bind(listenfd,(SA *) &servaddr,sizeof(servaddr));

    /*
    调用listen函数将该套接字转换成一个监听套接字，
    这样来自客户的外来连接就可以在该套接字上有内核接受
    */
    //LISTENQ指定系统内核允许在这个监听描述符上排队的最大客户连接数
    Listen(listenfd,LISTENQ);

	/*
	接受客户连接，发送应答
	*/
    for(;;)
    {
    	/*
    	TCP的三路握手，进行连接。
    	完成TCP连接之后，accept函数返回一个“已连接描述符”
		该描述符用于与新近连接的那个客户端进行通信。
		accept为每个连接到本服务器的客户返回一个新的描述符。
    	*/
        connfd = Accept(listenfd,(struct sockaddr *)NULL,NULL);

		//获取当前系统时间
        ticks = time(NULL);
        //ctime将整数值转换成直观可读的时间格式
        snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
        //write函数将把结果字符串写给客户
        Write(connfd,buff,strlen(buff));

		//终止连接，TCP的四次挥手
        Close(connfd);
    }

    exit(0);
}

