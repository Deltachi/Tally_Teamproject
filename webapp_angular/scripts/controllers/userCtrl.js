//User-Controller der Daten fetcht und das Dropdownmenü 
//und alle weiteren user-relevanten Seiten aktuell hält,
//btw. alle relevanten Funktionen zur Aktualisierung bereithält
angular.module('app.controllers.userCtrl', []) 

	.controller('userCtrl', ['$scope', '$http', function($scope, $http){
		$scope.userData = null;
		


		$scope.userData = {
			"firstname": "Angelika",
			"lastname": "Lipp",
			"nick": "Geli",
			"password": "abcd1234",
			"mail": "gelismail@me.com",
			"leaderboard": true,
			"balance": 25.50,
			"messages": [
				{"msg_id":"0", "title": "System", "type":"alert-default","msg": "Did you check out our new menu?"},
				{"msg_id":"1", "title": "System", "type":"alert-info","msg": "Just today 10% off, for Snickers and Twix!"},
				{"msg_id":"2", "title": "Shop", "type":"alert-warning","msg": "Last 3 Twix, get them now!"},
				{"msg_id":"3", "title": "Admin", "type":"alert-danger","msg": "Pay your bills!"},
				{"msg_id":"4", "title": "Angyinski", "type":"alert-success","msg": "Let's watch POI"},
				{"msg_id":"5", "title": "Samaritan", "type":"alert-danger","msg": "I am watching you."},
				{"msg_id":"6", "title": "Samaritan", "type":"alert-danger","msg": "JK."}
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
		};
		$scope.userData.feeds = function(){ return $scope.userData.messages.length;}
		$scope.delete = function(index){
			console.log("Gonna delete this msg: " + $scope.userData.messages[index].msg);
			$scope.userData.messages.splice(index, 1);
		};
		// $("#idForm").submit(function() {

			var service_msg = "getMessages.php"; // the script where you handle the form input.
			var service_userData = "/apis/users/getUserData.php";
			var url;
			var postData = {};
			postData['request'] = "Geli";
			var responseData;
			$.ajax({
				type: "POST",
				url: service_userData,
				data: postData, // serializes the form's elements.
				success: function(data)
				{
					// alert(data); // show response from the php script.
					console.log(data);
					responseData = jQuery.parseJSON(data);
					console.log(responseData);

					$scope.userData.balance = responseData[0].Credits;
				},
				error: function(jqXHR, status, errors){
					console.log(status);
				}
			});

			// return false; // avoid to execute the actual submit of the form.
		// });
	}])