angular.module('app.controllers.lbCtrl', []) 	
	.controller('lbCtrl', ['$scope','$http', function($scope,$http){
		$scope.caffein = null;
		$scope.sugar = null;

		$scope.data = null;
		$http.get('/json/leaderboard.json')
		.success(function(res) {
			$scope.data = res;
			$scope.caffein = $scope.data.caffein;
			$scope.sugar = $scope.data.sugar;
			console.log($scope.data.caffein);
			console.log($scope.data.sugar);
		})
		.error(function(res,status,error,config){
			$scope.date = "Error";
			$scope.time = "Error";
		});
	}])