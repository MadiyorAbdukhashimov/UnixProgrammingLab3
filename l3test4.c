#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



int main(int argc, char const *argv[])
{
    DIR *dp = opendir("./"); // we are just opening the current directory
    struct dirent *dir;
    struct stat st;
    mode_t bits;
    char *pathName;

    char *time1;
    time_t t = time(0);
    struct tm *tm = localtime(&t);
    time_t t2;

    char today[32];
    strftime(today, sizeof(today), "%c", tm);

    pathName = (char *)(malloc(sizeof(char)*strlen(argv[1])));
    chdir(pathName);

    printf("%s\n\n", today);
    while((dir = readdir(dp)) != NULL){
        if (stat(dir->d_name, &st)) {
            printf("error in: stat(%s, &n)\n", dir->d_name);
            continue;
        }
        if(S_ISREG(st.st_mode)){
            if (difftime(t, st.st_atime)/86400 > 1) {
                printf("%s\n", dir->d_name);
            }
        }
    }
    closedir(dp);
    return 0;
}