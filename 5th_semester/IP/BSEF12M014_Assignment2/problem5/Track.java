package problem5;
import java.util.*;

public class Track 
{
	private String trackName;
	private int trackId;
	private String lyrics;
	
	Track()
	{
		trackName=null;
		trackId=0;
		lyrics=null;
		
	}

	Track(String name, int id)
	{
		this.trackName=name;
		this.trackId=id;
		this.lyrics=null;
	}
	
	Track(String name, int id, String lyr)
	{
		this.trackName=name;
		this.trackId=id;
		this.lyrics=lyr;
	}

	public void playTrack()
	{	
	}

	public void stopTrack()
	{	
	}

	public void pauseTrack()
	{	
	}

	public void downloadTrack()
	{	
	}

	public String getTrackName() 
	{
		return trackName;
	}
	
	public int getTrackId() 
	{
		return trackId;
	}
	

}
