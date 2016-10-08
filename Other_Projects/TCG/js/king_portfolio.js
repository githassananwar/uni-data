(function($) {
	"use strict";
	$(document).ready( function() {
	    $('#king-filters-container .king-portfolio-filter-item').click(function(e) {
	    	$('#king-filters-container .king-portfolio-filter-item-active').removeClass('king-portfolio-filter-item-active');
	    	$(this).addClass('king-portfolio-filter-item-active'); 
	        var target = $(this).attr('data-filter');
	        if( target == '*' ){
		        target = '.king-portfolio-item';
	        }
	        $('#king-grid-container .king-portfolio-item .king-portfolio-item-wrapper').addClass('animated zoomOut');
	        
	        setTimeout(function(){
	        
		        $('#king-grid-container .king-portfolio-item').css({display:'none'});
		        $('#king-grid-container .king-portfolio-item .king-portfolio-item-wrapper').get(0).className = 'king-portfolio-item-wrapper effHidden';
		        $('#king-grid-container '+target).each(function(){
			        $(this).css({display:'block'});
			        $(this).find('.king-portfolio-item-wrapper').get(0).className = 'king-portfolio-item-wrapper effVisible animated bounceIn';
		        });
		        setTimeout(function(){
			         $('#king-grid-container .animated').removeClass('animated').removeClass('bounceIn');
		        },1200);
		    },500); 
	        
	        e.preventDefault();
	    });
		
		
		$('#king-filters-container2 .king-portfolio-filter-item').click(function(e) {
	    	$('#king-filters-container2 .king-portfolio-filter-item-active').removeClass('king-portfolio-filter-item-active');
	    	$(this).addClass('king-portfolio-filter-item-active'); 
	        var target = $(this).attr('data-filter');
	        if( target == '*' ){
		        target = '.king-portfolio2-item';
	        }
	        $('#king-grid-container .king-portfolio2-item .king-portfolio2-item-wrapper').addClass('animated zoomOut');
	        
	        setTimeout(function(){
	        
		        $('#king-grid-container .king-portfolio2-item').css({display:'none'});
		        $('#king-grid-container .king-portfolio2-item .king-portfolio2-item-wrapper').get(0).className = 'king-portfolio2-item-wrapper effHidden';
		        $('#king-grid-container '+target).each(function(){
			        $(this).css({display:'block'});
			        $(this).find('.king-portfolio2-item-wrapper').get(0).className = 'king-portfolio2-item-wrapper effVisible animated bounceIn';
		        });
		        setTimeout(function(){
			         $('#king-grid-container .animated').removeClass('animated').removeClass('bounceIn');
		        },1200);
		    },500); 
	        
	        e.preventDefault();
	    });
	});
})(jQuery);
