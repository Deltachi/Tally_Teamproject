<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    // $grocery_id = $_POST["Grocery_ID"];	
	    $User_ID = $_POST["User_ID"];	
	    $Grocery_ID = $_POST["Grocery_ID"];	
	    if(isset($_POST["Discount"])){
	    	$Discount = $_POST["Discount"];
	    }
	    else{
	    	$Discount = 0;
	    }

	    

		$query = "INSERT INTO Favorites(User_ID, Grocery_ID, Discount) VALUES('".$User_ID."','".$Grocery_ID."','".$Discount."')";
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