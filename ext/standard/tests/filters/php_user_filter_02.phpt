--TEST--
class php_user_filter#2
--FILE--
<?php
class foo extends php_user_filter {
    function filter($in, $out, $consumed, $closing) {}
    function onCreate() {}
    function onClose() {}
}
?>
--EXPECTF--
Fatal error: Declaration of foo::filter() must be compatible with that of php_user_filter::filter() in %s on line %d
