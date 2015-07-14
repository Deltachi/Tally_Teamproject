angular.module('app.controllers.loginModalCtrl', []) 	
	.controller('loginModalCtrl', ['$scope','loginService','userDataService', function($scope,loginService,userDataService){
		this.cancel = $scope.$dismiss;
		$scope.ok = function () {
			$modalInstance.close($scope.selected.item);
		};

		$scope.cancel = function () {
			$modalInstance.dismiss('cancel');
		};
		this.submit = function(username, password){
			//UsersApi.login(username, password).then(function (user){$scope.$close(user);})

		}
	}]);