angular.module('app.controllers.menuCtrl', []) 	
	.controller('menuCtrl',['$scope','$http','menuService','userDataService', function($scope,$http,menuService,userDataService){
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


		// menuService.editItem = {"Nick":"Item placeholder"};
		// console.log("Initialize editItem with: "+menuService.editItem.Nick);
		$scope.addItem = function(){
			menuService.editItem = {'Nick': "New Item", 'Typ':"0", "Type_Group": "Drinks", "Visible": "1"};
			menuService.editMode = 'insert';
		}

		$scope.setNewEditItem = function(item_id){
			menuService.editMode = 'update';
			console.log("Change item with id: "+item_id);
			postData['request'] = item_id;
			menuService.getItemSync(postData).then(
								function(data){
									// console.log("Response data:");
									// console.log(jQuery.parseJSON(data)[0]);
									menuService.editItem =  jQuery.parseJSON(data)[0];
								});
			console.log(menuService.editItem);
		}

		// $scope.tooltips = function(){
		setTimeout(function(){
			console.log("Enable tooltips");
			$('[data-toggle="tooltip"]').tooltip();
		},300);
		// } 

		$scope.$watch(function () { return userDataService.getUserData(); }, function (value) {
			$scope.userData = value;
		});
		$scope.$watch(function () { return menuService.menu.drinks; }, function (value) {
			$scope.drinks = value;
		});
		$scope.$watch(function () { return menuService.menu.sweets; }, function (value) {
			$scope.sweets = value;
		});
		
	}]);