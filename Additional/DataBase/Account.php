<html>
	<?php
		
		$host = "localhost";
		$bdUsername = "root";
		$dbPassword = "";
		$dbname = "hamalsaran";
		
		$conn = mysql_connect($host, $bdUsername, $dbPassword, $dbname) or die('Connection faild: ' .mysql_error());
		
		mysql_select_db($dbname) or die(mysql_error());
			
		$SELECT = mysql_query("select * from `students` where `username`='$username' and `password`='$password';");
		$num_rows = mysql_num_rows($SELECT);
			
		if ($num_rows == 1) 
		{
			$row = mysql_fetch_assoc($SELECT);

			$name = $row["name"];
			$surname = $row["surname"];
			$age = $row["age"];
			$salary = $row["salary"];
			$email = $row["email"];
			$username = $row["username"];
		}
		mysql_close($conn) or die('Database close error' . mysql_error());

	?>
	  <div class="container">
	  
		<h1><?php echo $username ?>`s home page</h1>
		<hr>

		<label for="name"><b>Name : </b></label>
		<label for="name"><b><?php echo $name ?></b></label></br>
		
		<label for="surname"><b>Surname : </b></label>
		<label for="name"><b><?php echo $surname ?></b></label></br>
		
		<label for="age"><b>Age : </b></label>
		<label for="name"><b><?php echo $age ?></b></label></br>
		
		<label for="salary"><b>Salary : </b></label>
		<label for="name"><b><?php echo $salary ?></b></label></br>
		
		<label for="email"><b>Email : </b></label>
		<label for="name"><b><?php echo $email ?></b></label></br>

	  </div>
	
</html>