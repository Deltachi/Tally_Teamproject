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
					refreshMenu();
					$('#menuModal').modal('hide');
				}
				$scope.submitItem = function(){
					menuService.updateItemSync($scope.setItem);
					refreshMenu();
					$('#menuModal').modal('hide');
				}
				$scope.deleteItem = function(){
					menuService.deleteItemSync($scope.setItem);
					refreshMenu();
					$('#menuModal').modal('hide');
				}


				function refreshMenu(){
					var postData = {};
					postData['request'] = "Drinks";
					var responseDrinks;
					var responseSweets;

					//load Drinks from server
					menuService.getMenuSync(postData).then(
						function(data){
							responseDrinks = jQuery.parseJSON(data);
							// console.log(data);
							// console.log(responseDrinks);
							menuService.menu.drinks= responseDrinks;
							
						});
					postData['request'] = "Sweets";
					//Load Sweets from server
					menuService.getMenuSync(postData).then(
						function(data){
							responseSweets = jQuery.parseJSON(data);
							// console.log(data);
							// console.log(responseSweets);
							menuService.menu.sweets = responseSweets;
						});
				}

			}
		};
	});	