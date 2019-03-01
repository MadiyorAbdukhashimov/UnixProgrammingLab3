#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// U1610131 - @author - Madiyor Abdukhashimov
// UNIX LAB ASSIGMENT NUMBER 3
// this program takes input from argument

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Please enter as ./exe pathName\n");
        exit(1);
    }
    
    DIR *dp = opendir("./"); // we are just opening the current directory
    struct dirent *dir;
    struct stat st;
    char *pathName;
    pathName = (char *)(malloc(sizeof(char)*strlen(argv[1])));
    chdir(pathName);
    while((dir = readdir(dp)) != NULL){
        if (stat(dir->d_name, &st)) {
            printf("error in: stat(%s, &n)\n", dir->d_name);
            continue;
        }
        if(S_ISREG(st.st_mode)){
            printf(":::Regular File Found::: %s\n", dir->d_name);
        }
    }
    closedir(dp);
    return 0;
}
