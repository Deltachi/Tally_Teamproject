angular.module('app.services.loginModalService', []) 
	

	.factory("loginModalService", function($modal, $rootScope){
		function assignCurrentUser (user){
			$rootScope.currentUser = user;
			return user;
		}
		return function(){
			var instance = $modal.open({
				templateUrl: '/ng-templates/denied.html',
				controller: 'loginModalCtrl',
				controllerAs: 'loginModalCtrl'
			})
			return instance.result.then(assignCurrentUser);
		};
	});