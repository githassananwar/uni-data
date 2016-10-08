
(function($){
  // Simple wrapper around jQuery animate to simplify animating progress from your app
  // Inputs: Progress as a percent, Callback
  // TODO: Add options and jQuery UI support.
  $.fn.animateProgress = function(progress, callback) {    
    return this.each(function() {
      $(this).animate({
        width: progress+'%'
      }, {
        duration: 2000, 
        
        // swing or linear
        easing: 'swing',

        // this gets called every step of the animation, and updates the label
        step: function( progress ){
          var labelEl = $('.ui-label', this),
              valueEl = $('.value', labelEl);
          
          if (Math.ceil(progress) < 20 && $('.ui-label', this).is(":visible")) {
            labelEl.hide();
          }else{
            if (labelEl.is(":hidden")) {
              labelEl.fadeIn();
            };
          }
          
          if (Math.ceil(progress) == 100) {
            labelEl.text('Done');
            setTimeout(function() {
              labelEl.fadeOut();
            }, 1000);
          }else{
            valueEl.text(Math.ceil(progress) + '%');
          }
        },
        complete: function(scope, i, elem) {
          if (callback) {
            callback.call(this, i, elem );
          };
        }
      });
    });
  };
})(jQuery);  


jQuery(document).ready( function( $ ){

  // Hide the label at start
  $('.king-progress-bar .ui-progress .ui-label').hide();
  // Set initial value
  $('.king-progress-bar .ui-progress').css('width', '7%');

  // Simulate some progress
  $('.king-progress-bar .ui-progress').each(function(){
  		
  		this.per = $(this).find('.value').html().replace('%','');
  		
  		$( this ).viewportChecker({
			callbackFunction: function( elm ){
				elm.get(0).done = true;
				
				elm.animateProgress(elm.get(0).per, function() {
	  	
					$(this).animateProgress(this.per-10, function() {
						  $('.king-progress-bar .ui-progress').each(function(){
					    	 $(this).animateProgress(this.per);
						  });
					});
					
				});
									
			},
			classToAdd: ''
		});
	  
  });
  
  
});








