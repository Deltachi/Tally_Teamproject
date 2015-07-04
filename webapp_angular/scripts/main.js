
// Main .js file for main functions

$(function(){
	$('[data-toggle="tooltip"]').tooltip();
	

	var isMobile = (/android|webos|iphone|ipad|ipod|blackberry|iemobile|opera mini/i.test(navigator.userAgent.toLowerCase()));
	if(isMobile) {
		$('#footer').addClass('mobileFooter');
	} 
});
