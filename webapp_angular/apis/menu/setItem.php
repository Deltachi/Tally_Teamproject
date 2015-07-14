<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    $grocery_id = $_POST["Grocery_ID"];	
	    $grocery_name = $_POST["Name"];	
	    $grocery_nick = $_POST["Nick"];	
	    $grocery_barcode = $_POST["Barcode"];
	    $grocery_amount = $_POST["Amount"];	
	    $grocery_price = $_POST["Price"];	
	    $grocery_prime_cost = $_POST["Prime_Cost"];	
	    $grocery_image = $_POST["Image"];	
	    $grocery_info = $_POST["Info"];	
	    $grocery_ingredients = $_POST["Ingredients"];
	    $grocery_typ = $_POST["Typ"];
	    $grocery_type_group = $_POST["Type_Group"];
	    $grocery_visible = $_POST["Visible"];	

		$query = "UPDATE Groceries SET Name='".$grocery_name."' , Nick='".$grocery_nick."' , Barcode='".$grocery_barcode."' , Amount='".$grocery_amount."' , Price='".$grocery_price."' , Prime_Cost='".$grocery_prime_cost."' , Image='".$grocery_image."' , Info='".$grocery_info."' , Ingredients='".$grocery_ingredients."' , Typ='".$grocery_typ."' , Type_Group='".$grocery_type_group."' , Visible='".$grocery_visible."'  WHERE Grocery_ID = '".$grocery_id."'";
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