#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"

int debug_mode;
const int NORMAL_END = 0;
const int ABNORMAL_END = -1;
const char *FILE_PATH = "./resource/bulk_insert.sql";
const int MAX_INSERT_STR_LENGTH = 5000;
const int MAX_INSERT_LINES = 9;
int main(void){
    debug_mode = ENABLE_DEBUG_MODE;
    
    FILE *fp;
    debug("start read file filepath:[%s]\n", FILE_PATH);
    fp = fopen(FILE_PATH, "r");
    if (fp == NULL){
        perror("fopen");
        error(" invalid file filepath: [%s]\n", FILE_PATH);
        return ABNORMAL_END;
    }

    char (*lines)[5000] = (char*) malloc(sizeof(char) *  MAX_INSERT_STR_LENGTH * MAX_INSERT_LINES);
    if (lines == NULL){
        error(" faild calloc\n");
        return ABNORMAL_END;
    }
    char line[1024];
    for (int i = 0; fgets(line, sizeof(line), fp); i++){
        if (i != 0 && i % MAX_INSERT_LINES == 0){
            debug(" strcated lines to line\n [%s]\n", lines);
            info(" resets the count because the row size has reached its maximum\n");
            free(lines);
            lines = (char*) malloc(sizeof(char) *  MAX_INSERT_STR_LENGTH * MAX_INSERT_LINES);
        }
        strcat(*lines, line);
    }
    if (ferror(fp)){
        fprintf(stderr, " invalid file\n");
        return ABNORMAL_END;
    }
    debug("before free variable lines\n [%s] \n", lines);
    free(lines);
    debug("freed variable lines\n");
    fclose(fp);

    debug("finish read file filepath:[%s]\n", FILE_PATH);

    return NORMAL_END;
}