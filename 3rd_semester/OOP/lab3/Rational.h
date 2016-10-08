#pragma once
class Rational
{
private:
	int numerator;
	int denominator;
public:
	
	Rational(int=0, int=1);
	Rational(const Rational &);
	Rational add(const Rational&) const;
	Rational subtract(const Rational & ) const;
	Rational multiply(const Rational & ) const;
	Rational divide(const Rational & ) const;
	void print( ) const;
	~Rational();
};

