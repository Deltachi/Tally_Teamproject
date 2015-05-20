$(function(){
	$bar = $('.progress .progress-bar');
	$balance = $('#balance');

	$('#btn-good').on('click', good);
	$('#btn-neutral').on('click', neutral);
	$('#btn-bad').on('click', bad);
	
	function good(){
		$balance.html("55&euro;");
		$balance.removeClass();
		$balance.addClass('text-success');

		$bar.attr("aria-valuenow",'55');
		$bar.addClass('progress-bar-success');
		$bar.removeClass('progress-bar-warning');
		$bar.removeClass('progress-bar-danger');
		$bar.css({
			width: '55%',
			display: 'block', 
			float: 'left'
		});
	}
	function neutral(){
		$balance.html("10&euro;");
		$balance.removeClass();
		$balance.addClass('text-warning');

		$bar.attr("aria-valuenow",'10');
		$bar.removeClass('progress-bar-success');
		$bar.addClass('progress-bar-warning');
		$bar.removeClass('progress-bar-danger');
		$bar.css({
			width: '10%',
			display: 'block', 
			float: 'left'
		});
	}
	function bad(){
		$balance.html("-34&euro;");
		$balance.removeClass();
		$balance.addClass('text-danger');

		$bar.attr("aria-valuenow",'34');
		$bar.removeClass('progress-bar-success');
		$bar.removeClass('progress-bar-warning');
		$bar.addClass('progress-bar-danger');
		$bar.css({
			width: '34%',
			display: 'block', 
			float: 'right'
		});
	}
		
});