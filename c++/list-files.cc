/**
 * @file list-files.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-03
 */

#include <iostream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

using namespace std;

vector<string> GetFiles(const string &str)
{
    vector<string> vec;

    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(str.c_str()); ///open the dir

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(ptr->d_type == 4) //normal file
            vec.push_back(ptr->d_name);
    }

    closedir(dir);
    return vec;
}

int len = 0;
int trave_dir(char* path)
{
    DIR *d; 
    struct dirent *file; 
    struct stat buf;    

    if(!(d = opendir(path)))
    {
        printf("error opendir %s!!!\\n",path);
        return -1;
    }
    chdir(path);//Add this, so that it can scan the children dir(please look at main() function)
    while((file = readdir(d)) != NULL)
    {

        if(strncmp(file->d_name, ".", 1) == 0)
            continue;
        if(stat(file->d_name, &buf) >= 0 && !S_ISDIR(buf.st_mode) )
        {
            printf("%s\n",file->d_name);
            //printf("\\tfile size=%d\\n",buf.st_size);
            //printf("\\tfile last modify time=%d\\n",buf.st_mtime);
        }

    }
    closedir(d);
    return 0;
}

int main()
{
    int i;
    trave_dir(".");//trave_dir("./ChildrenDir");
    return 0;
}
