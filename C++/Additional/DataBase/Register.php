<?php

	$name = $_POST['name'];
	$surname = $_POST['surname'];
	$age = $_POST['age'];
	$salary = $_POST['salary'];
	$email = $_POST['email'];
	$username = $_POST['username'];
	$password = $_POST['password'];
	
	$host = "localhost";
	$bdUsername = "root";
	$dbPassword = "";
	$dbname = "hamalsaran";
	
	$conn = mysql_connect($host, $bdUsername, $dbPassword, $dbname) or die('Connection faild: ' .mysql_error());
	
	mysql_select_db($dbname) or die(mysql_error());
		
	$SELECT = mysql_query("select * from `students` where `username`='$username';");
	$num_rows = mysql_num_rows($SELECT);
		
	if ($num_rows) 
	{
		die('There is a user with this username.');
	}
		
	$INSERT = mysql_query("insert into `students` (`name`, `surname`, `age`, `salary`, `username`, `password`, `email`)
								values ('$name', '$surname', '$age', '$salary', '$username', '$password', '$email');");
								
	if (!$INSERT) 
	{
		die('Invalid query: ' . mysql_error());
	}
	
	mysql_close($conn) or die('Database close error: ' . mysql_error());
	
	include 'Account.php';
?>