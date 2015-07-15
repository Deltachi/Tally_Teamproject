<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    $user_id = $_POST["request"];	//must be User_ID

	    $query = "SELECT * FROM Sell_History INNER JOIN Groceries ON Sell_History.Grocery_ID=Groceries.Grocery_ID WHERE Sell_History.User_ID = '".$user_id."'ORDER BY Sell_History.Sale_ID DESC LIMIT 5";
		$results = $db->query($query);
		$rows = $results->fetchAll(PDO::FETCH_ASSOC);
		$data = array();
		foreach ($rows as $rowKey => $row) {
			array_push($data,$row);
		}
		echo json_encode($data);
		// http_response_code(404);
	    $db = NULL;		// Close database

	} catch(PDOException $e) 	{
	    echo "ERROR you noob :P -> ";
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>