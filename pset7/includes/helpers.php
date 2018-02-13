<?php
	// helpers.php	CC50	Pset 7	Helper functions.

	/*
	 * void
	 * apologize($message)
	 *
	 * Apologizes to user by displaying a page with message.
	 */

	function apologize($message)
	{
		// require template
		require_once("apology.php");

		// exit immediately since we're apologizing
		exit;
	}

	/*
	 * void
	 * dump($variable)
	 *
	 * Facilitates debugging by dumping contents of variable
	 * to browser.
	 */

	function dump($variable)
	{
		// dump variable with some quick and dirty HTML
		require("dump.php");

		// exit immediately so that we can see what we printed
		exit;
	}

	/*
	 * void
	 * logout()
	 *
	 * Logs out current user, if any. Based on Example #1 at
	 * http://us.php.net/manual/en/function.session-destroy.php.
	 */

	function logout()
	{
		// unset any session variables
		$_SESSION = array();

		// expire cookie
		if (isset($_COOKIE[session_name()]))
		{
			if (preg_match("{^(/~[^/]+/pset7/)}", $_SERVER["REQUEST_URI"], $matches))
				setcookie(session_name(), "", time() - 42000, $matches[1]);
			else
				setcookie(session_name(), "", time() - 42000);
		}

		// destroy session
		session_destroy();
	}

	/*
	 * stock
	 * lookup($symbol)
	 *
	 * Returns a stock by symbol (case-insensitively) else NULL if not found.
	 */

	function lookup($symbol)
	{
		// reject symbols that start with ^
		if (preg_match("/^\^/", $symbol))
			return NULL;

		// open connection to Yahoo
		if (($fp = @fopen(CSV, "r")) === FALSE)
			return NULL;

		// download first line of CSV file
		if (($data = fgetcsv($fp)) === FALSE || count($data) == 1)
			return NULL;

		// close connection to Yahoo
		fclose($fp);

		// ensure symbol was found
		if ($data[2] == 0.00)
			return NULL;

		// instantiate a stock object
		$stock = new Stock();

		// remember stock's symbol and trades
		$stock->name = $data[0];
		$stock->symbol = $data[1];
		$stock->price = $data[2];
		$stock->low = $data[3];
		$stock->high = $data[4];
		/*
		$stock->time = strtotime($data[5] . " " . $data[6]);
		$stock->change = $data[7];
		$stock->open = $data[8];
		*/

		// return stock
		return $stock;
	}

	/*
	 * void
	 * redirect($destination)
	 * 
	 * Redirects user to destination, which can be
	 * a URL or a relative path on the local host.
	 *
	 * Because this function outputs an HTTP header, it
	 * must be called before caller outputs any HTML.
	 */

	function redirect($destination)
	{
		// handle URL
		if (preg_match("/^http:\/\//", $destination))
			header("Location: " . $destination);

		// handle absolute path
		else if (preg_match("/^\//", $destination))
		{
			$protocol = (@$_SERVER["HTTPS"]) ? "https" : "http";
			$host = $_SERVER["HTTP_HOST"];
			header("Location: $protocol://$host$destination");
		}

		// handle relative path
		else
		{
			// adapted from http://www.php.net/header
			$protocol = (@$_SERVER["HTTPS"]) ? "https" : "http";
			$host = $_SERVER["HTTP_HOST"];
			$path = rtrim(dirname($_SERVER["PHP_SELF"]), "/\\");
			header("Location: $protocol://$host$path/$destination");
		}

		// exit immediately since we're redirecting anyway
		exit;
	}
?>
