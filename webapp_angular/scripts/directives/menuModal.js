angular.module('app.directives.menuModal', []) 

	.directive('menuModal', function(){
		return {
			restrict: 'E',
			templateUrl: '/ng-templates/menuModal.html',
			controller: function($scope, menuService){
				$scope.editItem = function(){return menuService.editItem;}
				$scope.editMode = function(){return menuService.editMode;}

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
				$scope.createItem = function(){
					menuService.insertItemSync($scope.setItem);
				}
				$scope.submitItem = function(){
					menuService.updateItemSync($scope.setItem);
				}
				$scope.deleteItem = function(){

				}
			}
		};
	});	