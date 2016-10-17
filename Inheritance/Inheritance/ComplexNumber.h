#pragma once
class ComplexNumber
{
public:

	ComplexNumber(float real, float imaginary);
	ComplexNumber();
	~ComplexNumber();

	ComplexNumber& operator=(const ComplexNumber &rhs);
	ComplexNumber& operator+(const ComplexNumber &rhs);
	ComplexNumber& operator-(const ComplexNumber &rhs);

	friend ostream& operator<<(ostream& ostr, const ComplexNumber &cnum);

private:

	float real;
	float imaginary;	
};

ComplexNumber::ComplexNumber(float real, float imaginary) : real(real), imaginary(imaginary)
{

}

ComplexNumber::ComplexNumber() : real(0), imaginary(0)
{

}

ComplexNumber::~ComplexNumber()
{

}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber &rhs)
{
	real = rhs.real;
	imaginary = rhs.imaginary;
	
	return *this;
}

ComplexNumber& ComplexNumber::operator+(const ComplexNumber &rhs)
{
	real += rhs.real;
	imaginary += rhs.imaginary;

	return *this;
}

ComplexNumber& ComplexNumber::operator-(const ComplexNumber &rhs)
{
	real -= rhs.real;
	imaginary -= rhs.imaginary;

	return *this;
}

ostream& operator<<(ostream& ostr, const ComplexNumber &cnum)
{
	ostr << "( " << cnum.real << " + " << cnum.imaginary << "i )";
	return ostr;
}


