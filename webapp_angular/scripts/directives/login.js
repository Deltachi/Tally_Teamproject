angular.module('app.directives.login', []) 

	.directive('login', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/login.html',
		};
	});	