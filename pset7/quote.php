<?php
	require_once("includes/common.php");
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" type="text/css" href="css/styles.css"/>
	<title>CC50 Finanças: Cotação</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<nav>
		<a href="buy.php" title="Comprar ações">Comprar</a><a href="sell.php" title="Vender ações">Vender</a>
		<a href="history.php" title="Histórico de transações">Histórico</a><a href="quote.php" title="Consultar valor de ação">Cotações</a>
		<a href="password.php" title="Mude sua senha">Mudar Senha</a><a href="logout.php" title="Fazer logoff">Sair</a>
	</nav>

	<div id="middle">
		<form action="quote2.php" method="post">
			<table>
				<tr><td>Símbolo de uma ação:</td></tr>
				<tr><td><input name="symbol" type="text"></td></tr>
				<tr><td><input type="submit" value="Consultar"></td></tr>
			</table>
		</form>
	</div>

	<div id="bottom">
		<span>© Matheus</span>
	</div>
</body>
</html>
