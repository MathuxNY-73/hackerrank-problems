
# A simple makefile template for creating a standalone executable Common Lisp image.
#
# Dependencies:
#  * SBCL
#  * Quicklisp
#
# Author: Smith Dhumbumroong <zodmaner@gmail.com>

SYSNAME = solve
TARGET = $(SYSNAME)
ENTRYFUNC = $(SYSNAME):main

all: $(TARGET)

$(TARGET): buildapp quicklisp-manifest.txt
	./buildapp --manifest-file quicklisp-manifest.txt \
			   --compress-core \
			   --load-system $(SYSNAME) \
			   --asdf-path "./" \
			   --entry $(ENTRYFUNC) \
			   --output $(TARGET)

quicklisp-manifest.txt:
	sbcl --no-userinit --no-sysinit --non-interactive \
		 --load ~/.quicklisp/setup.lisp \
		 --eval '(load "$(SYSNAME).asd")' \
		 --eval '(ql:quickload "$(SYSNAME)")' \
		 --eval '(ql:write-asdf-manifest-file "quicklisp-manifest.txt")'

buildapp:
	sbcl --no-userinit --no-sysinit --non-interactive \
		 --load ~/.quicklisp/setup.lisp \
		 --eval '(ql:quickload "buildapp")' \
		 --eval '(buildapp:build-buildapp)'

clean:
	-rm quicklisp-manifest.txt.SUFFIXES: .o .lsp . lisp

build:
	sbcl --load main.lisp \
	     --eval '(ql:quickload :main)' \
       --eval "(sb-ext:save-lisp-and-die #p\"main\" :toplevel #main:main :executable t)"

## Workspace cleanup

clean:
	rm -f *.o *.fasl *~ *.flc

lib-clean :
	(cd lib; make clean)

dist-clean: clean
	rm -rf fasl sbcl-fasl
