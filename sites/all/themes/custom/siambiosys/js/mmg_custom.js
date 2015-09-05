jQuery(document).ready(function($) {
  // Wrapper for YouTube videos.
  $('iframe').each(function(index, value) {
    if ($(this).attr('src')) {
      var src = $(this).attr('src');
      var yt = "youtube.com";
      var vm = "vimeo.com";
      if ((src.indexOf(yt) != -1) || (src.indexOf(vm) != -1)) {
        $(this).wrap("<div class='mmg-video'></div>");
      }
    }
  });
  $('#block-views-game-instructions-block .view-content a').each(function() {
    var link = $(this).attr('href');
    var url = window.location.pathname + location.search;
    if (link.indexOf(url) != -1) {
      $(this).addClass('active-page');
    }
  });
});