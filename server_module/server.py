import socket  # 导入 socket 模块
from globals import * # 格式规定作为全局变量
class my_server():
    def __init__(self, ip, port=8888): #实例化时需给定IP地址，对服务器端可给定为本机地址并设置固定ip地址
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # 创建 socket 对象，使用tcp协议
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # 设置地址可重用
        self.server.bind((ip, port))  # 绑定端口
        self.info = information()
        self.recommend_info= information()
        self.client = None
        self.client_addr = None

    def conn(self, connect_number=5):
        self.server.listen(connect_number)  # 等待客户端连接
        self.client, self.client_addr = self.server.accept()  # 建立客户端连接
        print('Connected successfully', self.client_addr)

    def send(self, msg):  #采用utf-8编码，缓冲默认大小为1024
        self.client.send(msg.encode('utf-8'))
    def recv(self, buffer=1024):
         return self.client.recv(buffer).decode('utf-8')
    def confirm(self):  #用于确认对方已经收到消息
        if self.recv()=='OK':
            return 0
        elif self.recv()=='error':
            return 1
        else:
            return -1

    def recommend(self, rec_number=1):  #暂时只返回自身
        self.recommend_info=self.info

    def recv_from_client(self):     #按规定方式从客户端接收信息，并存入self.info
        self.info.set_database(self.recv())  #调用self.info的成员函数将收到的信息存入database，下同
        self.send(suc_msg)                   #发送成功接收的消息号接收下一个
        print('database: ', self.info.get_database())

        self.info.set_title (self.recv())
        self.send(suc_msg)
        print('title: ', self.info.get_title())

        self.info.set_origin (self.recv())
        self.send(suc_msg)
        print('origin: ', self.info.get_origin())

        self.info.set_cite_number (self.recv())
        self.send(suc_msg)
        print('site_number: ', self.info.get_cite_number())

        self.info.set_date (self.recv())
        self.send(suc_msg)
        print('date: ', self.info.get_date())

        self.info.set_doi (self.recv())
        self.send(suc_msg)
        print('doi: ', self.info.get_doi())

        self.info.set_abstract (self.recv())
        self.send(suc_msg)
        print('abstract: ', self.info.get_abstract())

        for i in range(len_author):  # 个数由作者个数决定
            self.info.set_author (self.recv(),i)
            self.send(suc_msg)
        print('author:', self.info.get_author(i))

        for i in range(len_key):  # 个数由关键词个数决定
            self.info.set_key_word (self.recv(),i)
            self.send(suc_msg)
        print('key_word:', self.info.get_key_word(i))

        for i in range(len_ref):  # 个数由关键词个数决定
            self.info.set_ref (self.recv(),i)
            self.send(suc_msg)
        print('ref:', self.info.get_ref(i))

    def send_to_client(self,input):  #将输入的input发送给客户端，输入的input是结构化的information对象
        self.send(input.get_database())
        if self.confirm()!=0:
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


if __name__ == '__main__' :
    Server = my_server(ip=socket.gethostbyname(socket.gethostname()))   #使用本机ip地址
    while True:
        Server.conn()  # 等待客户端连接，默认最大数为5
        try:
            quest = Server.recv()                #确认请求类型，包括’send'纯发送指令，和‘search’搜索相关文档指令
            if(quest=='send' or quest=='search'):  #收到发送文章信息或搜索请求
                print(quest,'quest received')
                Server.send(suc_msg)
                Server.recv_from_client()
                msg = Server.recv()
                if(msg=='finish'):
                    print('receive OK!')
                    continue
                #如果是搜索指令则搜索并回传推荐信息，否则直接断开
                elif(msg=='quest_info'):
                    Server.recommend()
                    Server.send(suc_msg)
                    Server.send_to_client(Server.recommend_info)
                else:
                    Server.send(err_msg)
                    continue
            else:
                Server.send(err_msg)
                continue
        except ConnectionResetError as e:
            print('connected error')
            break
    Server.close()

