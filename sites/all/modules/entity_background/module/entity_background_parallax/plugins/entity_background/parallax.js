
/**
 * @file
 * Javascript for entity background parallax.
 */

(function($) {
  Drupal.behaviors.entityBackgroundParallax = {
    attach: function(context) {
      var images = Drupal.settings.entity_background_parallax;
      $.each(images, function(selector, options) {
        $(selector).parallax(options);
        // Add class.
        $(selector).addClass('eb-parallax');
      });
    }
  };

})(jQuery);