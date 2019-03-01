#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    DIR *dp = opendir("./"); // we are just opening the current directory
    struct dirent *dir;
    struct stat st;

    char *pathName;
    pathName = (char *)(malloc(sizeof(char)*strlen(argv[1])));
    chdir(pathName);
    while((dir = readdir(dp)) != NULL){
        if (lstat (dir->d_name, &st)) {
            printf("error in: stat(%s, &n)\n", dir->d_name);
            continue;
        }
        if(S_ISREG(st.st_mode)){
            if ((st.st_nlink) > 2) {
                printf(":::File Found with more than 2 links:::\n::: %s\n", dir->d_name);
            }
        }
    }
    closedir(dp);
    return 0;
}
