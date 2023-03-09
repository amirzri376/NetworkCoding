/* this is a c++ program 
We have two entries the first one is the number of source packets and second one is the Finite Field size
for the first one n = 64 and 128 would be suitable and secodinf one x (2 ^ x)=  1,4,5 would be suitable.
*/

#include <iostream>
#include <conio.h>
#include <math.h> 
using namespace std;

double combine(double n, double k);
double func(double n, double k, double p);
double *data1, *data2, *data3;
double *datax, *datay, *dataz;
double ffs;
int k = 0;
int windowSize = 2;
long double result = 0;
void main(int argc, char *argv[])
{
	int ff = 0;
	int vertex;
	cout << "Enter the number of source packets : "<< endl;
	cin >> vertex;
	int edge = vertex;
	int expected = vertex * 15;
	cout << "Enter Field size of x, x is power of 2, (2 ^ x) : " << endl;
	cin >> ff;
	ffs = (double)1 / pow(2, ff);
	data1 = new double[expected + 1];
	data2 = new double[expected + 1];
	data3 = new double[expected + 1];
	datax = new double[9000000];
	datay = new double[9000000];
	dataz = new double[9000000];
	for (int i = 0; i < edge - 1; i++)
	{
		data1[i] = 0;
	}
	for (int i = edge; i <= expected; i++)
	{
		func(vertex, i, vertex);
		result = result + (i * data1[i]);
	}
	
	/*for (int i = 0; i < expected + 1; i++)
	{
		cout << data1[i] << endl;
	}*/
	//cout << "///////////"<<endl;
	/*for (int i = edge; i <= expected; i++)
	{
		data2[i] = data1[i] - data1[i - 1];
		data3[i] = i * data2[i];
		result = result + data3[i];
	}*/
	/*for (int i = edge; i < expected + 1; i++)
	{
		cout << data1[i] << endl;
	}
	cout << "///////////"<<endl;
	for (int i = edge; i < expected + 1; i++)
	{
		cout << data2[i] << endl;
	}*/
	cout << "result : " << result << endl;
	cin >> ff;
	getchar();
}
static double func(double x, double y, double z)
{
	double a, b, c, d = 0;
	//cout << "x : " << x << "," << " y : " << y <<endl;
	if (x < windowSize || y < (ceil(x / windowSize)))
		return 0;
	else if (x == windowSize && y == 1)
		return 1;
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (x == datax[i])
			{
				if (y == datay[i])
				{
					return dataz[i];
				}
			}
		}
		//std::cout << "x :  " << x << " y : " << y << std::endl;
		//std::cout << "b : " << ((combine(x1, 2) / combine(z, 2)) + ((((x - 1) * (z - (x - 1))) / combine(z, 2)) * pow(ffs, 1)) + ((combine(z - (x - 2), 2) / combine(z, 2)) * pow(ffs, 2))) << std::endl;
		//std::cout << "c  : " << (((((x - 1) * (z - (x - 1))) / combine(z, 2)) * pow(1 - ffs, 1)) + ((combine(z - (x - 2), 2) / combine(z, 2)) * pow(1 - ffs, 1) * pow(ffs, 1))) << std::endl;
		//std::cout << "d  : " << ((combine(z - (x - 2), 2) / combine(z, 2)) * pow(1 - ffs, 2)) << std::endl;
		//We insert this if because of absorbing state actually I want probablity enerance absorbing state to each other be 1
		if (x == z)
		{
			b = 0;
		}
		else if (z - x >= 2)
		{
			//std::cout << "b : " << ((combine(x, 2) / combine(z, 2)) + (((x  * (z - x)) / combine(z, 2)) * pow(ffs, 1)) + ((combine(z - x, 2) / combine(z, 2)) *
				//pow(ffs, 2))) << std::endl;
			b = (((combine(x, 2) / combine(z, 2)) + (((x  * (z - x)) / combine(z, 2)) * pow(ffs, 1)) + ((combine(z - x , 2) / combine(z, 2)) *
				pow(ffs, 2))) * func(x, y - 1, z));
		}
		else
		{
			//std::cout << "b : " << ((combine(x, 2) / combine(z, 2)) + (((x  * (z - x)) / combine(z, 2)) * pow(ffs, 1))) << std::endl;
			b = ((combine(x, 2) / combine(z, 2)) + (((x  * (z - x)) / combine(z, 2)) * pow(ffs, 1))) * func(x, y - 1, z);
		}

        //std::cout << "b : " << b << std::endl;
		
		if (z - (x - 1) >= 2)
		{
			//std::cout << "c : " << (((((x - 1) * (z - (x - 1))) / combine(z, 2)) * pow(1 - ffs, 1)) + ((combine(z - (x - 1), 2) / combine(z, 2)) *
				//pow(1 - ffs, 1) * pow(ffs, 1) * combine(2, 1))) << std::endl;
			c = ((((((x - 1) * (z - (x - 1))) / combine(z, 2)) * pow(1 - ffs, 1)) + ((combine(z - (x - 1), 2) / combine(z, 2)) *
				pow(1 - ffs, 1) * pow(ffs, 1) * combine(2,1))) * func(x - 1, y - 1, z));

		}
		else
		{
			//std::cout << "c : " << (((x - 1) * (z - (x - 1))) / combine(z, 2)) * pow(1 - ffs, 1) << std::endl;
			c = (((x - 1) * (z - (x - 1))) / combine(z, 2)) * pow(1 - ffs, 1) * func(x - 1, y - 1, z);
		}
		//std::cout << "c : " << c << std::endl;
		//std::cout << "d : " << ((combine(z - (x - 2), 2) / combine(z, 2)) * pow(1 - ffs, 2)) << std::endl;
		d = (((combine(z - (x - 2), 2) / combine(z, 2)) * pow(1 - ffs, 2)) * func(x - 2, y - 1, z));
		//std::cout << "b :  " << b << " /c : " << c << " /d : "<< d << std::endl;
		a = b + c + d;
		//cout << "a : " << a << endl;
		if (x == z)
		{
			//cout << "x : " << x << "," << " y : " << y << endl;
			data1[(int)y] = a;
			//cout << "data1 " << y <<"= "<< a<< endl;
		}
		datax[k] = x;
		datay[k] = y;
		dataz[k] = a;
		k++;
		return a;
	}
}
double combine(double n, double k)
{
	double v = 1;
	for (int i = 1; i <= k; i++)
		v = v * (n + 1 - i) / i;
	return v;
}


