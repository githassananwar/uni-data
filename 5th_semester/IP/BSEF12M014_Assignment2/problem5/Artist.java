package problem5;
import java.util.*;

public class Artist
{
	private String artistName;
	private Album alb;
	private Track tr;
	
	Artist()
	{
		artistName=null;
		alb=null;
		tr=null;
	}

	Artist(String name, Album al, Track t)
	{
		this.artistName=name;
		this.alb=new Album(al.getAlbumId(), al.getTitle(), al.getTrack());
		this.tr=new Track(t.getTrackName(), t.getTrackId());
	}

	public Track getTrack()
	{
		return tr;
	}

	public Album getAlbum()
	{
		return alb;
	}

	public String getArtistName()
	{
		return artistName;
	}


}
