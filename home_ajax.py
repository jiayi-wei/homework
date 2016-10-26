import requests
import json
import pprint
from lxml import html
import os
from time import sleep

uuu="http://www.shihuo.cn/shihuo/getList?pageSize=20&createTimestamp="
get_next="//li[last()]/@data-time"
url='http://www.shihuo.cn/'
homework_path="D:\\ajax_homework.txt"

x=html.parse(url)
next_dex=x.xpath(get_next)
url_new=uuu+next_dex[0]
list_titles=[]
list_intro=[]
list_price=[]
list_create_time=[]
list_orginal_type=[]
i=0

while i<10:
    cont=requests.get(url_new).content
    con=cont.decode('unicode_escape')
    result=json.loads(con.replace('\r\n', ''))
    datas=result['data']
    for data in datas:
        list_titles.append(data['data']['title'])
        list_intro.append(data['data']['intro'])
        list_price.append(data['data']['price'])
        list_create_time.append(data['data']['create_time'])
        list_orginal_type.append(data['data']['orginal_type'])
    url_new=uuu+str(data['data']['createTimestamp'])
    i+=1
    sleep(1)

j=0
while j<len(list_titles):
    with open(homework_path,'a') as f:
        f.write("title:        "+list_titles[j]+'\n')
        f.write("price:        "+list_price[j]+'\n')
        f.write("introduction: "+list_intro[j]+'\n')
        f.write("create time:  "+list_create_time[j]+'\n')
        f.write("source:       "+list_orginal_type[j]+'\n')
        f.write("--------------\n\n")



