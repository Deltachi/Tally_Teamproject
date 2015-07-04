angular.module('app.directives.myFooter', []) 

	.directive('myFooter', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/footer.html'
		};
	});	
