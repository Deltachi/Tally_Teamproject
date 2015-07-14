angular.module('app.directives.menuModal', []) 

	.directive('menuModal', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/menuModal.html',
			controller: function($scope, menuService){
				$scope.editItem = function(){return menuService.editItem;}

				$scope.$watch(function () { return menuService.editItem; }, function (value) {
					$scope.setItem = value;
				});

				$scope.toggleVisible = function(){
					if (menuService.editItem.Visible == 1){
						menuService.editItem.Visible = 0;
					}
					else{
						menuService.editItem.Visible = 1;
					}
				}

				$scope.submitItem = function(){
					menuService.setItemSync($scope.setItem);
				}
				$scope.deleteItem = function(){

				}
			}
		};
	});	