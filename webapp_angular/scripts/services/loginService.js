angular.module('app.services.loginService', []) 
	

	.factory("loginService", function($http){
		user = null;
		function getUser() {
			return user;
		}
		function setUser(newData) {
			user = newData;
		}
		return {
			getUser: getUser,
			setUser: setUser,
		  	login: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/auth/login.php",
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
		}
	});