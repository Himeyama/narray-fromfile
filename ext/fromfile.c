/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#include <fromfile.h>
#include <ruby.h>
#include <numo/narray.h>

extern VALUE numo_cDFloat;

VALUE cFromfile;

VALUE numo_fromfile(VALUE self, VALUE filename){
    char* cfilename = StringValuePtr(filename);
    FILE* fp = fopen(cfilename, "r");
    long filesize;
    if(fp){
        if((filesize = fsize(fp)) == -1) return Qfalse;
        fclose(fp);
    }else{
        return Qfalse;
    }
    VALUE a = rb_funcall(numo_cDFloat, rb_intern("zeros"), 1, LONG2NUM(filesize / sizeof(double)));
    dFloatfromfilep(cfilename, (double*)na_get_pointer_for_read(a));
    return a;
}

void Init_fromfile(void){
    cFromfile = rb_define_module("Fromfile");
    rb_define_singleton_method(cFromfile, "fromfile", numo_fromfile, 1);
}