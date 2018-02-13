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
	<title>CC50 Finanças: Registro</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<div id="middle">
		<form action="register2.php" method="post">
			<table>
				<tr>
					<td>Usuário:</td><td><input name="username" type="text"></td>
				</tr>
				<tr>
					<td>Senha:</td><td><input name="password" type="password"></td>
				</tr>
				<tr>
					<td>Repita a senha:</td><td><input name="password2" type="password"></td>
				</tr>
				<tr>
					<td></td><td><input type="submit" value="Registrar"></td>
				</tr>
			</table>
		</form>
		<p><a href="login.php">login</a></p>
	</div>

	<div id="bottom">
		<span>© Matheus</span>
	</div>
</body>
</html>
