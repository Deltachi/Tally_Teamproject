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
			getUserFavoritesSync: function(postData){
			  	return	$.ajax({
							type: "POST",
							async: false,
							url: "/apis/users/getFavorites.php",
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
			//Dummy data
			userData: {
				"firstname": "Unknown",
				"lastname": "Intruder",
				"nick": "(no name)",
				"password": "0000",
				"mail": "nomail@me.com",
				"leaderboard": true,
				"balance": -6.66,
				"messages": [
					{},
				],
				"history": [
					{"history_id":"0", "title": "Kaffee L", "price":"1.50","date": "1435356176000"},
					{"history_id":"1", "title": "Cappuchino", "price":"1.20","date": "1435356176000"},
					{"history_id":"2", "title": "Snickers", "price":"0.50","date": "1435356176000"},
					{"history_id":"3", "title": "Kaffee M", "price":"1","date": "1435356176000"},
					{"history_id":"4", "title": "Kaffee L", "price":"1.50","date": "1435313176000"},
					{"history_id":"5", "title": "Cappuchino", "price":"1.20","date": "1435313176000"},
					{"history_id":"6", "title": "Snickers", "price":"0.50","date": "1435313176000"},
					{"history_id":"7", "title": "Kaffee M", "price":"1","date": "1435313176000"}
				],
				"favorites": [
					{"favorite_id":"0", "title": "Kaffee L", "price":"1.50"},
					{"favorite_id":"1", "title": "Cappuchino", "price":"1.20"},
					{"favorite_id":"2", "title": "Snickers", "price":"0.50"},
					{"favorite_id":"3", "title": "Kaffee M", "price":"1"},
					{"favorite_id":"4", "title": "Macchiato", "price":"1.50"}
				]
			}
		}
	});
