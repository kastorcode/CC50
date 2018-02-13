<?php
    // require common code
    require_once("includes/common.php"); 

    // log out current user, if any
    logout();
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" type="text/css" href="css/styles.css"/>
	<title>CC50 Finanças: Log out</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<div id="middle">
		<p>kthxbai</p>
		<p>faça o <a href="login.php">login</a> de novo</p>
	</div>

	<div id="bottom">
		<span>© Matheus</span>
	</div>
</body>
</html>
