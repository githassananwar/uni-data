package problem5;
import java.util.*;

public class MusicCategory
{
	private Artist ar;
	
	MusicCategory()
	{
		ar=null;
	}

	MusicCategory(Artist a)
	{
		ar=a;
	}

	public Artist getArtist()
	{
		return ar;
	}

	public Track getTrack()
	{
		return ar.getTrack();
	}

	public Album getAlbum()
	{
		return ar.getAlbum();	
	}

}
