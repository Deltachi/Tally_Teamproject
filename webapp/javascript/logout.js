$(document).ready(function() {
    function redirect(){
		window.location.href = 'index.html';
	}

    setTimeout(function(){

		$('.progress .bar').each(function() {
			var me = $(this);
			var perc = me.attr("data-percentage");
			console.log(perc);
			var current_perc = 0;

			var progress = setInterval(function() {
				if (current_perc>=perc) {
					clearInterval(progress);
					setTimeout(redirect,1000);
				} else {
					current_perc +=4;
					me.css('width', (current_perc)+'%');
				}

				// me.text((current_perc)+'%');

			}, 50);
			
		});

	},300);
	
});