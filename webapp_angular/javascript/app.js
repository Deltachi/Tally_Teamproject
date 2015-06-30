var app = angular.module('app',['ui.router']);

app.factory("myService", function(){

  return {sharedObject: {data: false } }

});


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
			templateUrl: 'ng-templates/menu.html'
			// controller: 'menuCtrl'
		})
		.state('notifications', {
			url: '/notifications',
			templateUrl: 'ng-templates/notifications.html'
		})
		.state('leaderboard', {
			url: '/leaderboard',
			templateUrl: 'ng-templates/leaderboard.html'
		})
		.state('settings', {
			url: '/settings',
			templateUrl: 'ng-templates/settings.html'
		})
		.state('favorites', {
			url: '/favorites',
			templateUrl: 'ng-templates/favorites.html'
		})
		.state('logout', {
			url: '/logout',
			templateUrl: 'ng-templates/logout.html',
			controller: 'logoutCtrl'
		})
}]);

//CONTROLLER
app.controller('loginCtrl', ['$scope','myService', function($scope,myService){
	$scope.loggedIn = myService.sharedObject.data;
	$scope.switchMode = function(){
		myService.sharedObject.data = !myService.sharedObject.data;
		$scope.loggedIn = myService.sharedObject.data;
		console.log("Client logged in: "+$scope.loggedIn);
		console.log("myService variable: "+myService.sharedObject.data);

	}
	$scope.getLogin = function(){
		return myService.sharedObject.data;
	}
}]);

//User-Controller der Daten fetcht und das Dropdownmenü 
//und alle weiteren user-relevanten Seiten aktuell hält,
//btw. alle relevanten Funktionen zur Aktualisierung bereithält
app.controller('userCtrl', ['$scope', '$http', function($scope, $http){
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
			{"title": "System", "type":"alert-success","msg": "Did you check out our new menu?"},
			{"title": "System", "type":"alert-info","msg": "Just today 10% off, for Snickers and Twix!"},
			{"title": "Shop", "type":"alert-warning","msg": "Last 3 Twix, get them now!"},
			{"title": "Admin", "type":"alert-danger","msg": "Pay your bills!"},
			{"title": "Angyinski", "type":"alert-success","msg": "Let's watch POI"},
			{"title": "Samaritan", "type":"alert-danger","msg": "I am watching you."},
			{"title": "Samaritan", "type":"alert-danger","msg": "JK."}
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
		"favorites": [
			{"title": "Kaffee L", "price":"1.50"},
			{"title": "Cappuchino", "price":"1.20"},
			{"title": "Snickers", "price":"0.50"},
			{"title": "Kaffee M", "price":"1"},
			{"title": "Macchiato", "price":"1.50"}
		]
	};
	$scope.userData.feeds = function(){ return $scope.userData.messages.length;}
	$scope.delete = function(index){
		console.log("Gonna delete this msg: " + $scope.userData.messages[index].msg);
		$scope.userData.messages.splice(index, 1);
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
app.controller('lbCtrl', ['$scope','$http', function($scope,$http){
	$scope.caffein = null;
	$scope.sugar = null;

	$scope.data = null;
	$http.get('/json/leaderboard.json')
	.success(function(res) {
		$scope.data = res;
		$scope.caffein = $scope.data.caffein;
		$scope.sugar = $scope.data.sugar;
		console.log($scope.data.caffein);
		console.log($scope.data.sugar);
	})
	.error(function(res,status,error,config){
		$scope.date = "Error";
		$scope.time = "Error";
	});
}])

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
app.controller('logoutCtrl', ['$scope','$location', '$state', 'myService', function($scope,$location,$state,myService){
	function redirect(){
  //   	if ($.cookie('session') == null){
		// 	console.log('NO COOKIE THERE >.>')
		// }
		// else{
			// $.removeCookie('session');
			myService.sharedObject.data = false;
			console.log('myService variable: '+myService.sharedObject.data);

			$state.go('home')
		// }
	}

	setTimeout(function(){
		$('.progress .bar').each(function() {
			var me = $(this);
			var perc = me.attr("data-percentage");
			console.log(perc);
			var current_perc = 0;

			var progress = setInterval(function() {
				if (current_perc>=perc) {
					clearInterval(progress);
					setTimeout(redirect,1000);
				} else {
					current_perc +=4;
					me.css('width', (current_perc)+'%');
				}
				
			}, 50);
			
		});

	},300);
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

