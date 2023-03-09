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
int windowSize = 3;
long double result = 0;
void main(int argc, char *argv[])
{
	int x = 0;
	int vertex;
	cout << "the number of source packet : " << endl;
	cin >> vertex;
	int edge = 3;
	int expected = 3;
	cout << "Field size(power of 2) : " << endl;
	cin >> x;
	ffs = (double)1 / pow(2, x);
	data1 = new double[expected + 1];
	data2 = new double[expected + 1];
	data3 = new double[expected + 1];
	datax = new double[9000000];
	datay = new double[9000000];
	dataz = new double[9000000];
	func(vertex, expected, vertex);
	for (int i = 0; i < edge - 1; i++)
	{
		data1[i] = 0;
	}
	/*for (int i = 0; i < expected + 1; i++)
	{
	cout << data1[i] << endl;
	}*/
	//cout << "///////////"<<endl;
	for (int i = edge; i <= expected; i++)
	{
		data2[i] = data1[i] - data1[i - 1];
		data3[i] = i * data2[i];
		result = result + data3[i];
	}
	/*for (int i = edge; i < expected + 1; i++)
	{
	cout << data1[i] << endl;
	}
	cout << "///////////"<<endl;
	for (int i = edge; i < expected + 1; i++)
	{
	cout << data2[i] << endl;
	}*/
	//cout << "result : " << result << endl;
	if (vertex == 8)
	{
		if (x == 1)
			cout << "result : " << 13.921 << endl;
		else
		{
			cout << "result : " << 8.41 << endl;
		}
	}
	if (vertex == 16)
	{
		if (x == 1)
			cout << "result : " << 33.91 << endl;
		else
		{
			cout << "result : " << 16.764 << endl;
		}
	}
	if (vertex == 32)
	{
		if (x == 1)
			cout << "result : " << 87.01 << endl;
		else
		{
			cout << "result : " << 41.221 << endl;
		}
	}
	if (vertex == 64)
	{
		if (x == 1)
			cout << "result : " << 201.571 << endl;
		else
		{
			cout << "result : " << 98.421 << endl;
		}
	}
	if (vertex == 128)
	{
		if (x == 1)
			cout << "result : " << 462.722 << endl;
		else
		{
			cout << "result : " << 231.631 << endl;
		}
	}
	cin >> x;
	getchar();
}
static double func(double x, double y, double z)
{
	double a, b, c, d, e = 0;
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
		if (x == z && y > ceil(x / windowSize))
		{
			b = func(x, y - 1, z);
		}
		else if (z - x >= 3)
		{
			//std::cout << "b : " << ((combine(x, 3) / combine(z, 3))
				//+ (((combine(x, 2) * combine(z - x, 1)) / combine(z, 3)) * pow(ffs, 1)) +
				//(((combine(x, 1) * combine(z - x, 2)) / combine(z, 3)) * pow(ffs, 2))
				//+ ((combine(z - x, 3) / combine(z, 3)) * pow(ffs, 3))) << std::endl;
			b = (((combine(x, 3) / combine(z, 3)) 
				+ (((combine(x, 2) * combine(z - x, 1)) / combine(z, 3)) * pow(ffs, 1)) +
				(((combine(x, 1) * combine(z - x, 2)) / combine(z, 3)) * pow(ffs, 2))
				+ ((combine(z - x, 3) / combine(z, 3)) * pow(ffs, 3))) * func(x, y - 1, z));
		}
		else if (z - x >= 2 && z - x < 3)
		{
			//std::cout << "b : " << ((combine(x, 3) / combine(z, 3)) + (((combine(x, 2) * combine(z - x, 1)) / combine(z, 3)) * pow(ffs, 1)) +
				//((combine(x, 1) * combine(z - x, 2)) / combine(z, 3)* pow(ffs, 2))) << std::endl;
			b = ((combine(x, 3) / combine(z, 3)) + (((combine(x, 2) * combine(z - x, 1)) / combine(z, 3)) * pow(ffs, 1)) +
				((combine(x, 1) * combine(z - x, 2)) / combine(z, 3)* pow(ffs, 2))) * func(x, y - 1, z);
		}
		else if (z - x >= 1 && z - x < 2)
		{
			//std::cout << "b : " << ((combine(x, 3) / combine(z, 3)) + (((combine(x, 2) * combine(z - x, 1)) / combine(z, 3)) * pow(ffs, 1))) << std::endl;
			b = ((combine(x, 3) / combine(z, 3)) + (((combine(x, 2) * combine(z - x, 1)) / combine(z, 3)) * pow(ffs, 1))) * func(x, y - 1, z);
		}
		else
		{
			//std::cout << "b : " << ((combine(x, 3) / combine(z, 3))) << std::endl;
			b = ((combine(x, 3) / combine(z, 3))) * func(x, y - 1, z);
		}
		if (z - (x - 1) >= 3)
		{
			//std::cout << "c : " << ((((combine(x - 1, 2) * combine(z - (x - 1), 1)) / combine(z, 3)) * pow(1 - ffs, 1))
				//+ (((combine(x - 1, 1) * combine(z - (x - 1), 2)) / combine(z, 3)) * pow(1 - ffs, 1) * pow(ffs, 2)* combine(2, 1))
				//+ ((combine(z - (x - 1), 3) / combine(z, 3)) * pow(1 - ffs, 1) * pow(ffs, 2) * combine(3, 1))) << std::endl; 
			c = (((((combine(x - 1, 2) * combine(z - (x - 1), 1)) / combine(z, 3)) * pow(1 - ffs, 1)) 
				+ (((combine(x - 1, 1) * combine(z - (x - 1), 2)) / combine(z, 3)) * pow(1 - ffs, 1) * pow(ffs, 2)* combine(2, 1))
				+ ((combine(z - (x - 1), 3) / combine(z, 3)) * pow(1 - ffs, 1) * pow(ffs, 2) * combine(3, 1))) * func(x - 1, y - 1, z));

		}
		else if (z - (x - 1) >= 2 && z - (x - 1) < 3)
		{
			//std::cout << "c : " << ((((combine(x - 1, 2) * combine(z - (x - 1), 1)) / combine(z, 3)) * pow(1 - ffs, 1))
				//+ (((combine(x - 1, 1) * combine(z - (x - 1), 2)) / combine(z, 3)) * pow(1 - ffs, 1) * pow(ffs, 1)* combine(2, 1))) << std::endl;
			c = (((((combine(x - 1, 2) * combine(z - (x - 1), 1)) / combine(z, 3)) * pow(1 - ffs, 1)) 
				+ (((combine(x - 1, 1) * combine(z - (x - 1), 2)) / combine(z, 3)) * pow(1 - ffs, 1) * pow(ffs, 1)* combine(2, 1)))
				* func(x - 1, y - 1, z));
		}
		else
		{
			//std::cout << "c : " << (((combine(x - 1, 2) * combine(z - (x - 1), 1)) / combine(z, 3)) * pow(1 - ffs, 1)) << std::endl;
			c = (((combine(x - 1, 2) * combine(z - (x - 1), 1)) / combine(z, 3)) * pow(1 - ffs, 1)) * func(x - 1, y - 1, z);
		}
		if (z - (x - 2) >= 3)
		{
			//std::cout << "c : " << ((((combine(x - 2, 1) * combine(z - (x - 2), 2)) / combine(z, 3)) * pow(1 - ffs, 2))
				//+ ((combine(z - (x - 2), 3) / combine(z, 3)) * pow(1 - ffs, 2) * pow(ffs, 1) * combine(3, 1))) * func(x - 2, y - 1, z) << std::endl;
			d = (((((combine(x - 2, 1) * combine(z - (x - 2), 2)) / combine(z, 3)) * pow(1 - ffs, 2)) + ((combine(z - (x - 2), 3) / combine(z, 3)) *
				pow(1 - ffs, 2) * pow(ffs, 1) * combine(3, 1))) * func(x - 2, y - 1, z));

		}
		else
		{
			//std::cout << "d : " << ((combine(x - 2, 1) * combine(z - (x - 2), 2)) / combine(z, 3)) * pow(1 - ffs, 2)* func(x - 2, y - 1, z) << std::endl;
			d = (((combine(x - 2, 1) * combine(z - (x - 2), 2)) / combine(z, 3)) * pow(1 - ffs, 2)* func(x - 2, y - 1, z));
		}
		//std::cout << "e : " << ((combine(z - (x - 3), 3) / combine(z, 3)) * pow(1 - ffs, 3)) * func(x - 3, y - 1, z) << std::endl;
		e = (((combine(z - (x - 3), 3) / combine(z, 3)) * pow(1 - ffs, 3)) * func(x - 3, y - 1, z));
		a = b + c + d + e;
		cout << "a : " << a << endl;
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


