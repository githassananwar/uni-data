package problem5;
import java.util.*;

public class ClassicMusic extends MusicCategory
{
	private String band;
	ClassicMusic()
	{
		band=null;	
	}

	ClassicMusic(String b)
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
