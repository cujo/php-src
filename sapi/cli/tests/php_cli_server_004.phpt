--TEST--
Bug #55747 (request headers missed in $_SERVER)
--INI--
allow_url_fopen=1
--SKIPIF--
<?php
include "skipif.inc"; 
if (substr(PHP_OS, 0, 3) == 'WIN') {
    die ("skip not for Windows");
}
?>
--FILE--
<?php
include "php_cli_server.inc";
php_cli_server_start('foreach($_SERVER as $k=>$v) { if (!strncmp($k, "HTTP", 4)) var_dump( $k . ":" . $v); }');

list($host, $port) = explode(':', PHP_CLI_SERVER_ADDRESS);
$port = intval($port)?:80;

$fp = fsockopen($host, $port, $errno, $errstr, 0.5);
if (!$fp) {
  die("connect failed");
}

if(fwrite($fp, <<<HEADER
GET / HTTP/1.1
Host:{$host}
User-Agent:dummy
Custom:foo


HEADER
)) {
	while (!feof($fp)) {
		echo fgets($fp);
	}
}

?>
--EXPECTF--	
HTTP/1.1 200 OK
Host: %s
Connection: closed
X-Powered-By: PHP/5.5.0-dev
Content-type: text/html

string(19) "HTTP_HOST:localhost"
string(21) "HTTP_USER_AGENT:dummy"
string(15) "HTTP_CUSTOM:foo"
