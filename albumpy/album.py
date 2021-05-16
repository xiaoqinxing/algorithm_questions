#coding: utf-8
from PIL import Image
import os
import sys
import json
from datetime import datetime
from ImageProcess import Graphics

def make_directory(directory):
    """创建目录"""
    os.makedirs(directory)

def directory_exists(directory):
    """判断目录是否存在"""
    if os.path.exists(directory):
        return True
    else:
        return False

def list_img_file(directory):
    """列出目录下所有文件，并筛选出图片文件列表返回"""
    old_list = os.listdir(directory)
#    print(old_list)
    new_list = []
    for filename in old_list:
        name, fileformat = filename.split(".")
        if fileformat.lower() == "jpg" or fileformat.lower() == "png" or fileformat.lower() == "gif" or fileformat.lower() == "jpeg":
            new_list.append(filename)
    # print new_list
    return new_list

def handle_photo():
    '''根据图片的文件名处理成需要的json格式的数据
    
    -----------
    最后将data.json文件存到博客的source/photos文件夹下
    '''
    src_dir = "photos/"
    file_list = list_img_file(src_dir)
    # print(file_list)
    list_info = []
    for i in range(len(file_list)):
        filename = file_list[i]
        info, _ = filename.split(".")
        t = os.path.getctime(src_dir+filename)
        tt = datetime.fromtimestamp(t)
        date_str = tt.strftime('%Y-%m-%d')
        year_month = date_str[0:7] 
        date = datetime.strptime(date_str, "%Y-%m-%d")
        """
        date_str, info = filename.split("_")
        info, _ = info.split(".")
        date = datetime.strptime(date_str, "%Y-%m-%d")
        year_month = date_str[0:7]            
        """
        if i == 0:  # 处理第一个文件
            new_dict = {"date": year_month, "arr":{'year': date.year,
                                                                   'month': date.month,
                                                                   'link': [filename],
                                                                   'text': [info],
                                                                   'type': ['image']
                                                                   }
                                        } 
            list_info.append(new_dict)
        elif year_month != list_info[-1]['date']:  # 不是最后的一个日期，就新建一个dict
            new_dict = {"date": year_month, "arr":{'year': date.year,
                                                   'month': date.month,
                                                   'link': [filename],
                                                   'text': [info],
                                                   'type': ['image']
                                                   }
                        }
            list_info.append(new_dict)
        else:  # 同一个日期
            list_info[-1]['arr']['link'].append(filename)
            list_info[-1]['arr']['text'].append(info)
            list_info[-1]['arr']['type'].append('image')
    list_info.reverse()  # 翻转
    tmp = bubbleYear(list_info)
    bubble(tmp)
    final_dict = {"list": list_info}
    with open("../blog/themes/next/source/lib/album/data.json","w") as fp:
        json.dump(final_dict, fp)

def bubble(bubbleList):
    listLength = len(bubbleList)
    while listLength > 0:
        for i in range(listLength - 1):    # 这个循环负责设置冒泡排序进行的次数
            # print(bubbleList[i])
            for j in range(listLength-i-1):  # ｊ为列表下标
                if(bubbleList[j].get('arr').get('year') == bubbleList[j+1].get('arr').get('year')):
                    if bubbleList[j].get('arr').get('month') < bubbleList[j+1].get('arr').get('month'):
                
                        bubbleList[j], bubbleList[j+1] = bubbleList[j+1], bubbleList[j]
        return bubbleList

    
        # for i in range(listLength - 1):
        #     if(bubbleList[i].get('arr').get('year') == bubbleList[i+1].get('arr').get('year')):
        #         if bubbleList[i].get('arr').get('month') > bubbleList[i+1].get('arr').get('month'):
        #             bubbleList[i] = bubbleList[i] + bubbleList[i+1]
        #             bubbleList[i+1] = bubbleList[i] - bubbleList[i+1]
        #             bubbleList[i] = bubbleList[i] - bubbleList[i+1]
        # listLength -= 1

def bubbleYear(bubbleList):
    listLength = len(bubbleList)
    while listLength > 0:
        for i in range(listLength - 1):
            for j in range(listLength-i-1):
                if bubbleList[j].get('arr').get('year') < bubbleList[j+1].get('arr').get('year'):
                    
                    bubbleList[j], bubbleList[j+1] = bubbleList[j+1], bubbleList[j]
        # print(bubbleList)
        return bubbleList
"""
def getExif(filename):
    FIELD = 'EXIF DateTimeOriginal'
    fd = open(filename, 'rb')
    tags = exifread.process_file(fd)
    fd.close()
    if FIELD in tags:
        new_name = str(tags[FIELD]).replace(':', '').replace(' ', '_') + os.path.splitext(filename)[1]
        tot = 1
        while os.path.exists(new_name):
            new_name = str(tags[FIELD]).replace(':', '').replace(' ', '_') + '_' + str(tot) + os.path.splitext(filename)[1]
            tot += 1
 
        new_name2 = new_name.split(".")[0] + '__' +filename
        print(new_name2)    
        os.rename(filename, new_name2)
    else:
        print('No {} found'.format(FIELD))

def getCreateTime(filename):
    createTime = os.path.getmtime(filename)
"""
if __name__ == "__main__":
    handle_photo()     # 将文件处理成json格式，存到博客仓库中