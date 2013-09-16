# -*- mode: makefile; -*-
EMACS=emacs
BATCH=$(EMACS) --batch --eval '(require (quote org))' --eval '(setq starter-kit-dir "~/.emacs.d")' --load ~/.emacs.d/starter-kit-org.el

files_org = $(wildcard *.org)
files_pdf = $(files_org:.org=.pdf)

all: $(files_pdf)

%.pdf: %.org
	@echo "NOTICE: Exporting $< to pdf..."
	@$(BATCH) --visit "$<" --funcall org-beamer-export-to-pdf > /dev/null 2>&1

clean:
	@rm -rf $(files_org:.org=.tex) $(files_org:.org=.pyg) \
	$(files_pdf) $(img_pdf) tikz.d latex.d \
	*.nav *.out *.toc *.snm *.fdb* *.fls *.aux *.log *.auxlock *.vrb *~
