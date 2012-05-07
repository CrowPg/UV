<html>

<head>

  <title>Inscription Soutenance NF17</title>

</head>

<body>

  <h1>Inscriptions à la soutenance de NF17</h1>

  <h2>Liste des créneaux horaires</h2>

  <table border="1">

    <tr>

      <td width="100pt"><b>Session</b></td>

      <td width="100pt"><b>Début</b></td>

      <td width="100pt"><b>Fin</b></td>

      <td width="100pt"><b>Places disponibles</b></td>

    </tr>

<?php

  include "connect.php";

  include "inscription_param.php";

  $vConn = fConnect();

  $vSql ="SELECT id, debut, fin, $CST_DISPO_SESSION-count(pklogin) FROM tSession LEFT OUTER JOIN tGroupe ON tSession.id=tGroupe.session GROUP BY id, debut, fin ORDER BY id ASC;";

  $vQuery=pg_query($vConn, $vSql);

  while ($vResult = pg_fetch_array($vQuery)) {

    echo "<tr>";

    echo "<td>Session $vResult[0]</td>";

    echo "<td>$vResult[1]</td>";

    echo "<td>$vResult[2]</td>";
	
	echo "<td>$vResult[3]</td>";

    echo "</tr>";

  }

?>

  </table>

  <hr/>

  <a href="inscription2.html">S'inscrire</a>

</body>

</html>