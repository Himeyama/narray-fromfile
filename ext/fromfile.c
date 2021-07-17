/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#include <fromfile.h>
#include <ruby.h>
#include <numo/narray.h>

extern VALUE numo_cDFloat;

VALUE numo_fromfile(VALUE self, VALUE filename){
    char* cfilename = StringValuePtr(filename);
    long filesize = NUM2LONG(rb_funcall(rb_cFile, rb_intern("size"), 1, filename));
    VALUE a = rb_funcall(numo_cDFloat, rb_intern("zeros"), 1, LONG2NUM(filesize / sizeof(double)));
    dFloatFromFileP(cfilename, (double*)na_get_pointer_for_read(a));
    return a;
}

void Init_fromfile(void){
    rb_define_singleton_method(numo_cDFloat, "fromfile", numo_fromfile, 1);
}