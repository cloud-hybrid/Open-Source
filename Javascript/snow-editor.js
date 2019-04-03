$(document).ready(function () {
  $('#create-article').validator();

  // when the form is submitted
  $('#create-article').on('submit', function (e) {
    sync();
    // if the validator does not prevent form submit
    if (!e.isDefaultPrevented()) {
      var url = "https://vaultcipher.com/assets/scripts/upload.php";

      // POST values in the background the the script URL
      $.ajax({
        type: "POST",
        url: url,
        data: $(this).serialize(),
        success: function (data)
        {
          var messageAlert = 'alert-' + data.type;
          var messageText = data.message;

          // Bootstrap alert box HTML
          var alertBox = '<div class="alert ' + messageAlert + ' alert-dismissable"><button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>' + messageText + '</div>';

          if (messageAlert && messageText) {
              // inject the alert to .messages
              $('#create-article').find('.messages').html(alertBox);
            }
          }
        });
        return false;
    }
  })
});
