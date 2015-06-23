var app = angular.module('app',['ui.router']);

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

app.directive('myNavbar', function(){
	return {
		restrict: 'E',
		templateUrl: '/ng-templates/navbar.html'
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
