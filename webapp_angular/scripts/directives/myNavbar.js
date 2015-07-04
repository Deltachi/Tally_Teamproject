angular.module('app.directives.myNavbar', []) 

	.directive('myNavbar', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/navbar.html',
			controller: 'loginCtrl'
		};
	});	