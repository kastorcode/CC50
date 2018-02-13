<?php
	// require common code
	require_once("includes/common.php");
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" type="text/css" href="css/styles.css"/>
    <title>CC50 Finanças: Histórico de Operações</title>
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
		<?
			$query = mysqli_query($connection, "SELECT * FROM history WHERE uid = {$_SESSION["uid"]}");
			print("<table><tr><td>Ação</td><td>Operação</td><td>Quantidade</td><td>Preço</td><td>Data</td></tr>");
			while ($row = mysqli_fetch_array($query)) {
				$type = ($row["operation"] == "B") ? "Compra" : "Venda";
				print("<tr><td>{$row["symbol"]}</td><td>$type</td><td>{$row["stocks"]}</td><td>{$row["price"]}</td>
					   <td>{$row["date"]}</td></tr>");
			}
			print("</table>");
		?>
	</div>
	<div id="bottom">
		<span>© Matheus</span>
	</div>
</body>
</html>
