require 'mkmf'

$LIBS += " -lfromfile -lnarray"
create_makefile "fromfile"