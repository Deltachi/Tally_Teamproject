var app = angular.module('app',[
	'ui.router',
	'app.directives.myNavbar',
	'app.directives.myFooter',
	'app.directives.login',
	'app.directives.menuModal',
	'app.controllers.userCtrl',
	'app.controllers.menuCtrl',
	'app.controllers.loginCtrl',
	'app.controllers.updatedCtrl',
	'app.controllers.logoutCtrl',
	'app.controllers.lbCtrl',
	'app.services.myService',
	'app.services.userDataService',
	'app.services.menuService'
	]);

//UI-ROUTER
app.config(['$urlRouterProvider','$stateProvider',function($urlRouterProvider, $stateProvider) {
	$urlRouterProvider.otherwise('/');
	$stateProvider
		.state('/', {
			url: '/',
			templateUrl: 'ng-templates/home.html'
		})
		.state('home', {
			url: '/home',
			templateUrl: 'ng-templates/home.html'
		})
		.state('menu', {
			url: '/menu',
			templateUrl: 'ng-templates/menu.html'
			// controller: 'menuCtrl'
		})
		.state('notifications', {
			url: '/notifications',
			templateUrl: 'ng-templates/notifications.html'
		})
		.state('leaderboard', {
			url: '/leaderboard',
			templateUrl: 'ng-templates/leaderboard.html'
		})
		.state('settings', {
			url: '/settings',
			templateUrl: 'ng-templates/settings.html'
		})
		.state('favorites', {
			url: '/favorites',
			templateUrl: 'ng-templates/favorites.html'
		})
		.state('logout', {
			url: '/logout',
			templateUrl: 'ng-templates/logout.html',
			controller: 'logoutCtrl'
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
