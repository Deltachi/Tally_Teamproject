<?php
	try {
		session_start();
	    
		session_destroy();
		
		echo true;
		
		
		
		
		

	} catch(PDOException $e) 	{
	    echo "ERROR you noob :P -> ";
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>