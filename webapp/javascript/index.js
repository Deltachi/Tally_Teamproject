$(function(){
	$('#alert-not-available').hide()
	$('#btn_hide').on('click', function(){
		$('#panel_sweets').slideUp(1000);
	});
	$('#btn_show').on('click', function(){
		$('#panel_sweets').slideDown(1000);
	});
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
	$('.not-available').on('click',showAlert);

	function showAlert(){
		$('#alert-not-available').slideDown(500).delay(2000).slideUp(500);
	}
});
