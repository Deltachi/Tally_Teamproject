<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    $User_ID = $_POST["User_ID"];	
	    $Firstname = $_POST["Firstname"];	
	    $Lastname = $_POST["Lastname"];	
	    $Username = $_POST["Username"];
	    $T9 = strtr(strtoupper($Username), 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' , '22233344455566677778889999'); //Converts the String into T9 Code		
	    $Password = $_POST["Password"];	
	    $Image = $_POST["Image"];	
	    $Email = $_POST["Email"];	
	    $Credits = $_POST["Credits"];	
	    $Blocked = $_POST["Blocked"];
	    $Rights = $_POST["Rights"];
	    $Leaderboard = $_POST["Leaderboard"];
	    	

		$query = "UPDATE Users SET Firstname='".$Firstname."' , Lastname='".$Lastname."' , Username='".$Username."' , T9='".$T9."' , Password='".$Password."' , Image='".$Image."' , Email='".$Email."' , Credits='".$Credits."' , Blocked='".$Blocked."' , Rights='".$Rights."' , Leaderboard='".$Leaderboard."'  WHERE User_ID = '".$User_ID."'";
		$results = $db->query($query);
		$rows = $results->rowCount();
		// $rows = $results->fetchAll(PDO::FETCH_ASSOC);
		// $data = array();
		// foreach ($rows as $rowKey => $row) {
		// 	array_push($data,$row);
		// }
		// echo json_encode($data);
		echo $rows;
		// http_response_code(404);
	    $db = NULL;		// Close database

	} catch(PDOException $e) 	{
	    echo "ERROR you noob :P -> ";
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>