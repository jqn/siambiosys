/**
 * @file
 * Javascript for entity background image.
 */

(function ($) {
  Drupal.behaviors.entityBackgroundImage = {
    attach: function (context) {
      var images = Drupal.settings.entity_background_image;
      $.each(images, function (selector, value) {
        $(selector).css('background-image', 'url(' + value.image + ')');
        // Add class.
        $(selector).addClass('eb-image');
        // Add style class.
        if (value.style) {
          $(selector).addClass(value.style);
        }
      });
    }
  };

})(jQuery);
