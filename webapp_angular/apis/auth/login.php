<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    $username = $_POST["request"];	//must be Username
	    $password = $_POST["request_2"];	//must be Password

	    $query = "SELECT * FROM Users WHERE Username = '".$username."' AND Password = '".$password."'";
		$results = $db->query($query);
		$rows = $results->fetchAll(PDO::FETCH_ASSOC);
		$data = array();
		foreach ($rows as $rowKey => $row) {
			array_push($data,$row);
		}
		if (!empty($data)){
			echo "SUCCESS - Erfolgreich Eingeloggt!";  //json_encode($data);
		}
		else{
			echo "ERROR - Daten stimmen nicht überein!";
		}
		// http_response_code(404);
	    $db = NULL;		// Close database

	} catch(PDOException $e) 	{
	    echo "ERROR you noob :P -> ";
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>