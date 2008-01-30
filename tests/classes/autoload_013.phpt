--TEST--
Ensure the ReflectionClass constructor triggers autoload.
--SKIPIF--
<?php extension_loaded('reflection') or die('skip'); ?>
--FILE--
<?php
  function __autoload($name)
  {
      echo "In autoload: ";
      var_dump($name);
  }
  
  try {
      new ReflectionClass("UndefC");
  }
  catch (ReflectionException $e) {
      echo $e->getMessage();
  }
?>
--EXPECTF--
In autoload: string(6) "UndefC"
Class UndefC does not exist
--UEXPECTF--
In autoload: unicode(6) "UndefC"
Class UndefC does not exist