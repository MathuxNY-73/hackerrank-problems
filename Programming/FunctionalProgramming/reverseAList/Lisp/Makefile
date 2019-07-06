.SUFFIXES: .o .lsp . lisp

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
