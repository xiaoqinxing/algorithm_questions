# -*- coding: utf-8 -*-
'''
上传文件夹到七牛
'''

from qiniu import Auth, put_file
import os
import traceback

AK = '你的AK'
SK = '你的SK'
# 要上传的文件夹绝对路径
dir = 'C:\\tmp\public'

bucket_name = '空间名称'
q = Auth(AK, SK)
token = q.upload_token(bucket_name)

def updir(dirpath):
    if os.path.isdir(dirpath):#文件夹
        sublist = os.listdir(dirpath)
        for sub in sublist:
            updir(dirpath+'\\'+sub)
    else:#文件
        fpath, fname = os.path.split(dirpath)
        patharr = fpath.split('\\')
        try:
            key = getKey(dirpath)
            print key
            ret, info = put_file(token, key, dirpath)
            print ret
        except:
            traceback.print_exc()

def getKey(file):
    key = ''
    fpath, fname = os.path.split(file)
    patharr = fpath.split('\\')
    if len(patharr) >= 2:
        key = '/'.join(patharr[2:]) + '/' + fname
    else:
        key = fname
    return key

if __name__ == '__main__':
    updir(dir)