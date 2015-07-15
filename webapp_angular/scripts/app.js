var app = angular.module('app',[
	'ui.router',
	'ui.bootstrap',
	'app.directives.myNavbar',
	'app.directives.myFooter',
	'app.directives.login',
	'app.directives.menuModal',

	'app.controllers.userCtrl',
	'app.controllers.menuCtrl',
	'app.controllers.loginCtrl',
	'app.controllers.loginModalCtrl',
	'app.controllers.updatedCtrl',
	'app.controllers.logoutCtrl',
	'app.controllers.lbCtrl',

	'app.services.myService',
	'app.services.userDataService',
	'app.services.menuService',
	'app.services.loginService',
	'app.services.loginModalService'

	]);

//UI-ROUTER
app.config(['$urlRouterProvider','$stateProvider',function($urlRouterProvider, $stateProvider) {
	$urlRouterProvider.otherwise('/');
	$stateProvider
		.state('/', {
			url: '/',
			templateUrl: 'ng-templates/home.html',
			data: {
				requireLogin: false 
			}
		})
		.state('home', {
			url: '/home',
			templateUrl: 'ng-templates/home.html',
			data: {
				requireLogin: false 
			}
		})
		.state('menu', {
			url: '/menu',
			templateUrl: 'ng-templates/menu.html',
			data: {
				requireLogin: false 
			}
		})
		.state('app' ,{
			abstract: true,
			data: {
				requireLogin: true //this property will apply to all children of 'app'
			}
		})
		.state('notifications', {
			url: '/notifications',
			templateUrl: 'ng-templates/notifications.html',
			data: {
				requireLogin: true 
			}
		})
		.state('leaderboard', {
			url: '/leaderboard',
			templateUrl: 'ng-templates/leaderboard.html',
			data: {
				requireLogin: true 
			}
		})
		.state('settings', {
			url: '/settings',
			templateUrl: 'ng-templates/settings.html',
			data: {
				requireLogin: true 
			}
		})
		.state('favorites', {
			url: '/favorites',
			templateUrl: 'ng-templates/favorites.html',
			data: {
				requireLogin: true 
			}
		})
		.state('logout', {
			url: '/logout',
			templateUrl: 'ng-templates/logout.html',
			controller: 'logoutCtrl',
			data: {
				requireLogin: true 
			}
		})
}]);

app.filter('positive', function() {
        return function(input) {
            if (!input) {
                return 0;
            }

            return Math.abs(input);
        };
    })

app.run(['$rootScope','$location', '$state','loginService', 'loginModalService', 'userDataService', function($rootScope, $location, $state, loginService, loginModalService, userDataService){
	
	var response;
	var unparsed;
	loginService.retrieveData().then(function (data) { 
			if (data != "nodata"){
				response =  jQuery.parseJSON(data);
			}
			else{
				response = "nodata";
			}
	});
	if 	(response != "nodata") {
		console.log("Successfully retrieved last Session!")
		loginService.setUser({"Username":response.username,"Password":response.password});
			var postData = {};
			var postMail = {};
			postData['request'] = response.username;
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
					// console.log(responseFavorites);
					userData = userDataService.getUserData();
					userData.favorites = responseFavorites;
					console.log("Loaded "+userData.favorites.length+" favorites");
					userDataService.setUserData(userData);
					// console.log("Sucessfully built user object");
					// console.log("...I wont show it in public.");
				});
				var responseHistory;
			//Load mails from server
			userDataService.getUserHistorySync(postData).then(
				function(data){
					responseHistory = jQuery.parseJSON(data);
					// console.log(data);
					// console.log(responseHistory);
					userData = userDataService.getUserData();
					userData.history = responseHistory;
					console.log("Loaded "+userData.history.length+" history");
					userDataService.setUserData(userData);
					console.log("Sucessfully built user object");
					console.log("...I wont show it in public.");
				});
		
		
	}
	else{
		console.log("User did not have a valid session!");
	}


	$rootScope.$on('$stateChangeStart', function(event, toState, toParams){
		var requireLogin = toState.data.requireLogin;
		console.log("checking access..");
		console.log("login required: "+ requireLogin);

		if (requireLogin && loginService.getUser() == null){
			console.log("WARNING, unauthorized access!")
			event.preventDefault();
			// $('#myModal').modal('show');
			loginModalService()
				.then(function(){
					// return $state.go(toState.name, toParams);
					return $state.go('home');
				})
				.catch(function(){
					return $state.go('home');
				})
			// $state.go('home');

		}
		if (requireLogin && loginService.getUser() != null){
			//load user data 
		}
	});
}]);



