/**
 * @file
 * Responsive Background Images JQuery plugin
 *
 * @author: Daniel Honrade http://drupal.org/user/351112
 *
 * Settings:
 * - 
 * - 
 *
 */

(function($){

  // Process responsive_background
  $.fn.responsive_background = function(options){
    var settings = $.extend($.fn.responsive_background.defaults, options);
    var images = this;

    var imageContainerWidth = $(window).width(),
        imageContainerHeight = $(window).height();
    
    var top_position = settings['top'];

    $('body').append('<img id="responsive-background-image-dummy" src="" alt="" />');
    $('#responsive-background-image-wrapper').css({ position: settings['position'], top: top_position.replace(/[^0-9]/g, '') + 'px' });  
        
    // Load on refresh
    loadRWDImages(images, settings, imageContainerWidth, imageContainerHeight);

    // Load on resize
    $(window).resize(function(e){
      imageContainerWidth = $(window).width();
      imageContainerHeight = $(window).height();
      
      loadRWDImages(images, settings, imageContainerWidth, imageContainerHeight);
    });
              
    return this;
  };
  
  $.fn.responsive_background.defaults = {
    position: 'fixed',
    center: 0,
    top: 0,
    height: '',
    bp320: 'none', // 320px or less
    bp480: 'none', // 480px or less
    bp640: 'none', // 640px or less
    bp800: 'none', // 800px or less
    bp960: 'none', // 960px or less
    bp1120: 'none', // 1120px or less
    bp1280: 'none', // 1280px or less
    bp1440: 'none', // 1440px or less
    bp1600: 'none' // 1600px or less and above
  };

  // Loading RWD images
  function loadRWDImages(images, settings, imageContainerWidth, imageContainerHeight){
    var proportion_width  = 0.75;        // width/height
    var proportion_height = 1.333333333; // height/width

    var bgimage_height = Math.round(imageContainerWidth * proportion_width), 
        bgimage_width  = Math.round(imageContainerHeight * proportion_height);
    var wrapper_width, wrapper_height;
    
    if((bgimage_height < imageContainerHeight) && (bgimage_width > imageContainerWidth)) {
      wrapper_width  = bgimage_width;
      wrapper_height = imageContainerHeight;
    }
    else {
      wrapper_width  = imageContainerWidth;
      wrapper_height = bgimage_height;
    }

    if(settings['height'] != '') wrapper_height = settings['height'].replace(/[^0-9]/g, '');
 
          
    //TODO: slideshow support
    $('#responsive-background-image-wrapper').cycle({
      fx: 'fade',
      height: wrapper_height,
      width: wrapper_width,
      fit: 1
      //slideExpr:  $('.slide', this),     // expression for selecting slides (if something other than all children is required)
      //next:  $('.next'),     // element, jQuery object, or jQuery selector string for the element to use as event trigger for next slide      
      //prev:  $('.back'),     // element, jQuery object, or jQuery selector string for the element to use as event trigger for previous slide
      //timeout: 0,
      //nowrap: 1, 
      //containerResize:  0,        // resize container to fit largest slide
      //pause: 0        
    });
  
    images.each(function(){
      if ($(this).hasClass('responsive-background-image')){
        loadImage(this, settings, imageContainerWidth);
        pageBackground(this, settings);
      }
    });
  };

  // Load the image
  function loadImage(image, settings, imageContainerWidth){
    var src = $(image).attr('src'),
        breakpoint1  = src.search(settings['bp320']),
        breakpoint2  = src.search(settings['bp480']),
        breakpoint3  = src.search(settings['bp640']),
        breakpoint4  = src.search(settings['bp800']),
        breakpoint5  = src.search(settings['bp960']),
        breakpoint6 = src.search(settings['bp1120']),
        breakpoint7 = src.search(settings['bp1280']),
        breakpoint8 = src.search(settings['bp1440']),
        breakpoint9 = src.search(settings['bp1600']);
    var imageHeight, imageWidth, currentBreakpoint; 
    

    // check the real image size by loading it again on dummy img  
    $('#responsive-background-image-dummy').attr('src', src).load(function() {
      imageHeight = this.height;
      imageWidth = this.width;
      //console.log(src);      
      // this will only trigger if the image is less than it's container
      if (imageContainerWidth > imageWidth) {
        
        // get the current breakpoint
        if(breakpoint1 != -1) {
          currentBreakpoint = settings['bp320'];
        }
        else if(breakpoint2 != -1) {
          currentBreakpoint = settings['bp480'];
        }    
        else if(breakpoint3 != -1) {
          currentBreakpoint = settings['bp640'];
        }
        else if(breakpoint4 != -1) {
          currentBreakpoint = settings['bp800'];
        }
        else if(breakpoint5 != -1) {
          currentBreakpoint = settings['bp960'];
        }
        else if(breakpoint6 != -1) {
          currentBreakpoint = settings['bp1120'];
        }
        else if(breakpoint6 != -1) {
          currentBreakpoint = settings['bp1280'];
        }
        else if(breakpoint7 != -1) {
          currentBreakpoint = settings['bp1440'];
        }
        else if(breakpoint9 != -1) {
          currentBreakpoint = settings['bp1600'];
        }
        else {
          currentBreakpoint = '';
        }        
        currentBreakpoint = '/' + currentBreakpoint + '/';
        
        // replace the current image with appropriate size
        if((settings['bp320'] != 'none') && (imageContainerWidth <= 320)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp320'] + '/'));
        }
        else if((settings['bp480'] != 'none') && (imageContainerWidth <= 480)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp480'] + '/'));
        }    
        else if((settings['bp640'] != 'none') && (imageContainerWidth <= 640)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp640'] + '/'));
        }
        else if((settings['bp800'] != 'none') && (imageContainerWidth <= 800)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp800'] + '/'));
        }
        else if((settings['bp960'] != 'none') && (imageContainerWidth <= 960)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp960'] + '/'));
        }
        else if((settings['bp1120'] != 'none') && (imageContainerWidth <= 1120)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp1120'] + '/'));
        }
        else if((settings['bp1280'] != 'none') && (imageContainerWidth <= 1280)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp1280'] + '/'));
        }
        else if((settings['bp1440'] != 'none') && (imageContainerWidth <= 1440)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp1440'] + '/'));
        }
        else if((settings['bp1600'] != 'none') && (imageContainerWidth > 1440)) {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp1600'] + '/'));
        }
        else {
          $(image).attr('src', src.replace(currentBreakpoint, '/' + settings['bp320'] + '/'));
        }
      }
    }); 
  };
         
  function pageBackground(image, settings) {
    // initialize vars
    var proportion_width  = 0.75;        // width/height
    var proportion_height = 1.333333333; // height/width

    var screen_width   = $(window).width(), 
        screen_height  = $(window).height(),
        bgimage_height = Math.round(screen_width * proportion_width), 
        bgimage_width  = Math.round(screen_height * proportion_height);
          
        $(image).css({ position: settings['position'] });  
        
        if((settings['center'] == 1) && (bgimage_width > screen_width)) {
         $(image).css({ left: -Math.round((bgimage_width - screen_width)/2) }); 
        } 
    //TODO: center image
    
    //TODO: set minimum
    // set lower limits for page and image sizes
    //if(screen_height < 960) screen_height = 960;
    //if(bgimage_height < 960) bgimage_height = 960;
    //if(screen_width < 960) screen_width = 960;
    //if(bgimage_width < 1280) bgimage_width = 1280;
    
    //TODO: if there's a wrapper option      
    //$('#page-wrapper').width(screen_width).height(screen_height);

    // ensures that the image will occupy the whole page
    if((bgimage_height < screen_height) && (bgimage_width > screen_width)) {
      $(image).css({width: bgimage_width, height: screen_height});
    }
    else {
      $(image).css({width: screen_width, height: bgimage_height});
    }  
  } 


})(jQuery); 
