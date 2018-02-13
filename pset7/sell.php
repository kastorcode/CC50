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
    <title>CC50 Finanças: Vender Ações</title>
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
 			$query1 = mysqli_query($connection, "SELECT username, cash FROM users WHERE uid = {$_SESSION["uid"]}");
 			$uc = mysqli_fetch_array($query1);
 			print("<table><tr><td>{$uc[0]}</td><td>Valor disponível: {$uc[1]}.</td></tr></table><br/>");
 			$query2 = mysqli_query($connection, "SELECT symbol, shares FROM wallet WHERE uid = {$_SESSION["uid"]}");
 			print("<table><tr><td>Nome</td><td>Símbolo</td><td>Preço</td><td>+Baixo</td><td>+Alto</td><td>Quantidade</td></tr>");
 			while ($row = mysqli_fetch_array($query2)) {
 				$s = lookup($row["symbol"]);
 				print("<tr><td>{$s->name}</td><td>{$s->symbol}</td><td>{$s->price}</td><td>{$s->low}</td><td>{$s->high}</td>
 					   <td>{$row["shares"]}</td></tr>");
 			}
 			print("</table>");
 		?>
		<p>Vender Ações</p>
 		<form action="sell2.php" method="post">
 			Símbolo: <input type="text" name="ssym"/><br/>
 			Quantidade: <input type="number" name="ssha"><br/>
 			<input type="submit" value="Vender"/>
 		</form>
 	</div>

	<div id="bottom">
		<span>© Matheus</span>
	</div>
</body>
</html>
