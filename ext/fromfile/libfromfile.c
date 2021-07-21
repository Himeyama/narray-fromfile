/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "fromfile.h"


// ファイルサイズを調べる
long fsize(const char* filename){
    struct stat s;
    if(stat(filename, &s) == 0)
        return s.st_size;
    return -1;
}


DFloat dFloat2file(const char* filename, DFloat data){
    FILE* fp;
    if(fp = fopen(filename, "w")){
        fwrite(data.data, sizeof(double), data.size, fp);
        fclose(fp);
    }else{
        exit(EXIT_FAILURE);
    }
    return data;
}


DFloat dFloatFromFile(const char* filename){
    FILE* fp;
    DFloat data;
    if(fp = fopen(filename, "r")){
        long filesize;
        if((filesize = fsize(filename)) == -1) exit(EXIT_FAILURE);
        data.data = (double*)malloc(filesize);
        data.size = filesize / sizeof(double);
        long len = fread(data.data, sizeof(double), filesize / sizeof(double), fp);
        fclose(fp);        
    }else{
        exit(EXIT_FAILURE);
    }
    return data;
}

DFloat dFloatFromFileP(const char* filename, double *p){
    FILE* fp;
    DFloat data;
    data.data = p;
    if(fp = fopen(filename, "r")){
        long filesize;
        if((filesize = fsize(filename)) == -1) exit(EXIT_FAILURE);
        data.size = filesize / sizeof(double);
        long len = fread(data.data, sizeof(double), filesize / sizeof(double), fp);
        fclose(fp);        
    }else{
        exit(EXIT_FAILURE);
    }
    return data;
}

void dFloatPrint(DFloat data){
    char* str = (char*)malloc(data.size * 16);
    char tmp[16];
    str[0] = '[';
    str[1] = 0;
    long sum = 0;
    for(long i = 0; i < data.size; i++){
        sum += sprintf(tmp, "%lf, ", data.data[i]);
        strcat(str, tmp);
    }
    str[sum-1] = ']';
    str[sum] = 0;
    puts(str);
    free(str);
}

void dFloatFree(DFloat data){
    free(data.data);
}