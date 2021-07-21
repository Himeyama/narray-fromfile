require 'mkmf'

narray_dir = Gem.find_files("numo")[0]
dir_config('narray', narray_dir, narray_dir)
have_library("narray")

create_makefile "fromfile"