function highlightStar(obj,id) {
	removeHighlightt(id);		
	$('.demo-table #tutorial-'+id+' li').each(function(index) {
		$(this).addClass('highlight');
		if(index == $('.demo-table #tutorial-'+id+' li').index(obj)) {
			return false;	
		}
	});
}
function removeHighlight(usr,id,i,stars) {
	removeHighlightt(id);
for(j=1;j<=stars;j++)
{
	$('#'+usr+j).addClass('selected');
}	
}
function removeHighlightt(id) {
	$('.demo-table #tutorial-'+id+' li').removeClass('selected');
	$('.demo-table #tutorial-'+id+' li').removeClass('highlight');
}
function addRating(obj,id,noRating,curr) {
	$('.demo-table #tutorial-'+id+' li').each(function(index) {
		$(this).addClass('selected');
		$('#tutorial-'+id+' #rating').val((index+1));
		if(index == $('.demo-table #tutorial-'+id+' li').index(obj)) {
			return false;	
		}
	});
	
	$.ajax({
	type: "POST",
	url: "functions/add_rating.php",
	data:{id:id, rating:$('#tutorial-'+id+' #rating').val(), noRate:noRating, curr:curr},//'id='+id+'&rating='+$('#tutorial-'+id+' #rating').val()+'&noRate='+noRating+'&curr='+curr,
	cache:false,
	success: function(result){
                if(result == "ok"){
					alert("Your rating is recorded!");
					 $("#vendorlist").load('functions/vendorlist.php');
                }
               
            }
	
	});
	
}
function resetRating(id) {
	if($('#tutorial-'+id+' #rating').val() != 0) {
		$('.demo-table #tutorial-'+id+' li').each(function(index) {
			$(this).addClass('selected');
			if((index+1) == $('#tutorial-'+id+' #rating').val()) {
				return false;	
			}
		});
	}
}