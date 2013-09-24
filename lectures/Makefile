# -*- mode: makefile; -*-
EMACS=emacs
BATCH=$(EMACS) --batch --no-init-file \
		--eval '(require (quote org))' \
		--eval '(org-babel-load-file "../README.org")'

files_org = $(wildcard *.org)

all: pdf

pdf:
	@for f in $(files_org); do \
	echo "NOTICE: Exporting $$f to pdf..."; \
	$(BATCH) --visit "$$f" --funcall org-latex-export-to-pdf > /dev/null 2>&1; \
	done

clean:
	@rm -rf	latex.d \
	*.tex *.pdf *.fdb* *~
