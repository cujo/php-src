--TEST--
mb_convert_encoding()
--SKIPIF--
<?php include('skipif.inc'); ?>
--POST--
--GET--
--FILE--
<?php include('016.inc'); ?>
--EXPECT--
== BASIC TEST ==
EUC-JP: ���ܸ�ƥ����ȤǤ���01234������������
EUC-JP: ���ܸ�ƥ����ȤǤ���01234������������
SJIS: k/qWe4zqg2WDTINYg2eCxYK3gUIwMTIzNIJUglWCVoJXgliBQg==
JIS: GyRCRnxLXDhsJUYlLSU5JUgkRyQ5ISMbKEIwMTIzNBskQiM1IzYjNyM4IzkhIxsoQg==
== ARRAY ENCODING LIST ==
EUC-JP: ���ܸ�ƥ����ȤǤ���01234������������
SJIS: k/qWe4zqg2WDTINYg2eCxYK3gUIwMTIzNIJUglWCVoJXgliBQg==
JIS: GyRCRnxLXDhsJUYlLSU5JUgkRyQ5ISMbKEIwMTIzNBskQiM1IzYjNyM4IzkhIxsoQg==
== DETECT ORDER ==
EUC-JP: ���ܸ�ƥ����ȤǤ���01234������������
SJIS: k/qWe4zqg2WDTINYg2eCxYK3gUIwMTIzNIJUglWCVoJXgliBQg==
JIS: GyRCRnxLXDhsJUYlLSU5JUgkRyQ5ISMbKEIwMTIzNBskQiM1IzYjNyM4IzkhIxsoQg==
== INVALID PARAMETER ==
INT: 1234
EUC-JP: 
ERR: Warning
BAD: 
ERR: Warning
MP: 


