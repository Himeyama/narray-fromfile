/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 *  source: https://github.com/Himeyama/C-Gaussian-Filter
 */


#ifndef FROMFILE_H
#define FROMFILE_H

typedef struct __DFloat{
    double* data;
    long size;
} DFloat;

long fsize(const char* filename);
DFloat dFloatFromFile(const char* filename);
void dFloatPrint(DFloat data);
void dFloatFree(DFloat data);
DFloat dFloat2file(const char* filename, DFloat data);
DFloat dFloatFromFileP(const char* filename, double *p);

#endif