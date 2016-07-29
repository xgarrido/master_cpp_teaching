# -*- mode: makefile; -*-
EMACS=emacs
BATCH=$(EMACS) --batch --no-init-file						\
		--eval "(require 'org)"						\
		--eval "(org-babel-do-load-languages 'org-babel-load-languages	\
			'((sh . t)(C . t)))"					\
		--eval "(setq org-babel-use-quick-and-dirty-noweb-expansion t)" \
		--eval "(setq org-confirm-babel-evaluate nil)"			\
		--eval '(org-babel-load-file "../README.org")'                  \
		--eval '(org-babel-tangle-file "../README.org")'

ifndef with-correction
	BATCH += --eval "(setq org-export-exclude-tags '(\"correction\"))"
endif

files_org = $(wildcard *.org)
files_pdf = $(files_org:.org=.pdf)

all: $(files_pdf)

%.pdf: %.org
	@echo "NOTICE: Exporting $< to pdf..."
	@TEXINPUTS=".:..:$$TEXINPUTS" $(BATCH) --visit "$<" --funcall cpp-export-classes > /dev/null 2>&1

clean:
	@rm -rf	latex.d *.tex *.pdf *.fdb* *~
