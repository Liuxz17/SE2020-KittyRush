import requests
import time
from bs4 import BeautifulSoup
import os
import random


def get_one_page(url):
    response = requests.get(url)
    print(response.status_code)
    while response.status_code == 403:
        time.sleep(500 + random.uniform(0, 500))
        response = requests.get(url)
        print(response.status_code)
    print(response.status_code)
    if response.status_code == 200:
        return response.text

    return None


def download(title, save_path, web='arxiv'):
    title_split = title.split()
    if web == 'arxiv':
        url = 'https://arxiv.org/search/?query='
        for str in title_split:
            if str[-1] == ':':
                url = url + str[0:-1] + '%3A' + '+'
            elif str[-1] == ',':
                url = url + str[0:-1] + '%2C' + '+'
            elif str[-1] == '?':
                url = url + str[0:-1] + '%3F' + '+'
            else:
                url = url + str + '+'
        url = url[0:-1] + '&searchtype=title&abstracts=hide&order=&size=50'
        # url = 'https://arxiv.org/search/?query=SOLO%3A+Segmenting%2C+Objects+by+Locations&searchtype=title&abstracts=hide&order=&size=50'

        html = requests.get(url)
        # strhtml = get_one_page(url)
        soup = BeautifulSoup(html.text, 'lxml')
        data = soup.select('#main-container > div.content > ol > li > div > p > span > a:nth-child(1)')
        link = data[0].get('href')

        if not os.path.exists(save_path):
            os.makedirs(save_path)

        pdf = requests.get(link)
        pdf_name = title.replace(': ', '_')
        pdf_root = os.path.join(save_path, pdf_name)
        with open(pdf_root + '.pdf', 'wb') as file:
            file.write(pdf.content)






if __name__ == '__main__':
    title = 'Depth Map Prediction from a Single Image using a Multi-Scale Deep Network'
    path = os.getcwd()
    download(title, path)
