angular.module('app.controllers.updatedCtrl', []) 	
	
	.controller('updatedCtrl', ['$scope','$http', function($scope,$http){
		$scope.date = null;
		$scope.time = null;

		$scope.data = null;
		$http.get('/json/updated.json')
		.success(function(res) {
			$scope.data = res;
			$scope.date = $scope.data.date;
			$scope.time = $scope.data.time;
			console.log($scope.data.date);
			console.log($scope.data.time);
		})
		.error(function(res,status,error,config){
			$scope.date = "Error";
			$scope.time = "Error";
		});
	}])