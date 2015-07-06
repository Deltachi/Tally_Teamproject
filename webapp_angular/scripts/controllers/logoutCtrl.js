angular.module('app.controllers.logoutCtrl', []) 	
	.controller('logoutCtrl', ['$scope','$location', '$state', 'myService', function($scope,$location,$state,myService){
		function redirect(){
	  //   	if ($.cookie('session') == null){
			// 	console.log('NO COOKIE THERE >.>')
			// }
			// else{
				// $.removeCookie('session');
				myService.sharedObject.data = false;
				console.log('myService variable: '+myService.sharedObject.data);

				$state.go('home')
			// }
		}

		setTimeout(function(){
			$('.progress .bar').each(function() {
				var me = $(this);
				var perc = me.attr("data-percentage");
				console.log(perc);
				var current_perc = 0;

				var progress = setInterval(function() {
					if (current_perc>=perc) {
						clearInterval(progress);
						setTimeout(redirect,1000);
					} else {
						current_perc +=4;
						me.css('width', (current_perc)+'%');
					}
					
				}, 50);
				
			});

		},300);
	}])