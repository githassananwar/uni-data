package problem5;
import java.util.*;

public class Album  
{
	private int albumId;
	private String albumTitle;
	private int trackNumber;
	private int year;
	private Track tr;

	Album()
	{
		albumId=0;
		albumTitle=null;
		trackNumber=0;
		year=0;
		tr=null;
	}

	Album(int albumId, String title, Track t)
	{
		this.albumId=albumId;
		this.albumTitle=title;
		this.trackNumber=0;
		this.year=0;
		this.tr=new Track(t.getTrackName(), t.getTrackId());

	}

	Album(int albumId, String title, int trackNum, int y, Track t)
	{
		this.albumId=albumId;
		this.albumTitle=title;
		this.trackNumber=trackNum;
		this.year=y;
		this.tr=new Track(t.getTrackName(), t.getTrackId());

	}

	public Track getTrack()
	{
		return tr;
	}	

	public void viewTrack() 
	{
		System.out.println("TRACK INFO:-");
		System.out.println("Track ID: "+tr.getTrackId());
		System.out.println("Track Name: "+tr.getTrackName());
	}

	public void viewTrackNumber() 
	{
		System.out.println("Track Number: "+trackNumber);
	}

	public void viewYear()
	{
		System.out.println("Year: "+year);
	}

	public int getAlbumId()
	{
		return albumId;
	}

	public String getTitle()
	{
		return albumTitle;
	}


}
