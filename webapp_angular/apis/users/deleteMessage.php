<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    $Message_ID = $_POST["Message_ID"];	//

	    $query = "DELETE FROM Messages WHERE Message_ID = '".$Message_ID."'";
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