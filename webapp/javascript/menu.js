$(function(){
	$item_list = $('#item-list');
	var itemTemplate = $('#item-template').html();
	
	var item = 
	[
		{
			name: "Item1",
			description: "Description1",
			price: "Price1",
		}
	];
	for (var i = 0; i <= item.length-1; i++) {
		var rendered = Mustache.render(itemTemplate,item[i]);
		$item_list.append(rendered);
	};
});