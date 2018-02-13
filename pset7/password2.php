<?php
	// require common code
	require_once("includes/common.php");

	if ($_POST["pass2"] != $_POST["pass3"])
		apologize("As senhas escolhidas não coincidem.");

	$query = mysqli_query($connection, "SELECT password FROM users WHERE uid = {$_SESSION["uid"]}");
	$old_password = mysqli_fetch_array($query);

	if ($_POST["pass1"] != $old_password[0])
		apologize("Senha antiga está errada.");

	$new_password = mysqli_real_escape_string($connection, $_POST["pass2"]);

	if (!mysqli_query($connection, "UPDATE users SET password = '$new_password' WHERE uid = {$_SESSION["uid"]}"))
		apologize("Não foi possível alterar sua senha.");

	apologize("Senha alterada com sucesso.");
?>
