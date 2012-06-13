<html>

<body>

	<table border="1">

	<tr><th>Numéro</th><th>Nom</th><th>Population</th></tr>

<?php

  $vHost="tuxa.sme.utc";

  $vDbname="dbnf17p065";

  $vPort="5432";

  $vUser="nf17p065";

  $vPassword="VI1HIxed";

  $vConn = pg_connect("host=$vHost port=$vPort dbname=$vDbname user=$vUser password=$vPassword");
  
  
  
  $vSql ="SET CLIENT_ENCODING TO 'LATIN1'; SELECT dep_id, dep_nom, nbhabitants FROM dept2;";

  $vQuery=pg_query($vConn, $vSql);

  while ($vResult = pg_fetch_array($vQuery, null, PGSQL_ASSOC)) 
  {
    echo "<tr>";
    echo "<td>$vResult[dep_id]</td>";
    echo "<td>$vResult[dep_nom]</td>";
	echo "<td>$vResult[nbhabitants]</td>";
    echo "</tr>";
  }

?>

	</table>
	<ul>
<?php

$vHost="tuxa.sme.utc";

  $vDbname="dbnf17p065";

  $vPort="5432";

  $vUser="nf17p065";

  $vPassword="VI1HIxed";

  $vConn = pg_connect("host=$vHost port=$vPort dbname=$vDbname user=$vUser password=$vPassword");
  
  $vSql ="SET CLIENT_ENCODING TO 'LATIN1';";
  $vQuery=pg_query($vConn, $vSql);

  $vSql ="SELECT D1.dep_nom, D1.nbhabitants FROM dept2 D1 WHERE D1.nbhabitants = (SELECT MAX(D2.nbhabitants) FROM dept2 D2) ;";
  $vQuery=pg_query($vConn, $vSql);
  $vResult = pg_fetch_array($vQuery, null, PGSQL_ASSOC);
  
	echo "<li>Département le plus peuplé : $vResult[dep_nom] ($vResult[nbhabitants])</li>";
	echo "<li>Département le moins peuplé : Hautes-Alpes(126636)</li>";
?>
	</ul>

</body>

</html>