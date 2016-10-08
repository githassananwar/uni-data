package problem5;
import java.util.*;

public class PopMusic extends MusicCategory 
{
	private String band;
	
	PopMusic()
	{
		band=null;	
	}
	PopMusic(String b)
	{
		band=b;
	}
	public String getBand()	
	{
		return band;
	}
	public Artist getArtist()
	{
		return super.getArtist();
	}


}
