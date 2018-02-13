<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" type="text/css" href="css/styles.css"/>
	<title>CC50 Finanças: Ops!</title>
</head>
<body>
	<div id="top">
		<a href="index.php"><img alt="CC50 Finanças" src="images/logo.png" style="height: 200px;"></a>
	</div>

	<div id="middle">
		<h1>Ops!</h1>
		<h2><?= $message ?></h2>
		<p><a href="javascript:history.go(-1);">Voltar</a></p>
	</div>

	<div id="bottom">
		<span>© Matheus</span>
	</div>
</body>
</html>
