--TEST--
SPL: forward
--SKIPIF--
<?php if (!extension_loaded("spl")) print "skip"; ?>
--FILE--
<?php
class c implements spl_forward_assoc {

	public $max = 3;
	public $num = 0;

	function current() {
		echo __METHOD__ . "\n";
		return $this->num;
	}
	function next() {
		echo __METHOD__ . "\n";
		$this->num++;
	}
	function hasMore() {
		echo __METHOD__ . "\n";
		return $this->num < $this->max;
	}
	function key() {
		echo __METHOD__ . "\n";
		switch($this->num) {
			case 0: return "1st";
			case 1: return "2nd";
			case 2: return "3rd";
			default: return "???";
		}
	}
}

$i = new c();

$implements = class_implements($i);
asort($implements);
$c_info = array(get_class($i) => array('inheits' => class_parents($i), 'implements' => $implements));
print_r($c_info);
$methods = get_class_methods("spl_forward_assoc");
sort($methods);
print_r($methods);
$methods = get_class_methods($i);
sort($methods);
print_r($methods);


echo "1st try\n";
foreach($i as $w) {
	echo "object:$w\n";
}

echo "2nd try\n";

foreach($i as $v => $w) {
	echo "object:$v=>$w\n";
}

echo "3rd try\n";
$i->num = 0;

foreach($i as $v => $w) {
	echo "object:$v=>$w\n";
}

print "Done\n";
?>
--EXPECT--
Array
(
    [c] => Array
        (
            [inheits] => Array
                (
                )

            [implements] => Array
                (
                    [spl_assoc] => spl_assoc
                    [spl_forward] => spl_forward
                    [spl_forward_assoc] => spl_forward_assoc
                )

        )

)
Array
(
    [0] => current
    [1] => hasMore
    [2] => key
    [3] => next
)
Array
(
    [0] => current
    [1] => hasMore
    [2] => key
    [3] => next
)
1st try
c::hasMore
c::current
c::key
object:0
c::next
c::hasMore
c::current
c::key
object:1
c::next
c::hasMore
c::current
c::key
object:2
c::next
c::hasMore
2nd try
c::hasMore
3rd try
c::hasMore
c::current
c::key
object:1st=>0
c::next
c::hasMore
c::current
c::key
object:2nd=>1
c::next
c::hasMore
c::current
c::key
object:3rd=>2
c::next
c::hasMore
Done
