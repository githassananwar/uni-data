package problem5;
import java.util.*;

public class FilmMusic extends MusicCategory
{
	private String band;

	FilmMusic()
	{
		band=null;	
	}

	FilmMusic(String b)
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
