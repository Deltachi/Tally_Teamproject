angular.module('app.controllers.loginCtrl', []) 	
	.controller('loginCtrl', ['$scope','loginService','userDataService', function($scope,loginService,userDataService){
		
		$scope.$watch(function () { return loginService.getUser(); }, function (value) {
			$scope.user = value;
		});
		$scope.loggedIn = function(){
			if ($scope.user == null){
				return false;
			}
			else{
				return true;
			}
		}
	
		this.data;
		this.submitForm = function(submitData){
			this.loadUserData(submitData);
			$('#myModal').modal('hide');
		}

		this.loadUserData = function(submitData){
			console.log(submitData);
			loginService.setUser({"Username":submitData.username,"Password":submitData.password});
			var postData = {};
			var postMail = {};
			postData['request'] = submitData.username;
			var responseData;
			var userData; //temporary stored userdata for changes
			//load userData from server
			userDataService.getUserDataSync(postData).then(
				function(data){
					responseData = jQuery.parseJSON(data);
					// console.log(data);
					// console.log(responseData);

					//Convert the UserData ids from the catched backend data 
					userData = userDataService.getUserData();
					userData.id = responseData[0].User_ID;
					userData.firstname = responseData[0].Firstname;
					userData.lastname = responseData[0].Lastname;
					userData.username = responseData[0].Username;
					userData.password = responseData[0].Password;
					userData.imagePath = responseData[0].Image;
					userData.email = responseData[0].Email;
					userData.balance = responseData[0].Credits;
					userData.timestamp = responseData[0].Timestamp;
					userData.blocked = responseData[0].Blocked;
					userData.rights = responseData[0].Rights;
					userData.leaderboard = responseData[0].Leaderboard;
					userData.loginAttempts = responseData[0].Login_Attempts;
					//save the loaded UserData into active session service
					userDataService.setUserData(userData);
					//Debug
					console.log("Loaded: -> Users ID: "+userData.id+" - Username: "+userData.username);
					postMail['request'] = userData.id;
				});
			var responseMail;
			//Load mails from server
			userDataService.getUserMailSync(postMail).then(
				function(data){
					responseMail = jQuery.parseJSON(data);
					// console.log(data);
					// console.log(responseMail);
					userData.messages = responseMail;
					console.log("Loaded "+userData.messages.length+" messages");
					userDataService.setUserData(userData);
					console.log("Sucessfully built user object");
					console.log("...I wont show it in public.");
				});
		}
	}]);
