$(function(){	
	$('.not-available').on('click',showAlert);

	function showAlert(){
		$('#alert-not-available').slideDown(500).delay(2500).slideUp(500);
	}
});
