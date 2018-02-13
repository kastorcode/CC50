<?php

    // require common code
    require_once("includes/common.php"); 

    // escape username and password for safety
    $username = mysqli_real_escape_string($connection, $_POST["username"]);
    $password = mysqli_real_escape_string($connection, $_POST["password"]);

    // prepare SQL
    $sql = "SELECT uid FROM users WHERE username='$username' AND password='$password'";

    // execute query
    $result = mysqli_query($connection, $sql);

    // if we found a row, remember user and redirect to portfolio
    if (mysqli_num_rows($result) == 1)
    {
        // grab row
        $row = mysqli_fetch_array($result);

        // cache uid in session
        $_SESSION["uid"] = $row["uid"];

        // redirect to portfolio
        redirect("index.php");
    }
    // else report error
    else
        apologize("Usuário e/ou senha inválidos!");

?>
