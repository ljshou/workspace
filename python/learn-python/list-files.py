#!/usr/bin/python
#coding=utf8

import os

def list_files_recursive(path):
    for file_name in os.listdir(path):
        file_path = os.path.join(path, file_name)
        if os.path.isdir(file_path):
            list_files_recursive(file_path)
        else:
            print file_path


def list_files(path):
    for parent, path_list, file_list in os.walk(path):
        for file_name in file_list:
            print os.path.join(parent, file_name)

if __name__ == '__main__':
    list_files_recursive(os.getcwd())
