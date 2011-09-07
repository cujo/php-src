--TEST--
ext/sockets - socket_strerror - basic test
--CREDITS--
Florian Anderiasch
fa@php.net
--SKIPIF--
<?php
    if (!extension_loaded('sockets') || !function_exists('socket_strerror')) {
        die('skip sockets extension not available.');
    }
    if (!stristr(PHP_OS, "Linux")) {
        die('skip - test validates linux error strings only.');
    }
?>
--FILE--
<?php
    $s_s = socket_strerror();
    for ($i=0;$i<=132;$i++) {
        var_dump(socket_strerror($i));
    }
?>
--EXPECTF--

Warning: socket_strerror() expects exactly 1 parameter, 0 given in %s on line %i
string(7) "Success"
string(23) "Operation not permitted"
string(25) "No such file or directory"
string(15) "No such process"
string(23) "Interrupted system call"
string(18) "Input/output error"
string(25) "No such device or address"
string(22) "Argument list too long"
string(17) "Exec format error"
string(19) "Bad file descriptor"
string(18) "No child processes"
string(32) "Resource temporarily unavailable"
string(22) "Cannot allocate memory"
string(17) "Permission denied"
string(11) "Bad address"
string(21) "Block device required"
string(23) "Device or resource busy"
string(11) "File exists"
string(25) "Invalid cross-device link"
string(14) "No such device"
string(15) "Not a directory"
string(14) "Is a directory"
string(16) "Invalid argument"
string(29) "Too many open files in system"
string(19) "Too many open files"
string(30) "Inappropriate ioctl for device"
string(14) "Text file busy"
string(14) "File too large"
string(23) "No space left on device"
string(12) "Illegal seek"
string(21) "Read-only file system"
string(14) "Too many links"
string(11) "Broken pipe"
string(32) "Numerical argument out of domain"
string(29) "Numerical result out of range"
string(25) "Resource deadlock avoided"
string(18) "File name too long"
string(18) "No locks available"
string(24) "Function not implemented"
string(19) "Directory not empty"
string(33) "Too many levels of symbolic links"
string(16) "Unknown error 41"
string(26) "No message of desired type"
string(18) "Identifier removed"
string(27) "Channel number out of range"
string(24) "Level 2 not synchronized"
string(14) "Level 3 halted"
string(13) "Level 3 reset"
string(24) "Link number out of range"
string(28) "Protocol driver not attached"
string(26) "No CSI structure available"
string(14) "Level 2 halted"
string(16) "Invalid exchange"
string(26) "Invalid request descriptor"
string(13) "Exchange full"
string(8) "No anode"
string(20) "Invalid request code"
string(12) "Invalid slot"
string(16) "Unknown error 58"
string(20) "Bad font file format"
string(19) "Device not a stream"
string(17) "No data available"
string(13) "Timer expired"
string(24) "Out of streams resources"
string(29) "Machine is not on the network"
string(21) "Package not installed"
string(16) "Object is remote"
string(21) "Link has been severed"
string(15) "Advertise error"
string(13) "Srmount error"
string(27) "Communication error on send"
string(14) "Protocol error"
string(18) "Multihop attempted"
string(18) "RFS specific error"
string(11) "Bad message"
string(37) "Value too large for defined data type"
string(26) "Name not unique on network"
string(28) "File descriptor in bad state"
string(22) "Remote address changed"
string(38) "Can not access a needed shared library"
string(36) "Accessing a corrupted shared library"
string(31) ".lib section in a.out corrupted"
string(47) "Attempting to link in too many shared libraries"
string(37) "Cannot exec a shared library directly"
string(49) "Invalid or incomplete multibyte or wide character"
string(43) "Interrupted system call should be restarted"
string(18) "Streams pipe error"
string(14) "Too many users"
string(30) "Socket operation on non-socket"
string(28) "Destination address required"
string(16) "Message too long"
string(30) "Protocol wrong type for socket"
string(22) "Protocol not available"
string(22) "Protocol not supported"
string(25) "Socket type not supported"
string(23) "Operation not supported"
string(29) "Protocol family not supported"
string(40) "Address family not supported by protocol"
string(22) "Address already in use"
string(31) "Cannot assign requested address"
string(15) "Network is down"
string(22) "Network is unreachable"
string(35) "Network dropped connection on reset"
string(32) "Software caused connection abort"
string(24) "Connection reset by peer"
string(25) "No buffer space available"
string(39) "Transport endpoint is already connected"
string(35) "Transport endpoint is not connected"
string(45) "Cannot send after transport endpoint shutdown"
string(34) "Too many references: cannot splice"
string(20) "Connection timed out"
string(18) "Connection refused"
string(12) "Host is down"
string(16) "No route to host"
string(29) "Operation already in progress"
string(25) "Operation now in progress"
string(21) "Stale NFS file handle"
string(24) "Structure needs cleaning"
string(27) "Not a XENIX named type file"
string(29) "No XENIX semaphores available"
string(20) "Is a named type file"
string(16) "Remote I/O error"
string(19) "Disk quota exceeded"
string(15) "No medium found"
string(17) "Wrong medium type"
string(18) "Operation canceled"
string(26) "Required key not available"
string(15) "Key has expired"
string(20) "Key has been revoked"
string(27) "Key was rejected by service"
string(10) "Owner died"
string(21) "State not recoverable"
string(%d) "%s"
