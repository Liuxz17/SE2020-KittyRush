import socket
from globals import *

class my_client():
    def __init__(self):
        self.client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        self.info = information()
    def conn(self,ip,port=8888):
        self.client.connect((ip, port))
    def disconn(self):
        self.client.close()

    def send(self, msg):
        self.client.send(msg.encode('utf-8'))
    def recv(self, buffer=1024):
         return self.client.recv(buffer).decode('utf-8')
    def confirm(self):
        if self.recv()=='OK':
            return 0
        elif self.recv()=='error':
            return 1
        else:
            return -1

    def send_to_server(self,input):  #将input发送给服务器，input为information类的对象
        self.send(input.get_database())
        if self.confirm() != 0:
            return -1

        self.send(input.get_title())
        if self.confirm() != 0:
            return -1

        self.send(input.get_origin())
        if self.confirm() != 0:
            return -1

        self.send(input.get_cite_number())
        if self.confirm() != 0:
            return -1

        self.send(input.get_date())
        if self.confirm() != 0:
            return -1

        self.send(input.get_doi())
        if self.confirm() != 0:
            return -1

        self.send(input.get_abstract())
        if self.confirm() != 0:
            return -1

        for i in range(len_author):
            self.send(input.get_author(i))
            if self.confirm() != 0:
                return -1
        for i in range(len_key):
            self.send(input.get_key_word(i))
            if self.confirm() != 0:
                return -1
        for i in range(len_ref):
            self.send(input.get_ref(i))
            if self.confirm() != 0:
                return -1
        return 0


    def recv_from_server(self):  # 接收后存储在self.info
        self.info.set_database(self.recv())  # 调用self.info的成员函数将收到的信息存入database，下同
        self.send(suc_msg)  # 发送成功接收的消息号接收下一个
        print('database: ', self.info.get_database())

        self.info.set_title(self.recv())
        self.send(suc_msg)
        print('title: ', self.info.get_title())

        self.info.set_origin(self.recv())
        self.send(suc_msg)
        print('origin: ', self.info.get_origin())

        self.info.set_cite_number(self.recv())
        self.send(suc_msg)
        print('site_number: ', self.info.get_cite_number())

        self.info.set_date(self.recv())
        self.send(suc_msg)
        print('date: ', self.info.get_date())

        self.info.set_doi(self.recv())
        self.send(suc_msg)
        print('doi: ', self.info.get_doi())

        self.info.set_abstract(self.recv())
        self.send(suc_msg)
        print('abstract: ', self.info.get_abstract())

        for i in range(len_author):  # 个数由作者个数决定
            self.info.set_author(self.recv(), i)
            self.send(suc_msg)
        print('author:', self.info.get_author(i))

        for i in range(len_key):  # 个数由关键词个数决定
            self.info.set_key_word(self.recv(), i)
            self.send(suc_msg)
        print('key_word:', self.info.get_key_word(i))

        for i in range(len_ref):  # 个数由关键词个数决定
            self.info.set_ref(self.recv(), i)
            self.send(suc_msg)
        print('ref:', self.info.get_ref(i))


def send_info(addr, input ):  #向服务器发送input中存储的此文献信息，注意不是成员函数，为了调用方便;addr为服务器ip地址
    msg = 'send'  #标识是发送指令而非搜索相似文献指令
    clt = my_client()    #实例化
    clt.conn(addr)
    clt.send(msg)
    if clt.confirm() != 0:
        return -1
    if(clt.send_to_server(input)!=0):#发送异常
        return -1
    msg='finish'
    clt.send(msg)
    clt.disconn()
    del clt
    return 0

def search_info(addr,input):   #搜索相似文献,output为写入的位置
    msg = 'search'  # 标识是发送指令而非搜索相似文献指令
    clt = my_client()  # 实例化
    clt.conn(addr)
    clt.send(msg)
    if clt.confirm() != 0:
        return -1
    if (clt.send_to_server(input) != 0):  # 发送异常
        return -1
    msg = 'quest_info'
    clt.send(msg)
    if clt.confirm() != 0:
        return -1
    clt.recv_from_server()
    print('Search OK!')
    result = clt.info
    clt.disconn()
    del clt
    return result

if __name__ =='__main__':    #一个小测试
    info = information()
    info.set_database('unknown database')
    info.set_title('This is title')
    info.set_cite_number('999')
    info.content['author']=['Alpha','Beta','Gamma','Delta','Epsilon','Omega']
    info.content['key_word']=['key_word1','2','3']
    info.set_origin('origin unknown')
    info.set_date('I am date')
    for i in range(len_ref):
        info.set_ref('reference',i)
    info.set_doi('www.xxx.com')
    info.set_abstract('I have nothing to talk about.')

    send_info(addr=socket.gethostbyname(socket.gethostname()), input=info)    #自己ip地址做服务器
    print(search_info(addr=socket.gethostbyname(socket.gethostname()), input=info).content)
