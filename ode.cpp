#include <iostream>
#include <vector>
class Fun
{
public: 
	Fun(int dim): dqdt(dim,0.0) 
	{
	}
	std::vector<double> getEqns(std::vector<std::vector<double> >A, std::vector<double>q);

private:
	std::vector<double> dqdt;
};

std::vector<double> Fun::getEqns(std::vector<std::vector<double> >A, std::vector<double>q)
{
	for (int i = 0; i < q.size(); i++)
	{
		dqdt[i] = 0;
		for (int j = 0; j < q.size(); j++)
		{
			dqdt[i]+= A[i][j] * q[j];
			// printf("%4f\n", dqdt[i]);
		}
	}
	return dqdt;
}

int main(int argc, const char *argv[])
{
	double t = 0, dt = 0.01, tf = 1.0;
	std::vector<double> q = {10.0, 2.0, 3.0};

	// std::vector<double> q(1,1.0);
	Fun f(3);
	std::vector<std::vector<double> > A = {{1.0,2.0,3.0},{4.0,6.0,7.0},{2.0,1.0,0.0}};
	// std::vector<std::vector<double> > A = {{1.0}};
	while (t < tf)
	{
		std::vector<double> dqdt = f.getEqns(A, q);
		for (int i = 0; i <q.size(); i++)
		{
			q[i] += dt * dqdt[i];


		}
		t += dt;
		printf("t= %4f, q = %4f, %4f, %4f\n", t, q[0], q[1], q[2]);
	}

	return 0;

}