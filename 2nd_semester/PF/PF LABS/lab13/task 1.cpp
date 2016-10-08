#include<iostream>

using namespace std;

struct TempScale
{
	double farenheit;
	double centigrade;

};

struct Reading
{
	int windSpeed;
	double humidity;
	TempScale temperature;

};

void showReading(Reading);
void findReading(Reading&);
Reading getReading();
void recordReading(Reading *);


int main ()
{
   
	Reading read;
	read.windSpeed=37;
	read.humidity=32;
	read.temperature.farenheit=32;
	read.temperature.centigrade=0;

	showReading(read);
	cout<<endl;

	findReading(read);
	cout<<endl;

	read=getReading();

	cout<<"Wind speed(mph): "<<read.windSpeed<<endl;
	cout<<"Humidity(%): "<<read.humidity<<endl;
	cout<<"Temperature in F: "<<read.temperature.farenheit<<endl;
	cout<<"Temperature in C: "<<read.temperature.centigrade<<endl;

	cout<<endl;
	Reading *ptr=&read;
	recordReading(ptr);


    return 0;

}


void showReading(Reading r)
{
	cout<<"Wind speed(mph): "<<r.windSpeed<<endl;
	cout<<"Humidity(%): "<<r.humidity<<endl;
	cout<<"Temperature in F: "<<r.temperature.farenheit<<endl;
	cout<<"Temperature in C: "<<r.temperature.centigrade<<endl;

}

void findReading(Reading &r)
{
	cout<<"Enter Wind speed(mph): ";
	cin>>r.windSpeed;

	cout<<"Enter Humidity(%): ";
	cin>>r.humidity;

	cout<<"Enter Temperature in C: ";
	cin>>r.temperature.centigrade;
	
	r.temperature.farenheit=((r.temperature.centigrade)*(9/5))+32;

}

Reading getReading()
{
	Reading agRead;

	cout<<"Enter Wind speed(mph): ";
	cin>>agRead.windSpeed;

	cout<<"Enter Humidity(%): ";
	cin>>agRead.humidity;

	cout<<"Enter Temperature in C: ";
	cin>>agRead.temperature.centigrade;
	
	agRead.temperature.farenheit=(agRead.temperature.centigrade)*9/5+32;


	cout<<endl;

	return agRead;


}

void recordReading(Reading *r)
{
	cout<<"Enter Wind speed(mph): ";
	cin>>(*r).windSpeed;

	cout<<"Enter Humidity(%): ";
	cin>>(*r).humidity;

	cout<<"Enter Temperature in C: ";
	cin>>(*r).temperature.centigrade;


}
