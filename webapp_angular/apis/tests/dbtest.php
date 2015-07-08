<?php
	try {
	    // Use database file "database.sqlite" or create a new one if not exists:
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    // Create tables, if not exists:
	    //$sql = "CREATE TABLE IF NOT EXISTS SensorValues (VID INTEGER PRIMARY KEY, TStamp TEXT, SName TEXT,	Value INTEGER, Sync INTEGER)";
	    //$db->exec($sql);
	    // Place INSERT, UPDATE or SELECT statements here!

	    $name = $_POST["username"];

	    $query = "SELECT * FROM Users WHERE Username = '".$name."'";
		$results = $db->query($query);
		$rows = $results->fetchAll(PDO::FETCH_ASSOC);
		$data = array();
		foreach ($rows as $rowKey => $row) {
			$data[] = $row;
			break;
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