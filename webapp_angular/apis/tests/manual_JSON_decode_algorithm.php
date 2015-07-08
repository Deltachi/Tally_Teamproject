<?php
	try {
	    // Use database file "database.sqlite" or create a new one if not exists:
	    $db = new PDO('sqlite:database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    // Create tables, if not exists:
	    //$sql = "CREATE TABLE IF NOT EXISTS SensorValues (VID INTEGER PRIMARY KEY, TStamp TEXT, SName TEXT,	Value INTEGER, Sync INTEGER)";
	    //$db->exec($sql);
	    // Place INSERT, UPDATE or SELECT statements here!

	    $query = "SELECT * FROM Users WHERE Firstname = 'Dominik'";
		$results = $db->query($query);
		$rows = $results->fetchAll(PDO::FETCH_ASSOC);
		//use $rows
		$data = array();
		$json = '{';
		$count = 0;
		foreach ($rows as $rowKey => $row) {
			// $data[] = $row['User_ID'] . " " . $row['Firstname'] . " " . $row['Lastname'] . " " . $row['Username'] . " " . $row['Password'];
			// $json .= "'" . $rowKey . "'{";
			$json .= '"UserData":{';

			foreach ($row as $key => $value) {
				if ($count != 0){
					$json .= ', ';
				}
				$json .= '"' . $key . '":"' . $value . '"';
				// echo $count;
				$count .= 1;
			}
			$count = 0;
			$json .= '}';
			$data[] = $row;
			break;
		}
		echo $json;
		echo json_encode($data);


	    $db = NULL;		// Close database

	} catch(PDOException $e) 	{
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>	
