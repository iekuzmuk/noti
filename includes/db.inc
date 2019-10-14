<?php

$hostname = "localhost";
$username = "admin";
$password = "admin_2019_10";
$databasename = "noti";

function showerror($str){
  die("Error " . $str);
}

function mysqlclean($array, $index, $maxlength, $connection){
  if (isset($array["{$index}"])){
    $input = substr($array["{$index}"], 0, $maxlength);
    $input = mysqli_real_escape_string( $connection,$input);
    return ($input);
  }
  return NULL;
}

?>
