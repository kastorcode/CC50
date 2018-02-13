<?php
	require_once("includes/common.php");
	$s = lookup($_POST["symbol"]);
	if (!$s)
		apologize("Símbolo inválido.");
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" type="text/css" href="css/styles.css"/>
	<title>CC50 Finanças: Valor da cotação</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<div id="middle">
		<p><div style="text-align: center">A ação <?= $s->name ?> atualmente custa $<?= $s->price ?>.</div></p>
		<p><a href="javascript:history.go(-1);">Voltar</a></p>
	</div>

	<div id="bottom">
		<span>© Matheus</span>
	</div>
</body>
</html>
