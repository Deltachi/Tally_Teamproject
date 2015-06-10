var not_available_html = ''+
'<div id="alert-not-available"class="alert alert-danger important-alert" role="alert">'+
	'This function is currently <strong>not available! :(</strong>'+
'</div>';

$(function(){	
	var deviceAgent = navigator.userAgent.toLowerCase();

	$("body").prepend(not_available_html);
	$('#alert-not-available').hide()
	$('.not-available').on('click',showAlert);

	function showAlert(){
		$('#alert-not-available').slideDown(500).delay(2500).slideUp(500);
	}
	
  
	if (deviceAgent.match(/(iphone|ipod|ipad)/)) {
		$('html').addClass('ios');
		$('html').addClass('mobile');
		$('.introBox').hide();
	}

	if (deviceAgent.match(/android/)) {
		$('html').addClass('android');
		$('html').addClass('mobile');
		$('.introBox').hide();
	}

	if (deviceAgent.match(/blackberry/)) {
		$('html').addClass('blackberry');
		$('html').addClass('mobile');
		$('.introBox').hide();
	}

	if (deviceAgent.match(/(symbianos|^sonyericsson|^nokia|^samsung|^lg)/)) {
		$('html').addClass('mobile');
		$('.introBox').hide();
	}

	$.cookie.raw = true;

	if ($.cookie('session') == null){
		console.log('NO COOKIE THERE >.>');
		$('.loggedOut').show();
		$('.loggedIn').hide();
	}
	else{
		console.log('Welcome back!');
		$('.loggedOut').hide();
		$('.loggedIn').show();
	}

	$('.register').on('click', function(){
		if ($.cookie('session') == null){
			$.cookie('session', 'validated', {expires: 1});
			console.log('successfully registered this session.')
			console.log('Cookie: '+$.cookie('session'));
		}
		else{
			console.log('already registered this session!!')
		}
	});
});
