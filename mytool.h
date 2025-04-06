
#ifndef MYTOOL_H
#define MYTOOL_H
/**
 * the return type of list_dir
 * void *list would be char[file_numbers][100]
 **/
typedef struct {
    int file_nums;
    char list[100][100];
} filelist;

/**
* search file recursively by ext
* path : directory path
* ext: the extension of the file to obtained
* fl: the filelist to be returned 
* eg:  
    filelist fl;
    char *buf[100] = {
        ".mp3",
        ".flac"
    };
    
    search_file_by_multi_ext("/repo/mp3", buf, 2, &fl);
    for (int i = 0; i < fl.file_nums; i++) {
        printf("%d - %s\n", i, fl.list[i]);
    }
    printf("size: %d\n", fl.file_nums);
**/ 
int search_file_by_ext(char* path, char* ext, filelist *fl);

/**
* search file recursively by multiple ext
* path : directory path
* ext: the extension of the file to obtained
* fl: the filelist to be returned 
* eg:  
*   filelist fl;
*   search_file_by_ext("/repo/mp3", "mp3", &fl);
*   for (int i = 0; i < fl.file_nums; i++) {
*       printf("%d - %s\n", i, fl.list[i]);
*   }
**/ 
int search_file_by_multi_ext(char* path, char** ext, int ext_len, filelist *fl);

/**
* check the exists of a directory
* return:
*     0, not exists
*     1, exists
*    -1, error  
*
*   filelist fl;
*   char *buf[100] = {
*       ".mp3",
*       ".flac"
*   };
*   
*   search_file_by_multi_ext("/repo/mp3", buf, 2, &fl);
*   for (int i = 0; i < fl.file_nums; i++) {
*       printf("%d - %s\n", i, fl.list[i]);
*   }
*   printf("size: %d\n", fl.file_nums);
*
**/   
int check_file_or_dir_exists(const char *path);



#endif
