<?php
	// common.php	CC50	Pset 7	Código comum a maioria das páginas.

    // display errors and warnings but not notices
    ini_set("display_errors", TRUE);
    error_reporting(E_ALL ^ E_NOTICE);

    // enable sessions, restricting cookie to /~username/pset7/
    if (preg_match("{^(/~[^/]+/pset7/)}", $_SERVER["REQUEST_URI"], $matches))
        session_set_cookie_params(0, $matches[1]);
    session_start();

    // requirements
    require_once("constants.php");
    require_once("helpers.php");
    require_once("stock.php");

    // require authentication for most pages
    if (!preg_match("/(:?log(:?in|out)|register)\d*\.php$/", $_SERVER["PHP_SELF"]))
    {
        if (!isset($_SESSION["uid"]))
            redirect("login.php");
    }

    // ensure database's name, username, and password are defined
    if (DB_NAME == "") apologize("You left DB_NAME blank.");
    if (DB_USER == "") apologize("You left DB_USER blank.");
    if (DB_PASS == "") apologize("You left DB_PASS blank.");

    // connect to database server
    if (($connection = @mysqli_connect(DB_SERVER, DB_USER, DB_PASS)) === FALSE)
        apologize("Não foi possível conectar ao banco de dados. " .
         "<br>Cheque os valores de DB_NAME, DB_PASS, e DB_USER em constants.php.");

    // select database
    if (@mysqli_select_db($connection, DB_NAME) === FALSE)
        apologize("Não foi possível selecionar o banco de dados (" . DB_NAME . ").");
?>
