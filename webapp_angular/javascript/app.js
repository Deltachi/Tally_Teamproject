var app = angular.module('app',['ui.router']);

//UI-ROUTER
app.config(['$urlRouterProvider','$stateProvider',function($urlRouterProvider, $stateProvider) {
	$urlRouterProvider.otherwise('/');
	$stateProvider
		.state('/', {
			url: '/',
			templateUrl: 'ng-templates/home.html'
		})
		.state('home', {
			url: '/home',
			templateUrl: 'ng-templates/home.html'
		})
		.state('menu', {
			url: '/menu',
			templateUrl: 'ng-templates/menu.html',
			// controller: 'menuCtrl'
		})
		.state('notifications', {
			url: '/notifications',
			templateUrl: 'ng-templates/notifications.html',
		})
		.state('leaderboard', {
			url: '/leaderboard',
			templateUrl: 'ng-templates/leaderboard.html',
		})
		.state('settings', {
			url: '/settings',
			templateUrl: 'ng-templates/settings.html',
		})
		.state('favorites', {
			url: '/favorites',
			templateUrl: 'ng-templates/favorites.html',
		})
}]);

//CONTROLLER
app.controller('loginCtrl', function(){
	this.loggedIn = false;
	this.switchMode = function(){
		this.loggedIn = !this.loggedIn;
		console.log("Client logged in: "+this.loggedIn);
	}
});

//User-Controller der Daten fetcht und das Dropdownmenü 
//und alle weiteren user-relevanten Seiten aktuell hält,
//btw. alle relevanten Funktionen zur Aktualisierung bereithält
app.controller('userCtrl', ['$scope', '$http', function($scope, $http){
	$scope.userData = null;
	$scope.userData = {
		"nick": "Custom Nick",
		"firstname": "MyFirstname",
		"lastname": "MyLastname",
		"messages": [
			{"title": "System", "type":"alert-success","msg": "Did you check out our new menu?"},
			{"title": "System", "type":"alert-info","msg": "Just today 10% off, for Snickers and Twix!"},
			{"title": "Shop", "type":"alert-warning","msg": "Last 3 Twix, get them now!"},
			{"title": "Admin", "type":"alert-danger","msg": "Pay your bills!"},
			{"title": "Angyinski", "type":"alert-success","msg": "Let's watch POI"},
			{"title": "Samaritan", "type":"alert-danger","msg": "I am watching you."}
		],
		"history": [
			{"title": "Kaffee L", "price":"1.50","date": "1435356176000"},
			{"title": "Cappuchino", "price":"1.20","date": "1435356176000"},
			{"title": "Snickers", "price":"0.50","date": "1435356176000"},
			{"title": "Kaffee M", "price":"1","date": "1435356176000"},
			{"title": "Kaffee L", "price":"1.50","date": "1435313176000"},
			{"title": "Cappuchino", "price":"1.20","date": "1435313176000"},
			{"title": "Snickers", "price":"0.50","date": "1435313176000"},
			{"title": "Kaffee M", "price":"1","date": "1435313176000"}
		],
		"balance": 25.50
	};
	$scope.userData.feeds = $scope.userData.messages.length;
	$scope.delete = function(){
		console.log("Gonna delete this msg: " + $scope.userData.messages[3].msg);
		$scope.userData.messages[3] = null;
	};
}])
app.controller('menuCtrl',['$scope','$http', function($scope,$http){
	
	
	$scope.drinks = null;
	$scope.sweets = null;

	$scope.list = null;
	$http.get('/json/menuContent.json')
	.success(function(res) {
		$scope.list = res;
		$scope.drinks = $scope.list.drinks;
		$scope.sweets = $scope.list.sweets;
		console.log($scope.list.drinks);
		console.log($scope.list.sweets);
	})
	.error(function(res,status,error,config){
		$scope.list = [{name:"Error",description:"Could not load json data"}];
	});
}]);

app.controller('updatedCtrl', ['$scope','$http', function($scope,$http){
	$scope.date = null;
	$scope.time = null;

	$scope.data = null;
	$http.get('/json/updated.json')
	.success(function(res) {
		$scope.data = res;
		$scope.date = $scope.data.date;
		$scope.time = $scope.data.time;
		console.log($scope.data.date);
		console.log($scope.data.time);
	})
	.error(function(res,status,error,config){
		$scope.date = "Error";
		$scope.time = "Error";
	});
}])

//DIRECTIVES
app.directive('myNavbar', function(){
	return {
		restrict: 'E',
		templateUrl: '/ng-templates/navbar.html',
		controller: 'loginCtrl'
	};
});	
app.directive('login', function(){
	return {
		restrict: 'E',
		templateUrl: '/ng-templates/login.html',
	};
});	
app.directive('myFooter', function(){
	return {
		restrict: 'E',
		templateUrl: '/ng-templates/footer.html'
	};
});	

