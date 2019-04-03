$(function() {
    $("pre").text(function(_, t) {return $.trim(this.innerHTML)});
    $("pre").trim();
});