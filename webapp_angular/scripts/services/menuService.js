angular.module('app.services.menuService', []) 
	

	.factory("menuService", function($http){

		return {
		  	getMenuSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/menu/getMenu.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request: getMenuSync");
				  				// var responseData;
								// alert(response); // show response from the php script.
								// console.log(response);
								// responseData = jQuery.parseJSON(response);
								// console.log(responseData);

								return response.data;
							},
							error: function(jqXHR, status, errors){
								console.log("Error service request");
								console.log(status);
							}
						});
			},
			getItemSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/menu/getItem.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request: getItemSync");
				  				// var responseData;
								// alert(response); // show response from the php script.
								// console.log(response);
								// responseData = jQuery.parseJSON(response);
								// console.log(responseData);

								return response.data;
							},
							error: function(jqXHR, status, errors){
								console.log("Error service request");
								console.log(status);
							}
						});
			},
			updateItemSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/menu/setItem.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request: updateItemSync");
				  				console.log(response+ " rows where affected");
				  				// var responseData;
								// alert(response); // show response from the php script.
								// console.log(response);
								// responseData = jQuery.parseJSON(response);
								// console.log(responseData);

								return response.data;
							},
							error: function(jqXHR, status, errors){
								console.log("Error service request");
								console.log(status);
							}
						});
			},
			insertItemSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/menu/addItem.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request: insertItemSync");
				  				console.log(response+ " rows where affected");
				  				// var responseData;
								// alert(response); // show response from the php script.
								// console.log(response);
								// responseData = jQuery.parseJSON(response);
								// console.log(responseData);

								return response.data;
							},
							error: function(jqXHR, status, errors){
								console.log("Error service request");
								console.log(status);
							}
						});
			},
			deleteItemSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/menu/deleteItem.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request: deleteItemSync");
				  				console.log(response+ " rows where affected");
				  				// var responseData;
								// alert(response); // show response from the php script.
								// console.log(response);
								// responseData = jQuery.parseJSON(response);
								// console.log(responseData);

								return response.data;
							},
							error: function(jqXHR, status, errors){
								console.log("Error service request");
								console.log(status);
							}
						});
			},
			menu: {
				drinks: {},				
				sweets: {}
			},
			editItem: {},
			editMode: 'update'
		}
	});