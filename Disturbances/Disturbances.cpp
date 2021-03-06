// Disturbances.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ПИВ

#include "pch.h"
#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

class Disturbances
{
private:
    double ampl = 3.5;
	vector<double> R;
	vector<double> L;
	double Ntid;
public: 
	Disturbances(int n)
	{
		cout << "Constructor" << endl;
		for (int i = 0; i < n; i++)
		{
			R.push_back(100);
			L.push_back(50);
		}
	}

	double getValue(vector<double> r, double Ne = 1.7)
	{
		for (int i = 0; i < r.size(); i++)
		{
			Ntid = exp(-(r[i]-R[i])/L[i]);
		}
		Ntid = Ne*(ampl*Ntid + 1);
		return (Ntid);
	}

	void showParameters()
	{
		cout << "Amplitude = " << ampl << "\n";
		cout << "R: ";
		for (int i = 0; i < R.size(); i++)
		{
			cout << R[i] << " ";
		}
		cout << endl;
		cout << "L: ";
		for (int i = 0; i < L.size(); i++)
		{
			cout << L[i] << " ";
		}
		cout << endl;
		//cout << "Ntid = " << Ntid;
	}
};

int main()
{
	
	Disturbances TID(3);
	vector<double> m(3);
	cout << fixed;
	cout.precision(2);
	cout << "Ntid = " << TID.getValue(m, 1.7) << "\n";
	cout << "TID: \n"; TID.showParameters();
	cout << endl;
	return 0;
}