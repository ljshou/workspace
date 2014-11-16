# -*- coding: UTF-8 -*- 
# server.py

from wsgiref.simple_server import make_server
from hello import application

# 创建一个服务器，IP地址为空，端口号是8000, 处理函数是 application:
http = make_server('', 8000, application)
print "Serving HTTP on port 8000"

# 开始监听HTTP请求
http.serve_forever()


