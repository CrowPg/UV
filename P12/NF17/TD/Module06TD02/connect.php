<?php
function fConnect(){
	$vHost="tuxa.sme.utc";
    $vPort="5432";
	$vDbname="dbnf17p065";
	$vUser="nf17p065";
	$vPassword="VI1HIxed";
	$vConn = pg_connect("host=$vHost port=$vPort dbname=$vDbname user=$vUser password=$vPassword");
	return $vConn;
}
?>