<?php

	$username = $_POST['username'];
	$password = $_POST['password'];
	
	if (!empty($name) || 
		!empty($password))
		{
			$host = "localhost";
			$bdUsername = "root";
			$dbPassword = "";
			$dbname = "hamalsaran";
			
			$conn = mysql_connect($host, $bdUsername, $dbPassword, $dbname) or die('Connection faild: ' .mysql_error());
			
			mysql_select_db($dbname) or die(mysql_error());
				
			$SELECT = mysql_query("select * from `students` where `username`='$username'");
			$num_rows = mysql_num_rows($SELECT);
				
			if (!$num_rows) 
			{
				die('You don\'t have account. Please create it first.');
			}
	
		mysql_close($conn) or die('Close error: ' . mysql_error());
		}
		
		include 'Account.php';
?>