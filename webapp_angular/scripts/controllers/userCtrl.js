//User-Controller der Daten fetcht und das Dropdownmenü 
//und alle weiteren user-relevanten Seiten aktuell hält,
//btw. alle relevanten Funktionen zur Aktualisierung bereithält
angular.module('app.controllers.userCtrl', []) 

	.controller('userCtrl', ['$scope', 'userDataService', function($scope, userDataService){
		$scope.loading = true;
		if (userDataService.getUserData() != null) {
			$scope.loading = false;
		}
		var data = userDataService.getUserData();
		$scope.barColor = function(){
			var color;
			var balance = data.balance;
			if (balance < 0){
				color = "danger";
			}
			else{
				if(balance <= 10.0){
					color = "warning";
				}
				else{
					color = "success";
				}
			}
			return color;
		};
		$scope.delete = function(index, Message_ID){
			console.log("Gonna delete this msg: " + userDataService.getUserData().messages[index].Message + " -> msg_id = " + Message_ID);
			userDataService.getUserData().messages.splice(index, 1);
		};

		$scope.$watch(function () { return userDataService.getUserData(); }, function (value) {
			$scope.userData = value;
		});
	}])