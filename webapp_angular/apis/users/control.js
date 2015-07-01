$(function(){
	$("#idForm").submit(function() {

    var service_msg = "getMessages.php"; // the script where you handle the form input.
    var service_userData = "getUserData.php";
    var url;

    var service = $('#service').val();
    

    $.ajax({
           type: "POST",
           url: service,
           data: $("#idForm").serialize(), // serializes the form's elements.
           success: function(data)
           {
               // alert(data); // show response from the php script.
               $('#response_panel').removeClass('panel-default, panel-danger').addClass('panel-success');
               $('#response').html(data);
           },
           error: function(jqXHR, status, errors){
              $('#response_panel').removeClass('panel-default, panel-success').addClass('panel-danger');
              $('#response').html("Error loading data. -> "+status);
           }
         });

    return false; // avoid to execute the actual submit of the form.
  });
});