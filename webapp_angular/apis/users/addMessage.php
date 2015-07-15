<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    // $grocery_id = $_POST["Grocery_ID"];	
	    $User_ID = $_POST["User_ID"];	
	    $Sender = $_POST["Sender"];	
	    $Title = $_POST["Title"];	
	    $Sender = $_POST["Sender"];	
	    if(isset($_POST["Type"])){
	    	$Type = $_POST["Type"];
	    }
	    else{
	    	$Type = "alert-info";
	    }
	    $Message = $_POST["Message"];	
	    

		$query = "INSERT INTO Messages(User_ID, Sender, Title, Type, Message) VALUES('".$User_ID."','".$Sender."','".$Title."','".$Type."','".$Message."')";
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