package problem5;
import java.util.*;

public class MusicItems 
{
	private MusicCategory mc;
	
	MusicItems()
	{
		mc=null;
	}

	MusicItems(MusicCategory m)
	{
		mc=new MusicCategory(m.getArtist());
	}
	
	public MusicCategory getMusicCategory()
	{
		return mc;
	}

	public Album getAlbum()
	{
		return mc.getAlbum();
	}

	public Artist getArtist()
	{
		return mc.getArtist();
	}

	public Track getTrack()
	{
		return mc.getTrack();
	}


}
