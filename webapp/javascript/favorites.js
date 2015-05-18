$(function(){
	
	$('.deleteBtn').on('click', function(){
		$button = $(this);
		
		$button.parent().parent().fadeOut(300);
	});	
	
});