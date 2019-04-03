jQuery(document).ready(function($) {

    $(window).scroll(function () {
      var height = $(window).height();
      var scroll = $(window).scrollTop();
      if (scroll) {
        $(".header-hide").addClass("scroll-header");
      } else {
        $(".header-hide").removeClass("scroll-header");
      }
    })
});
