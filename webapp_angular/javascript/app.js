// $(function(){
	var app = angular.module('app',[]);
	app.directive('myNavbar', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/navbar.html'
		};
	});	
	app.directive('welcome', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/title.html'
		};
	});
	
	app.controller('gemStore', ['', function(){
		
	}])
	
// });
