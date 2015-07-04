angular.module('app.controllers.menuCtrl', []) 	
	.controller('menuCtrl',['$scope','$http', function($scope,$http){
		
		
		$scope.drinks = null;
		$scope.sweets = null;

		$scope.list = null;
		$http.get('/json/menuContent.json')
		.success(function(res) {
			$scope.list = res;
			$scope.drinks = $scope.list.drinks;
			$scope.sweets = $scope.list.sweets;
			console.log($scope.list.drinks);
			console.log($scope.list.sweets);
		})
		.error(function(res,status,error,config){
			$scope.list = [{name:"Error",description:"Could not load json data"}];
		});
	}]);