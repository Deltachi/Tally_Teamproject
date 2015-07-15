<?php
	try {
		session_start();
	    
		$data = array();
		// foreach ($rows as $rowKey => $row) {
		// 	array_push($data,$row);
		// }
		foreach ($_SESSION as $key=>$value) {
			//array_push($data,$value);
			$data[$key] = $value;
		}
		if (!empty($data)){
			echo json_encode($data);
		}
		else{
			echo "nodata";
		}
		
	} catch(PDOException $e) 	{
	    echo "ERROR you noob :P -> ";
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>