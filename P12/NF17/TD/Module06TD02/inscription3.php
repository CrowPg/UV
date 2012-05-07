<html>

<head>

  <title>Inscription Soutenance NF17</title>

</head>

<body>

  <h1>Inscriptions à la soutenance de NF17</h1>

<?php

  /* Connexion à la base de données */

  include "connect.php";
  $vConn = fConnect();

  /* Récupération des variables passées par le fomulaire */

  $vLogin=$_POST['login'];

  $vChoix=$_POST['n_session'];
echo ":'(";
  /* Inscription */

  $vSql="UPDATE tGroupe SET session=$vChoix WHERE pklogin='$vLogin'";

  $vQuery=pg_query($vSql);

  echo "<p>Inscription de $vLogin à la session $vChoix validée</p>";

?>

  <hr/>

  <p><a href="inscription1.php">Retour</a></p>

</body>

</html>