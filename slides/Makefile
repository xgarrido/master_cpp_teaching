# -*- mode: makefile; -*-
EMACS=emacs
BATCH=$(EMACS) --batch --no-init-file \
		--eval '(require (quote org))' \
		--eval '(org-babel-load-file "../README.org")'

files_org = $(wildcard *.org)
files_pdf = $(files_org:.org=.pdf)

all: $(files_pdf)

%.pdf: %.org
	@echo "NOTICE: Exporting $< to pdf...";
	@$(BATCH) --visit "$<" --funcall org-beamer-export-to-pdf > /dev/null 2>&1;

clean:
	@rm -rf	latex.d *.tex *.pdf *.fdb* *~
