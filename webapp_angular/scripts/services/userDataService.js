angular.module('app.services.userDataService', []) 
	

	.factory("userDataService", function($http){
		var userData =  {
			"firstname": "Unknown",
			"lastname": "Intruder",
			"username": "(no name)",
			"password": "0000",
			"mail": "nomail@me.com",
			"leaderboard": true,
			"balance": -6.66,
			"messages": [
				{"Sender":"System","Type":"alert-danger","Title":"Hey, intruder","Message":"I'm watching you."},
			],
			"history": [
				{"history_id":"0", "title": "No recent purchases", "price":"","date": ""},
				
			],
			"favorites": [
				{"favorite_id":"0", "title": "Kaffee L", "price":"1.50"},
				{"favorite_id":"1", "title": "Cappuchino", "price":"1.20"},
				{"favorite_id":"2", "title": "Snickers", "price":"0.50"},
				{"favorite_id":"3", "title": "Kaffee M", "price":"1"},
				{"favorite_id":"4", "title": "Macchiato", "price":"1.50"}
			]
		};
		function getUserData() {
			return userData;
		}
		function setUserData(newData) {
			userData = newData;
		}
		return {
			getUserData: getUserData,
			setUserData: setUserData,
		// }
		// return {
		  	getUserDataSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/users/getUserData.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request: getUserDataSync");
				  				// var responseData;
								// responseData = jQuery.parseJSON(response);
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
				  				console.log("Successful service request: getUserDataAsync");
				  				
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
				  				console.log("Successful service request: getUserMailSync");
				  				
								return response.data;
							},
							error: function(jqXHR, status, errors){
								console.log("Error service request");
								console.log(status);
							}
						});
			},
			getUserFavoritesSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/users/getFavorites.php",
							data: postData, // serializes the form's elements.
							success: function(response){
				  				console.log("Successful service request");

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
