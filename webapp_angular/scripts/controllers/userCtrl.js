//User-Controller der Daten fetcht und das Dropdownmenü 
//und alle weiteren user-relevanten Seiten aktuell hält,
//btw. alle relevanten Funktionen zur Aktualisierung bereithält, auch
//Admin Tools für Menü, Settings etc
angular.module('app.controllers.userCtrl', []) 

	.controller('userCtrl', ['$scope', 'userDataService', function($scope, userDataService){
		//For notifications, if theres no Data, there will be a 'loading...' screen
		$scope.loading = true;
		//In Settings, if the static fields or the textfields are shown
		$scope.editing = false;

		//For notifications, if theres no Data, there will be a 'loading...' screen
		if (userDataService.getUserData() != null) {
			$scope.loading = false;
		}

		//For notifications, gets data and calculates the color for the bar
		var data = userDataService.getUserData();
		$scope.barColor = function(){
			var color;
			var balance = data.Credits;
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

		//In notifications, deletes a message from the internal userData variable
		$scope.deleteMessage = function(index, Message_ID){
			console.log("Gonna delete this msg: " + userDataService.getUserData().messages[index].Message + " -> msg_id = " + Message_ID);
			userDataService.getUserData().messages.splice(index, 1);
			var data = {
				"Message_ID":  Message_ID
			};
			userDataService.deleteMessageSync(data).then(function(response){
				console.log(response + " affected rows");
			})
		};

		$scope.newMessage;

		$scope.submitMessage = function(data){
			userDataService.insertMessageSync(data).then(function(response){
				console.log("Sent message, count: "+ response);
			})
		}

		//In Settings, if the static fields or the textfields are shown
		$scope.setEditing = function(value){
			console.log("Entering edit mode: "+value);
			$scope.editing = value;
		}

		$scope.$watch(function () { return userDataService.getUserData(); }, function (value) {
			$scope.userData = value;
		});

		//For settings Admin Edition: Select option field with User_ID value = userSelect
		this.userSelect;
		//Admin own ID
		this.myID;

		// If user is admin, then load all users data...
		if (userDataService.getUserData().Rights >= 3){
			var usersData;
			//load Users from server
			userDataService.getUsersSync().then(
				function(data){
					usersData = jQuery.parseJSON(data);
					// console.log(data);
					console.log(usersData);
					userDataService.users= usersData;
					
				});
			//calculate own id
			this.myID = userDataService.getUserData().User_ID;
			//set the default edit-settings to own settings
			userDataService.editUser = userDataService.users[this.myID];
		}
		else{
			//just load own data in the editBuffer variable
			userDataService.editUser = userDataService.getUserData();
		}

		//switch editBuffer data with other users data
		this.setEditUser = function(data_id){
			console.log("Change user to edit ID: "+data_id);
			console.log(userDataService.users[data_id]);

			// var userDataTemp;

			// userDataTemp = $scope.editUser;
			// userDataTemp.id = userDataService.users[data_id].User_ID;
			// userDataTemp.firstname = userDataService.users[data_id].Firstname;
			// userDataTemp.lastname = userDataService.users[data_id].Lastname;
			// userDataTemp.username = userDataService.users[data_id].Username;
			// userDataTemp.password = userDataService.users[data_id].Password;
			// userDataTemp.imagePath = userDataService.users[data_id].Image;
			// userDataTemp.email = userDataService.users[data_id].Email;
			// userDataTemp.balance = userDataService.users[data_id].Credits;
			// userDataTemp.timestamp = userDataService.users[data_id].Timestamp;
			// userDataTemp.blocked = userDataService.users[data_id].Blocked;
			// userDataTemp.rights = userDataService.users[data_id].Rights;
			// userDataTemp.leaderboard = userDataService.users[data_id].Leaderboard;
			// userDataTemp.loginAttempts = userDataService.users[data_id].Login_Attempts;

			userDataService.editUser = userDataService.users[data_id];
		}

		//post data to backend
		$scope.submitUserData = function(data){
			console.log(data);
			userDataService.setUserSync(data).then(function(response){
				console.log("Affected rows: "+response);
			})
			$scope.editing = false;
			
		}

		this.newDrink_ID;
		this.newSweet_ID;
		
		$scope.reloadFavorites = function(postData){
			var responseFavorites;
			//Load favorites from server
			userDataService.getUserFavoritesSync(postData).then(
				function(data){
					responseFavorites = jQuery.parseJSON(data);
					console.log(data);
					console.log(responseFavorites);
					userData = userDataService.getUserData();
					userData.favorites = responseFavorites;
					console.log("Loaded "+userData.favorites.length+" favorites");
					userDataService.setUserData(userData);
					console.log("Sucessfully built user object");
					console.log("...I wont show it in public.");
				});
		}

		$scope.addFavorite = function(user_id, grocery_id){
			console.log("Going to add a favorite with grocery_id: "+ grocery_id + " user_id: "+ user_id);
			var data = {
				"User_ID":  user_id,
				"Grocery_ID": grocery_id
			};
			userDataService.addFavoriteSync(data).then(function(response){
				console.log(response + " affected rows");
			})
			$scope.reloadFavorites({"request":user_id});

		}
		$scope.deleteFavorite = function(favorite_id, index){
			console.log("Going to delete favorite with id: "+ favorite_id);
			var data = {
				"Favorite_ID":  favorite_id
			};
			userDataService.deleteFavoriteSync(data).then(function(response){
				console.log(response + " affected rows");
			})
			userDataService.getUserData().favorites.splice(index, 1);
		}

		$scope.$watch(function () { return userDataService.users; }, function (value) {
			$scope.usersData = value;
		});
		$scope.$watch(function () { return userDataService.editUser; }, function (value) {
			$scope.editUser = value;
		});


		
	}])