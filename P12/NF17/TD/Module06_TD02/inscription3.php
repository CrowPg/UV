<html>

<head>

  <title>Inscription Soutenance NF17</title>

</head>

<body>

  <h1>Inscriptions � la soutenance de NF17</h1>

<?php

  /* Connexion � la base de donn�es */

  include "connect.php";
  $vConn = fConnect();

  /* R�cup�ration des variables pass�es par le fomulaire */

  $vLogin=$_POST['login'];

  $vChoix=$_POST['n_session'];
echo ":'(";
  /* Inscription */

  $vSql="UPDATE tGroupe SET session=$vChoix WHERE pklogin='$vLogin'";

  $vQuery=pg_query($vSql);

  echo "<p>Inscription de $vLogin � la session $vChoix valid�e</p>";

?>

  <hr/>

  <p><a href="inscription1.php">Retour</a></p>

</body>

</html>