/*
   +----------------------------------------------------------------------+
   | PHP Version 4                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997, 1998, 1999, 2000, 2001 The PHP Group             |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.02 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://www.php.net/license/2_02.txt.                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Hartmut Holzgraefe <hartmut@six.de>                         |
   |                                                                      |
   +----------------------------------------------------------------------+
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_ncurses.h"
#include "ext/standard/info.h"

/* If you declare any globals in php_ncurses.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(ncurses)
*/

/* True global resources - no need for thread safety here */
int le_ncurses;


static void ncurses_destruct(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    WINDOW **pwin = (WINDOW **)rsrc->ptr;

    delwin(*pwin);
    efree(pwin);
}


/* {{{ ncurses_module_entry
 */
zend_module_entry ncurses_module_entry = {
    STANDARD_MODULE_HEADER,
    "ncurses",
    ncurses_functions,
    PHP_MINIT(ncurses),
    PHP_MSHUTDOWN(ncurses),
    PHP_RINIT(ncurses),     /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(ncurses), /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(ncurses),
    NO_VERSION_YET,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_NCURSES
ZEND_GET_MODULE(ncurses)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("ncurses.value",      "42", PHP_INI_ALL, OnUpdateInt, global_value, zend_ncurses_globals, ncurses_globals)
    STD_PHP_INI_ENTRY("ncurses.string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_ncurses_globals, ncurses_globals)
PHP_INI_END()
*/
/* }}} */

#define PHP_NCURSES_CONST(x)  REGISTER_LONG_CONSTANT("NCURSES_"#x, x, CONST_CS | CONST_PERSISTENT)

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(ncurses)
{
    /* color constants */
    PHP_NCURSES_CONST(COLOR_BLACK);
    PHP_NCURSES_CONST(COLOR_RED);
    PHP_NCURSES_CONST(COLOR_GREEN);
    PHP_NCURSES_CONST(COLOR_YELLOW);
    PHP_NCURSES_CONST(COLOR_BLUE);
    PHP_NCURSES_CONST(COLOR_MAGENTA);
    PHP_NCURSES_CONST(COLOR_CYAN);
    PHP_NCURSES_CONST(COLOR_WHITE);
    
    /* keyboard constants */
    PHP_NCURSES_CONST(KEY_DOWN);
    PHP_NCURSES_CONST(KEY_UP);
    PHP_NCURSES_CONST(KEY_LEFT);
    PHP_NCURSES_CONST(KEY_RIGHT);
    PHP_NCURSES_CONST(KEY_BACKSPACE);

    /* mouse constants */
    PHP_NCURSES_CONST(BUTTON1_PRESSED);
    PHP_NCURSES_CONST(BUTTON1_RELEASED);
    PHP_NCURSES_CONST(BUTTON1_CLICKED);
    PHP_NCURSES_CONST(BUTTON1_DOUBLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON1_TRIPLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON2_PRESSED);
    PHP_NCURSES_CONST(BUTTON2_RELEASED);
    PHP_NCURSES_CONST(BUTTON2_CLICKED);
    PHP_NCURSES_CONST(BUTTON2_DOUBLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON2_TRIPLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON3_PRESSED);
    PHP_NCURSES_CONST(BUTTON3_RELEASED);
    PHP_NCURSES_CONST(BUTTON3_CLICKED);
    PHP_NCURSES_CONST(BUTTON3_DOUBLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON3_TRIPLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON4_PRESSED);
    PHP_NCURSES_CONST(BUTTON4_RELEASED);
    PHP_NCURSES_CONST(BUTTON4_CLICKED);
    PHP_NCURSES_CONST(BUTTON4_DOUBLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON4_TRIPLE_CLICKED);
    PHP_NCURSES_CONST(BUTTON_SHIFT);
    PHP_NCURSES_CONST(BUTTON_CTRL);
    PHP_NCURSES_CONST(BUTTON_ALT);
    PHP_NCURSES_CONST(ALL_MOUSE_EVENTS);
    PHP_NCURSES_CONST(REPORT_MOUSE_POSITION);


    le_ncurses = zend_register_list_destructors_ex(ncurses_destruct, NULL, "ncurses_handle", module_number);    

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(ncurses)
{
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(ncurses)
{
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(ncurses)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(ncurses)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "ncurses support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
    DISPLAY_INI_ENTRIES();
    */
}
/* }}} */

/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */



/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 fdm=marker
 * vim<600: sw=4 ts=4
 */
