//User-Controller der Daten fetcht und das Dropdownmenü 
//und alle weiteren user-relevanten Seiten aktuell hält,
//btw. alle relevanten Funktionen zur Aktualisierung bereithält
angular.module('app.controllers.userCtrl', []) 

	.controller('userCtrl', ['$scope', 'userDataService', function($scope, userDataService){
		$scope.loading = true;

		

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
				userDataService.userData.firstname = responseData[0].Firstname;
				userDataService.userData.lastname = responseData[0].Lastname;
				userDataService.userData.nick = responseData[0].Username;

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