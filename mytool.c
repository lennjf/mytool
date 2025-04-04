#include "mytool.h"
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>


int search_file_by_ext(char* path, char* ext, filelist *fl) {
    if(chdir(path) < 0){
        perror("path invalid");
        return -1;
    }
    char current_dir[100];
    getcwd(current_dir, sizeof(current_dir));
    printf("current dir : %s\n", current_dir);
    if(strlen(ext)<3){
        printf("extension invalid\n");
        return -1;
    }
    DIR *dir = opendir(".");
    if(dir == NULL){
        perror("open dir");
        return -1;
    }
    struct dirent * entry;
    while ((entry = readdir(dir)) != NULL) {
        if(entry->d_type == DT_REG){
            int filename_len = strlen(entry->d_name);
            int ext_len = strlen(ext);
            if(strcmp(entry->d_name + filename_len - ext_len, ext) == 0){
                char filename[100];
                sprintf(filename, "%s/%s", current_dir, entry->d_name);
                strcpy(fl->list[fl->file_nums], filename);
                fl->file_nums++;
            }
        }else if(entry->d_type == DT_DIR){
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;             
            }
            char filename[100];
            sprintf(filename, "%s/%s", current_dir, entry->d_name);
            if(search_file_by_ext(filename, ext, fl) < 0) {
                return -1;
            }
        }
    }
    closedir(dir);
    return 0;
}


int check_dir_exists(const char *path){
    struct stat exist_check;
    if(stat(path, &exist_check) == -1){
        if(errno == ENOENT){
            printf("path [%s] is not exists\n", path);
            return 0;
        }else {
            perror("check dir exists err");
            return -1;
        }
    }
    return 1;
}

