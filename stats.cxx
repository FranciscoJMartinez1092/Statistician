//FILE: stats.cxx
//CLASS IMPLEMENTED : statistician(see stats.h for documentation
#include "stats.h"
#include <cassert> //Provides Assert
namespace main_savitch_2C //Provides stats definition
{
	statistician::statistician()
	//constrtucts a statistician that can do basic statistics with numbers stored
	{
		count = 0;
		total = 0;
		
	}
	void statistician::next(double r)
	//stores numbers
	{
		if (count == 0)
		{
			tinyest = r;
			largest = r;
		}
		count++;
		total = total + r;
		if(r > largest)
			largest = r;
		if (r < tinyest)
			tinyest = r;
	}
	void statistician::reset()
	{
		count = 0;
		total = 0;
	}

	int statistician::length() const
	{
		return count;
	}
	double statistician::sum() const
	{
		return total;
	}
	double statistician::mean() const
	{
		assert(count > 0);
		return (total / count);
	}
	double statistician::minimum() const
	{
		assert(count > 0);
		return tinyest;
	}

	double statistician::maximum() const
	{
		assert(count > 0);
		return largest;
	}

	statistician operator +(const statistician& s1, const statistician& s2) 
	{
		statistician s3;
		
		if (s1.count == 0)
		{
			s3.tinyest = s2.tinyest;
			s3.largest = s2.largest;
		}
		if (s2.count == 0)
		{
			s3.tinyest = s1.tinyest;
			s3.largest = s1.largest;
		}
		if (s1.count > 0 && s2.count > 0)
		{
			if (s1.tinyest < s2.tinyest)
				s3.tinyest = s1.tinyest;
			else
				s3.tinyest = s2.tinyest;
			if (s1.largest > s2.largest)
				s3.largest = s1.largest;
			else
				s3.largest = s2.largest;
		}

		s3.total = s1.total + s2.total;
		s3.count = s1.count + s2.count;
		return s3;
	}
	statistician operator *(double scale, const statistician& s)
	{
		statistician s3;
		if (scale > 0)
		{
			s3.tinyest = s.tinyest * scale;
			s3.largest = s.largest * scale;
		}
		else
		{
			s3.tinyest = s.largest * scale;
			s3.largest = s.tinyest * scale;
		}
		s3.total = s.total * scale;
		s3.count = s.count;
		return s3;
	}
	bool operator ==(const statistician& s1, const statistician& s2)
	{
		if (s1.length() == 0 && s2.length() == 0)
			return 1;
		return (s1.length() == s2.length()) && (s1.sum() == s2.sum())
			&& (s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum())
			&& (s1.maximum() == s2.maximum());
		
	}
}