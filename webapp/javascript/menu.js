$(function(){
	$item_list = $('#item-list');
	var itemTemplate = $('#item-template').html();
	$drink_list = $('#drink-list');
	var drinkTemplate = $('#drink-template').html();
	
	for (var i = 0; i <= menu.items.length-1; i++) {
		var rendered = Mustache.render(itemTemplate,menu.items[i]);
		$item_list.append(rendered);
	};
	for (var j = 0; j <= menu.drinks.length-1; j++) {
		var rendered = Mustache.render(drinkTemplate,menu.drinks[j]);
		$drink_list.append(rendered);
	};
});