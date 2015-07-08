angular.module('app.directives.menuModal', []) 

	.directive('menuModal', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/menuModal.html',
			controller: function($scope, menuService){
				$scope.editItem = function(){return menuService.editItem;}
			}
		};
	});	