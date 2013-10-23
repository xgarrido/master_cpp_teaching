doc_tex			= $(wildcard *.tex)
doc_pdf			= $(doc_tex:.tex=.pdf)
doc_sty_skeleton	= $(wildcard ../../base/*.sty.skeleton)
doc_sty			= $(doc_sty_skeleton:.skeleton=)

#LATEXFLAGS=-halt-on-error -interaction=batchmode

.PHONY: all

all: $(doc_pdf)

%.pdf: %.tex
	../../utils/filepp ../../base/BasePackage.sty.skeleton -o ../../base/BasePackage.sty
	xelatex $(LATEXFLAGS) $< || exit $$?
	rm -f $(<:.tex=.out) $(<:.tex=.log) $(<:.tex=.aux) \
	$(<:.tex=.toc) $(<:.tex=.nav) $(<:.tex=.vrb) \
	$(<:.tex=.snm)

clean:
	@for f in $(doc_tex) ; do \
	rm -f $(doc_tex:.tex=.ps) $(doc_tex:.tex=.pdf) $(doc_tex:.tex=.toc) \
	$(doc_tex:.tex=.aux) $(doc_tex:.tex=.log) $(doc_tex:.tex=.blg) \
	$(doc_tex:.tex=.out) $(doc_tex:.tex=.bbl) $(doc_tex:.tex=.fot) \
	$(doc_tex:.tex=.brf) $(doc_tex:.tex=.dvi) $(doc_tex:.tex=.log) \
	$(doc_tex:.tex=.nav) $(doc_tex:.tex=.snm) $(doc_tex:.tex=.vrb); \
	done ; \
	rm -rf *.aux *~ tmp.inputs
