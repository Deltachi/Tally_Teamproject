//User-Controller der Daten fetcht und das Dropdownmenü 
//und alle weiteren user-relevanten Seiten aktuell hält,
//btw. alle relevanten Funktionen zur Aktualisierung bereithält
angular.module('app.controllers.userCtrl', []) 

	.controller('userCtrl', ['$scope', 'userDataService', function($scope, userDataService){
		$scope.loading = true;

		userDataService.userData = null;
		userDataService.userData = {
			"firstname": "Angelika",
			"lastname": "Lipp",
			"nick": "Geli",
			"password": "abcd1234",
			"mail": "gelismail@me.com",
			"leaderboard": true,
			"balance": 0,
			"messages": [
				{"Message_ID":"0", "Sender": "System", "Title": "MsgTitle", "Type":"alert-default","Message": "Did you check out our new menu?"},
				{"Message_ID":"1", "Sender": "System", "Title": "MsgTitle", "Type":"alert-info","Message": "Just today 10% off, for Snickers and Twix!"},
				{"Message_ID":"2", "Sender": "Shop", "Title": "MsgTitle", "Type":"alert-warning","Message": "Last 3 Twix, get them now!"},
				{"Message_ID":"3", "Sender": "Admin", "Title": "MsgTitle", "Type":"alert-danger","Message": "Pay your bills!"},
				{"Message_ID":"4", "Sender": "Angyinski", "Title": "MsgTitle", "Type":"alert-success","Message": "Let's watch POI"},
				{"Message_ID":"5", "Sender": "Samaritan", "Title": "MsgTitle", "Type":"alert-danger","Message": "I am watching you."},
				{"Message_ID":"6", "Sender": "Samaritan", "Title": "MsgTitle", "Type":"alert-danger","Message": "JK."}
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

		var postData = {};
		var postMail = {};
		postData['request'] = "Geli";
		postMail['request'] = 6;
		var responseData;
		var responseMail;

		//load userData from server
		userDataService.getUserDataSync(postData).then(
			function(data){
				responseData = jQuery.parseJSON(data);
				console.log(data);
				console.log(responseData);
				userDataService.userData.balance = responseData[0].Credits;
				$scope.loading = false;
			});

		//Load mails from server
		userDataService.getUserMailSync(postMail).then(
			function(data){
				responseMail = jQuery.parseJSON(data);
				console.log(data);
				console.log(responseMail);
				userDataService.userData.messages = responseMail;
				$scope.loading = false;
				console.log(userDataService.userData);
			});

		userDataService.userData.feeds = function(){ return userDataService.userData.messages.length;}
		$scope.barColor = function(){
			var color;
			var balance = userDataService.userData.balance;
			if (balance < 0){
				color = "danger";
			}
			else{
				if(balance <= 10.0){
					color = "warning";
				}
				else{
					color = "success";
				}
			}
			return color;
		};
		$scope.delete = function(index, Message_ID){
			console.log("Gonna delete this msg: " + userDataService.userData.messages[index].Message + " -> msg_id = " + Message_ID);
			userDataService.userData.messages.splice(index, 1);
		};

		$scope.userData = userDataService.userData;

	}])