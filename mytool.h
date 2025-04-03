
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
*   filelist fl;
*   search_file_by_ext("/repo/mp3", "mp3", &fl);
*   for (int i = 0; i < fl.file_nums; i++) {
*       printf("%d - %s\n", i, fl.list[i]);
*   }
**/ 
int search_file_by_ext(char* path, char* ext, filelist *fl);

#endif
