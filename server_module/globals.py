#设置截断长度及占位符
null='&'
len_author = 6
len_key = 3
len_ref = 10
suc_msg = 'OK'
err_msg = 'error'
#定义信息存储结构
class information():
    def __init__(self):
        self.content = {'database':null, 'cite_number':null,'title':null,'author':[null for i in range(len_author)],
                     'key_word':[null for i in range(len_key)],'origin':null,'date':null,
                     'ref':[null for i in range(len_ref)],'doi':null,'abstract':null}
    def get_info(self):  #直接返回全部信息
        return self.content
    def get_database(self):
        return self.content['database']
    def get_cite_number(self):
        return self.content['cite_number']
    def get_title(self):
        return self.content['title']
    def get_author(self,index):  #返回单个作者，下同
        return self.content['author'][index]
    def get_key_word(self,index):
        return self.content['key_word'][index]
    def get_origin(self):
        return self.content['origin']
    def get_ref(self,index):
        return self.content['ref'][index]
    def get_doi(self):
        return self.content['doi']
    def get_date(self):
        return self.content['date']
    def get_abstract(self):
        return self.content['abstract']

    def set_database(self,database):  #以下分别输入信息，要求输入为字符串
        self.content['database'] = database
    def set_cite_number(self,cite_number):
        self.content['cite_number'] = cite_number
    def set_title(self,title):
        self.content['title'] = title
    def set_date(self,date):
        self.content['date'] = date
    def set_author(self,author,index):   #注意作者栏为list，此函数只提供添加单个作者，并标明排序，author为字符串而非list，以下皆如此
        if index in range(len_author):  #做截断，如果序号不在规定范围内直接跳过
            self.content['author'][index]=author
    def set_key_word(self,key_word,index):
        if index in range(len_key):
            self.content['key_word'][index] = key_word
    def set_origin(self,origin):
        self.content['origin'] = origin
    def set_ref(self,ref,index):
        if index in range(len_ref):
            self.content['ref'][index] = ref
    def set_doi(self, doi):
        self.content['doi'] = doi
    def set_abstract(self, abstract):
        self.content['abstract'] = abstract