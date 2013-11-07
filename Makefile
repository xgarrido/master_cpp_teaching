# -*- mode: makefile; -*-
EMACS=emacs
BATCH=$(EMACS) --batch --no-init-file									\
  --eval "(require 'org)"										\
  --eval "(org-babel-do-load-languages 'org-babel-load-languages					\
        '((sh . t)))"											\
  --eval "(setq org-confirm-babel-evaluate nil)"							\
  --eval "(setq c-standard-font-lock-fontify-region-function 'font-lock-default-fontify-region)"	\
  --eval '(org-babel-load-file   "./README.org")'                                                       \
  --eval '(org-babel-tangle-file "./README.org")'							\

SUBDIRS_ALL = lectures td slides

all: html

html:
	@echo "NOTICE: Generating html documentation..."
	@$(BATCH) --visit "README.org" --funcall org-publish-cpp > /dev/null 2>&1
	@rm -f README.el *.sty
	@find doc -name *.*~ | xargs rm -f
	@tar czvf /tmp/org-cpp-publish.tar.gz index.html doc
	@git checkout gh-pages
	@tar xzvf /tmp/org-cpp-publish.tar.gz
	@if [ -n "`git status --porcelain`" ]; then git commit -am "update doc" && git push; fi
	@git checkout master

pdf:
	@for dir in $(SUBDIRS_ALL); do $(MAKE) -C $$dir || exit $$?; done

clean:
	@rm -rf doc index.html

clean-all: clean
	@for dir in $(SUBDIRS_ALL); do $(MAKE) -C $$dir clean || exit $$?; done
