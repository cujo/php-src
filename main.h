/* 
   +----------------------------------------------------------------------+
   | PHP HTML Embedded Scripting Language Version 3.0                     |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997,1998 PHP Development Team (See Credits file)      |
   +----------------------------------------------------------------------+
   | This program is free software; you can redistribute it and/or modify |
   | it under the terms of one of the following licenses:                 |
   |                                                                      |
   |  A) the GNU General Public License as published by the Free Software |
   |     Foundation; either version 2 of the License, or (at your option) |
   |     any later version.                                               |
   |                                                                      |
   |  B) the PHP License as published by the PHP Development Team and     |
   |     included in the distribution in the file: LICENSE                |
   |                                                                      |
   | This program is distributed in the hope that it will be useful,      |
   | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
   | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
   | GNU General Public License for more details.                         |
   |                                                                      |
   | You should have received a copy of both licenses referred to here.   |
   | If you did not, or have any questions about PHP licensing, please    |
   | contact core@php.net.                                                |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
 */


/* $Id$ */


#ifndef _MAIN_H
#define _MAIN_H

#include "zend_globals.h"
#include "php_globals.h"

int php3_request_startup(CLS_D ELS_DC PLS_DC);
extern void php3_request_shutdown(void *dummy);
extern void php3_request_shutdown_for_exec(void *dummy);
extern int php3_module_startup();
extern void php3_module_shutdown();
extern void php3_module_shutdown_for_exec(void);

extern void php3_call_shutdown_functions(void);


/* configuration module */
extern int php3_init_config(void);
extern int php3_shutdown_config(void);

/* environment module */
extern int php3_init_environ(void);
extern int php3_shutdown_environ(void);

#endif
