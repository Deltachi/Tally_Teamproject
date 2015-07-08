
// Main .js file for main functions

$(function(){
	$(window).load(function(){
		$('[data-toggle="tooltip"]').tooltip();
	});


	// console.log("Activate tooltips");

	var isMobile = (/android|webos|iphone|ipad|ipod|blackberry|iemobile|opera mini/i.test(navigator.userAgent.toLowerCase()));
	if(isMobile) {
		$('#footer').addClass('mobileFooter');
	} 
});
