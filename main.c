#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include "mytool.h"

int main(int argc, char **argv) {
    // char buf[100];
    // printf("sizeof buf %lu\n", sizeof(buf));
    // getcwd(buf, sizeof(buf));
    // printf("%s\n", buf);
    //
    // DIR *dir = opendir(argv[1]);
    // struct dirent * entry;
    // while ((entry = readdir(dir)) != NULL) {
    //     int len = strlen(entry->d_name);
    //     if(strcmp(entry->d_name + len -4, ".mp3") == 0){
    //         printf("%s\n", entry->d_name);
    //     }
    // }
    //
    // closedir(dir);
    // filelist fl;
    // search_file_by_ext("/repo/mp3", "mp3", &fl);
    // for (int i = 0; i < fl.file_nums; i++) {
    //     printf("%d - %s\n", i, fl.list[i]);
    // }
    // printf("size: %d\n", fl.file_nums);
    char *path = "/tmp/aaa";
    printf("aaa %d\n", check_file_or_dir_exists(path));
    char *path1 = "/tmp/zim-6vuzhf2l";
    printf("%d\n", check_file_or_dir_exists(path1));
    char *path2 = "/tmp/ibus.log";
    printf("%d\n", check_file_or_dir_exists(path2));
    char *path3 = "/tmp/ibus1.log";
    printf("%d\n", check_file_or_dir_exists(path3));
    return 0;
}
