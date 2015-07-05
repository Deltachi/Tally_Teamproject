angular.module('app.services.userDataService', []) 
	

	.factory("userDataService", function($http){

		return {
		  	getUserDataSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/users/getUserData.php",
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
			getUserDataAsync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: true,
							url: "/apis/users/getUserData.php",
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
			getUserMailSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/users/getMessages.php",
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
			userData: {}
		}
	});
