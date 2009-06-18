--TEST--
Test dcgettext() functionality
--SKIPIF--
<?php
if (!extension_loaded("gettext")) {
    die("skip gettext extension is not loaded.\n");
}
if (!setlocale(LC_ALL, 'en_US.UTF-8')) {
    die("skip en_US.UTF-8 locale not supported.");
}
--FILE--
<?php
chdir(dirname(__FILE__));

// Using deprectated setlocale() in PHP6. The test needs to be changed
// when there is an alternative available.

setlocale(LC_MESSAGES, 'en_US.UTF-8');
setlocale(LC_ALL, 'en_US.UTF-8');
bindtextdomain('dngettextTest', './locale');

var_dump(dcgettext('dngettextTest', 'item', LC_CTYPE));
var_dump(dcgettext('dngettextTest', 'item', LC_MESSAGES));
--EXPECTF--
Deprecated: setlocale(): deprecated in Unicode mode, please use ICU locale functions in %s.php on line %d

Deprecated: setlocale(): deprecated in Unicode mode, please use ICU locale functions in %s.php on line %d
string(8) "cProdukt"
string(7) "Produkt"
--CREDITS--
Christian Weiske, cweiske@php.net
PHP Testfest Berlin 2009-05-09
