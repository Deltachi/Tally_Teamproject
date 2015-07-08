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
				  				console.log("Successful service request");
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
			getItemAsync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/menu/getItem.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request");
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
			editItem: {}
		}
	});