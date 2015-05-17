var not_available_html = '<div id="alert-not-available"class="alert alert-danger important-alert" role="alert">Diese Funktion ist leider noch <strong>nicht verf&uuml;gbar! :(</strong></div>';

$(function(){	
	$("body").prepend(not_available_html);
	$('#alert-not-available').hide()
	$('.not-available').on('click',showAlert);

	function showAlert(){
		$('#alert-not-available').slideDown(500).delay(2500).slideUp(500);
	}
});
