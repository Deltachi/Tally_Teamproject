var app = angular.module('app',[
	'ui.router',
	'ui.bootstrap',
	'app.directives.myNavbar',
	'app.directives.myFooter',
	'app.directives.login',
	'app.directives.menuModal',

	'app.controllers.userCtrl',
	'app.controllers.menuCtrl',
	'app.controllers.loginCtrl',
	'app.controllers.loginModalCtrl',
	'app.controllers.updatedCtrl',
	'app.controllers.logoutCtrl',
	'app.controllers.lbCtrl',

	'app.services.myService',
	'app.services.userDataService',
	'app.services.menuService',
	'app.services.loginService',
	'app.services.loginModalService'

	]);

//UI-ROUTER
app.config(['$urlRouterProvider','$stateProvider',function($urlRouterProvider, $stateProvider) {
	$urlRouterProvider.otherwise('/');
	$stateProvider
		.state('/', {
			url: '/',
			templateUrl: 'ng-templates/home.html',
			data: {
				requireLogin: false 
			}
		})
		.state('home', {
			url: '/home',
			templateUrl: 'ng-templates/home.html',
			data: {
				requireLogin: false 
			}
		})
		.state('menu', {
			url: '/menu',
			templateUrl: 'ng-templates/menu.html',
			data: {
				requireLogin: false 
			}
		})
		.state('app' ,{
			abstract: true,
			data: {
				requireLogin: true //this property will apply to all children of 'app'
			}
		})
		.state('notifications', {
			url: '/notifications',
			templateUrl: 'ng-templates/notifications.html',
			data: {
				requireLogin: true 
			}
		})
		.state('leaderboard', {
			url: '/leaderboard',
			templateUrl: 'ng-templates/leaderboard.html',
			data: {
				requireLogin: true 
			}
		})
		.state('settings', {
			url: '/settings',
			templateUrl: 'ng-templates/settings.html',
			data: {
				requireLogin: true 
			}
		})
		.state('favorites', {
			url: '/favorites',
			templateUrl: 'ng-templates/favorites.html',
			data: {
				requireLogin: true 
			}
		})
		.state('logout', {
			url: '/logout',
			templateUrl: 'ng-templates/logout.html',
			controller: 'logoutCtrl',
			data: {
				requireLogin: true 
			}
		})
}]);

app.filter('positive', function() {
        return function(input) {
            if (!input) {
                return 0;
            }

            return Math.abs(input);
        };
    })

app.run(['$rootScope','$location', '$state','loginService', 'loginModalService', function($rootScope, $location, $state, loginService, loginModalService){
	
	$rootScope.$on('$stateChangeStart', function(event, toState, toParams){
		var requireLogin = toState.data.requireLogin;
		console.log("checking access..");
		console.log("login required: "+ requireLogin);

		if (requireLogin && loginService.getUser() == null){
			console.log("WARNING, unauthorized access!")
			event.preventDefault();
			// $('#myModal').modal('show');
			loginModalService()
				.then(function(){
					// return $state.go(toState.name, toParams);
					return $state.go('home');
				})
				.catch(function(){
					return $state.go('home');
				})
			// $state.go('home');

		}
		if (requireLogin && loginService.getUser() != null){
			//load user data 
		}
	});
}]);



