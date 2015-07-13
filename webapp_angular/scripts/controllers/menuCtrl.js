angular.module('app.controllers.menuCtrl', []) 	
	.controller('menuCtrl',['$scope','$http','menuService', function($scope,$http,menuService){
		var loading = true;
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
				
				$scope.loading = false;
			});
		postData['request'] = "Sweets";
		//Load Sweets from server
		menuService.getMenuSync(postData).then(
			function(data){
				responseSweets = jQuery.parseJSON(data);
				// console.log(data);
				// console.log(responseSweets);
				menuService.menu.sweets = responseSweets;

				$scope.loading = false;
			});


		
		$scope.drinks = menuService.menu.drinks;
		$scope.sweets = menuService.menu.sweets;

		menuService.editItem = {"Nick":"Item placeholder"};
		console.log("Initialize editItem with: "+menuService.editItem.Nick);
		$scope.setNewEditItem = function(item_id){
			console.log("Change item with id: "+item_id);
			postData['request'] = item_id;
			menuService.getItemAsync(postData).then(
								function(data){
									// console.log("Response data:");
									// console.log(jQuery.parseJSON(data)[0]);
									menuService.editItem =  jQuery.parseJSON(data)[0];
								});
			console.log(menuService.editItem);
		}
		// $scope.list = null;
		// $http.get('/json/menuContent.json')
		// .success(function(res) {
		// 	$scope.list = res;
		// 	$scope.drinks = $scope.list.drinks;
		// 	$scope.sweets = $scope.list.sweets;
		// 	console.log($scope.list.drinks);
		// 	console.log($scope.list.sweets);
		// })
		// .error(function(res,status,error,config){
		// 	$scope.list = [{name:"Error",description:"Could not load json data"}];
		// });
	}]);