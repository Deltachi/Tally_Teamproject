$(function(){
	$('#alert-not-available').hide()
	
	$('#nav').affix({
	      offset: {
	        top: $('header').height()
	      }
	});
	$('#btn_testLogin').on('click', function(){
		$('#navLogin').html($('#username').val());
		$('#navLogin').attr("href", "users.html");
		$('#navLogin').attr("class", " ");
		$('#menuLogin').attr("class", "dropdown");
		$('#navLogin').attr("data-toggle", " ");
		$('#panel_login').hide();
	});	
	
});
