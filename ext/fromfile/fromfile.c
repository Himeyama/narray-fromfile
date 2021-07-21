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

VALUE numo_tofile(VALUE self, VALUE filename){
    char* cfilename = StringValuePtr(filename);
    DFloat data;
    data.data = (double*)na_get_pointer_for_read(self);
    data.size = NUM2LONG(rb_funcall(self, rb_intern("size"), 0));
    dFloat2file(cfilename, data);
    return self;
}

void Init_fromfile(void){
    rb_define_singleton_method(numo_cDFloat, "fromfile", numo_fromfile, 1);
    rb_define_method(numo_cDFloat, "tofile", numo_tofile, 1);
}