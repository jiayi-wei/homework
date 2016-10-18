from lxml import html
from time import sleep
import os

homework_path="D:\\homework.txt"
page="http://bbs.hupu.com/vote"
page_ori="http://bbs.hupu.com/"
next_button="//a[@class='next']/@href"
title_string="//a[@id='']/font/text()|//a[@id=''][@href]/b/font/text()|//a[@id=''][@href]/b/text()|//a[@id=''][@href]/text()"
author_string="//a[@class='u']/text()"
time_string="//td[@class='p_author']/text()[preceding-sibling::br]"
reply_string="//td[@class='p_re']/text()"
last_time_reply_string="//td[@class='p_retime']/text()[preceding-sibling::br]"
last_time_string="//a[@title='查看最后回复']/text()"

i=0
while(i<10):
    x = html.parse(page)
    titles = x.xpath(title_string)
    authors=x.xpath(author_string)
    time_=x.xpath(time_string)
    replys=x.xpath(reply_string)
    last_time_reply=x.xpath(last_time_reply_string)
    last_time=x.xpath(last_time_string)
    j=0
    with open(homework_path,'a',encoding='utf-8')as f:
        f.write("-*****第%d页的内容*****-"%(i+1)+'\n')
    while j<len(titles):
        try:
            with open(homework_path,'a')as f:
                f.write("title:               "+titles[j]+'\n')
                f.write("author:              "+authors[j+19]+'\n')
                f.write("release time:        "+time_[j]+'\n')
                f.write("replys/browse:       "+replys[j]+'\n')
                f.write("lastes reply time:   "+last_time_reply[j]+'\n')
                f.write("lastes reply author: "+last_time[j]+'\n')
                f.write('------------\n\n')
            j+=1
        except:
            print(titles[i])
            j+=1
    pages=x.xpath(next_button)
    page=page_ori+pages[0]
    i=i+1
    sleep(3)
    
