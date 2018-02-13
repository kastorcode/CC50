<?php
	// require common code
	require_once("includes/common.php");

	$symbol = mysqli_real_escape_string($connection, $_POST["ssym"]);
	$shares = mysqli_real_escape_string($connection, $_POST["ssha"]);
	$stock = lookup($symbol);
	$query = mysqli_query($connection, "SELECT shares FROM wallet WHERE uid = {$_SESSION["uid"]} AND symbol = '{$symbol}'");
	$slices = mysqli_fetch_array($query);

	if (empty($slices))
		apologize("Você não possui nenhuma ação \"{$symbol}\".");

	if ($shares > $slices["shares"])
		apologize("Você não pode vender mais do que possui.");

	if (!mysqli_query($connection, "UPDATE wallet SET shares = shares - {$shares} WHERE uid = {$_SESSION["uid"]} AND symbol = '{$symbol}'"))
		apologize("Falha ao vender a ação \"{$stock->name}\".");

	if (!mysqli_query($connection, "UPDATE users SET cash = cash + {$stock->price} WHERE uid = {$_SESSION["uid"]}"))
		apologize("Falha ao adicionar o dinheiro a sua carteira.");

	if (!mysqli_query($connection, "INSERT INTO history (uid, operation, symbol, stocks, price)
									VALUES ({$_SESSION["uid"]}, 'S', '{$stock->symbol}', {$shares}, {$stock->price})"))
		apologize("Falha ao armazenar informações no histórico.");

	redirect("sell.php");
?>
