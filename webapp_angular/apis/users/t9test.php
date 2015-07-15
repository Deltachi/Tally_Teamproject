<?php
	try {
	    
	    $T9 = strtr(strtoupper("Domi"), 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' , '22233344455566677778889999'); //$_POST["T9"];	
	    
		echo $T9;
		
	} catch(PDOException $e) 	{
	    echo "ERROR you noob :P -> ";
	    echo $e->getMessage();
	    echo $e->getTraceAsString();
	}
?>