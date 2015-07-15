<?php
	try {
		session_start();
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    if (isset($_POST["username"])){$username = $_POST["username"];}else{$username = "";}	//must be Username
	    if (isset($_POST["password"])){$password = $_POST["password"];}else{$password = "";}	//must be Password

	    $query = "SELECT * FROM Users WHERE Username = '".$username."' AND Password = '".$password."'";
		$results = $db->query($query);
		$rows = $results->fetchAll(PDO::FETCH_ASSOC);
		$data = array();
		foreach ($rows as $rowKey => $row) {
			array_push($data,$row);

		}
		if (!empty($data)){
			echo 'true';//json_encode($data);

			$_SESSION['username'] = $data[0]['Username'];
			$_SESSION['user_ID'] = $data[0]['User_ID'];
			$_SESSION['rights'] = $data[0]['Rights'];
			$_SESSION['password'] = $data[0]['Password'];

		}
		else{
			echo 'nodata';
		}
		// http_response_code(404);
	    $db = NULL;		// Close database

	} catch(PDOException $e) 	{
	    echo "ERROR you noob :P -> ";
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>