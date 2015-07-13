angular.module('app.controllers.loginModalCtrl', []) 	
	.controller('loginModalCtrl', ['$scope','loginService','userDataService', function($scope,loginService,userDataService){
		this.cancel = $scope.$dismiss;

		this.submit = function(username, password){
			//UsersApi.login(username, password).then(function (user){$scope.$close(user);})
			
		}
	}]);