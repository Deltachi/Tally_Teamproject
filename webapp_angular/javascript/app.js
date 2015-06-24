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
			templateUrl: 'ng-templates/menu.html'
		})
}]);

//CONTROLLER
app.controller('loginCtrl', [$scope, function($scope){
	this.loggedIn = false;
	this.switchMode = function(){
		this.loggedIn = !this.loggedIn;
		console.log("test");
	}
}]);

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

