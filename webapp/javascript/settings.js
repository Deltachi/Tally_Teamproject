$(function(){
	$('button.noedit').on('click',function(){
		$button = $(this);
		data = $button.attr('data-panel');
		console.log('btn (now editing) in '+data+' panel got clicked');
		$element = $('#'+data);
		$element.removeClass('noedit');
		$element.addClass('edit');
	});
	$('button.edit').on('click',function(){
		$button = $(this);
		data = $button.attr('data-panel');
		console.log('btn (exit editing) in '+data+' panel got clicked');
		console.log('button was a success btn? -> '+ $button.hasClass('btn-success'));
		$element = $('#'+data);
		if ($button.hasClass('btn-success') &&  $element.find('input').val() ) {
			
			console.log("Change text to: "+$element.find('input').val());
			$element.find('span').first().html($element.find('input').val());
		}
		$element.removeClass('edit');
		$element.addClass('noedit');
	});

});