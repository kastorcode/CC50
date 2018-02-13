<?php
	// require common code
	require_once("includes/common.php");

	$symbol = mysqli_real_escape_string($connection, $_POST["ssym"]);
	$shares = mysqli_real_escape_string($connection, $_POST["ssha"]);

	if (!preg_match("/^\d+$/", $shares))
		apologize("Você pode comprar somente com valores inteiro positivo.");

	$stock = lookup($symbol);
	$query = mysqli_query($connection, "SELECT cash FROM users WHERE uid = {$_SESSION["uid"]}");
	$slices = mysqli_fetch_array($query);

	if ($shares > $slices["cash"])
		apologize("Você não têm dinheiro suficiente para comprar.");

	if (!mysqli_query($connection, "INSERT INTO wallet (uid, symbol, shares) VALUES ({$_SESSION["uid"]}, '$stock->symbol', $shares)
									ON DUPLICATE KEY UPDATE shares = shares + $shares"))
		apologize("Falha ao comprar a ação \"{$stock->name}\".");

	if (!mysqli_query($connection, "UPDATE users SET cash = cash - $stock->price WHERE uid = {$_SESSION["uid"]}"))
		apologize("Falha ao remover o dinheiro da sua carteira.");

	if (!mysqli_query($connection, "INSERT INTO history (uid, operation, symbol, stocks, price)
									VALUES ({$_SESSION["uid"]}, 'B', '$stock->symbol', $shares, $stock->price)"))
		apologize("Falha ao armazenar informações no histórico.");

	redirect("buy.php");
?>
