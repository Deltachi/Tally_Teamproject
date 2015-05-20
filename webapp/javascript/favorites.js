$(function(){
	$favos = $('#favorites');
	$addBtn = $('#addBtn');
	$itemList = $('#itemList');
	var list_index = 1;

	$addBtn.on('click',function(){
		var value = $itemList.val();
		addItem(value);
	});
	function addItem(name){
		var count =  $( "tr" ).length;
		var htmlString = '<tr><th class="index" scope="row">'+count+'</th><td>'+name+'</td><td><button class="btn btn-sm btn-danger deleteBtn"><span class="glyphicon glyphicon-trash"></span></button></td></tr>';
		$('#favorites > tbody:last').append(htmlString);
		console.log('Added '+name+' at number '+count);
		
	}
	$favos.delegate('.deleteBtn','click', function(){
		console.log('Delete-button clicked');
		$button = $(this);
		$element = $button.closest('tr');
		$list = $element.parent();
		
		list_index = 1;
		$element.fadeOut(500,function(){
			$(this).remove();
			$('.index').each(function() {
				var before = $(this).html();
				var now = list_index;
				$(this).html(now);
				var item = $(this).next().html();
				console.log(item+" -> before:"+before+" now:"+now);
				list_index++;
			});
		});


	});	
	
});