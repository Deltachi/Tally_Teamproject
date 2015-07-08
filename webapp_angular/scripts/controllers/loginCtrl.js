angular.module('app.controllers.loginCtrl', []) 	
	.controller('loginCtrl', ['$scope','myService', function($scope,myService){
		$scope.loggedIn = myService.sharedObject.data;
		$scope.switchMode = function(){
			myService.sharedObject.data = !myService.sharedObject.data;
			$scope.loggedIn = myService.sharedObject.data;
			console.log("Client logged in: "+$scope.loggedIn);
			console.log("myService variable: "+myService.sharedObject.data);

		}
		$scope.getLogin = function(){
			return myService.sharedObject.data;
		}
		$scope.tooltips = function(){
			setTimeout(function(){
				$('[data-toggle="tooltip"]').tooltip();
			},300);
		} 
	}]);
