#  +----------------------------------------------------------------------+
#  | PHP Version 5                                                        |
#  +----------------------------------------------------------------------+
#  | Copyright (c) 1997-2004 The PHP Group                                |
#  +----------------------------------------------------------------------+
#  | This source file is subject to version 3.0 of the PHP license,       |
#  | that is bundled with this package in the file LICENSE, and is        |
#  | available through the world-wide-web at the following url:           |
#  | http://www.php.net/license/3_0.txt.                                  |
#  | If you did not receive a copy of the PHP license and are unable to   |
#  | obtain it through the world-wide-web, please send a note to          |
#  | license@php.net so we can mail you a copy immediately.               |
#  +----------------------------------------------------------------------+
#  | Author: Sascha Schumann <sascha@schumann.cx>                         |
#  +----------------------------------------------------------------------+
#
# $Id$ 
#

include generated_lists

TOUCH_FILES = mkinstalldirs install-sh missing

LT_TARGETS = ltmain.sh config.guess config.sub

makefile_in_files = $(makefile_am_files:.am=.in)
makefile_files    = $(makefile_am_files:e.am=e)

config_h_in = main/php_config.h.in

acconfig_h_SOURCES = acconfig.h.in $(config_h_files)

targets = $(TOUCH_FILES) configure $(config_h_in)

SUPPRESS_WARNINGS ?= 2>&1 | (egrep -v '(AC_TRY_RUN called without default to allow cross compiling|AC_PROG_CXXCPP was called before AC_PROG_CXX|defined in acinclude.m4 but never used|AC_PROG_LEX invoked multiple times|AC_DECL_YYTEXT is expanded from...|the top level)'||true)

all: $(targets)

acconfig.h: $(acconfig_h_SOURCES)
	@echo rebuilding $@
	cat $(acconfig_h_SOURCES) > $@

$(config_h_in): configure acconfig.h
# explicitly remove target since autoheader does not seem to work 
# correctly otherwise (timestamps are not updated)
	@echo rebuilding $@
	@rm -f $@
	autoheader $(SUPPRESS_WARNINGS)

$(TOUCH_FILES):
	touch $(TOUCH_FILES)

aclocal.m4: configure.in acinclude.m4
	@echo rebuilding $@
	cat acinclude.m4 ./build/libtool.m4 > $@

configure: aclocal.m4 configure.in $(config_m4_files)
	@echo rebuilding $@
	autoconf $(SUPPRESS_WARNINGS)

