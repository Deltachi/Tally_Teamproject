<?php
	try {
	    // Use database file "database.sqlite" 
	    $db = new PDO('sqlite:../../sqlite/database.sqlite');
	    // Throw exceptions on error
	    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	    // $grocery_id = $_POST["Grocery_ID"];	
	    $grocery_name = $_POST["Name"];	
	    $grocery_nick = $_POST["Nick"];	
	    if(isset($_POST["Barcode"])){$grocery_barcode = $_POST["Barcode"];}else{$grocery_barcode = "";}
	    $grocery_amount = $_POST["Amount"];	
	    $grocery_price = $_POST["Price"];	
	    $grocery_prime_cost = $_POST["Prime_Cost"];	
	    if(isset($_POST["Image"])){$grocery_image = $_POST["Image"];}else{$grocery_image = "";}
	    if(isset($_POST["Info"])){$grocery_info = $_POST["Info"];}else{$grocery_info = "";}	
	    if(isset($_POST["Ingredients"])){$grocery_ingredients = $_POST["Ingredients"];}else{$grocery_ingredients = 0;}
	    $grocery_typ = $_POST["Typ"];
	    $grocery_type_group = $_POST["Type_Group"];
	    $grocery_visible = $_POST["Visible"];	

	    

		$query = "INSERT INTO Groceries(Name, Nick, Barcode, Amount, Price, Prime_Cost, Image, Info, Ingredients, Typ, Type_Group, Visible) VALUES('".$grocery_name."','".$grocery_nick."','".$grocery_barcode."','".$grocery_amount."','".$grocery_price."','".$grocery_prime_cost."','".$grocery_image."','".$grocery_info."','".$grocery_ingredients."','".$grocery_typ."','".$grocery_type_group."','".$grocery_visible."')";
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