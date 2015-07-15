<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    if (isset($_POST["request"])){
	    	$name = $_POST["request"];	//must be Username
		}
		else{
			$name = $_POST["username"];
		}

	    $query = "SELECT * FROM Users WHERE Username = '".$name."'";
		$results = $db->query($query);
		$rows = $results->fetchAll(PDO::FETCH_ASSOC);
		$data = array();
		foreach ($rows as $rowKey => $row) {
			$data[] = $row;
			break;	//Break after 1 result. Should do that automatically, since Username is UNIQUE
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