angular.module('app.controllers.loginCtrl', []) 	
	.controller('loginCtrl', ['$scope','loginService','userDataService', function($scope,loginService,userDataService){
		
		$scope.loginError;

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
			
			console.log(submitData);
			var response;
			loginService.login(submitData).then(function (data) { 
				response = data;
			});
			if 	($.trim(response) == 'true') {
				$scope.loginError = null;
				this.loadUserData(submitData);
				$('#myModal').modal('hide');
			}
			else{
				$scope.loginError = "Username or Password incorrect!"
				console.log("Login not successful!");
				console.log(response);
			}
			
		}

		this.loadUserData = function(submitData){
			console.log(submitData);
			loginService.setUser({"Username":submitData.username,"Password":submitData.password});
			var postData = {};
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
					// userData = userDataService.getUserData();
					// userData.id = responseData[0].User_ID;
					// userData.firstname = responseData[0].Firstname;
					// userData.lastname = responseData[0].Lastname;
					// userData.username = responseData[0].Username;
					// userData.password = responseData[0].Password;
					// userData.imagePath = responseData[0].Image;
					// userData.email = responseData[0].Email;
					// userData.balance = responseData[0].Credits;
					// userData.timestamp = responseData[0].Timestamp;
					// userData.blocked = responseData[0].Blocked;
					// userData.rights = responseData[0].Rights;
					// userData.leaderboard = responseData[0].Leaderboard;
					// userData.loginAttempts = responseData[0].Login_Attempts;
					//save the loaded UserData into active session service
					// userDataService.setUserData(userData);
					userDataService.setUserData(responseData[0]);

					//Debug
					console.log("Loaded: -> Users ID: "+responseData[0].User_ID+" - Username: "+responseData[0].Username);
					postData['request'] = responseData[0].User_ID;
				});
			var responseMail;
			//Load mails from server
			userDataService.getUserMailSync(postData).then(
				function(data){
					responseMail = jQuery.parseJSON(data);
					// console.log(data);
					// console.log(responseMail);
					userData = userDataService.getUserData();
					userData.messages = responseMail;
					console.log("Loaded "+userData.messages.length+" messages");
					userDataService.setUserData(userData);
					// console.log("Sucessfully built user object");
					// console.log("...I wont show it in public.");
				});
			var responseFavorites;
			//Load mails from server
			userDataService.getUserFavoritesSync(postData).then(
				function(data){
					responseFavorites = jQuery.parseJSON(data);
					// console.log(data);
					console.log(responseFavorites);
					userData = userDataService.getUserData();
					userData.favorites = responseFavorites;
					console.log("Loaded "+userData.favorites.length+" favorites");
					userDataService.setUserData(userData);
					console.log("Sucessfully built user object");
					console.log("...I wont show it in public.");
				});
		}
	}]);
