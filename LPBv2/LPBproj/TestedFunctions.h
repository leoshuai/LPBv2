#pragma once
void GenMXHILB(const Eigen::VectorXd & x, double& y, Eigen::VectorXd & s)
{
	y = 0;
	size_t k;
	double v, tem, t1;
	for (size_t i = 0, size = x.size(); i < size; i++)
	{
		v = 0;
		for (size_t j = 0, size = x.size(); j < size; j++)
			v += (*(x.data() + j)) / (i + j + 1.0);
		t1 = abs(v);
		if (t1 > y)
		{
			y = t1;
			k = i;
			tem = v;
		}
	}
	if (tem > 0)
	{
		for (size_t i = 0, size = s.size(); i < size; i++)
		{
			*(s.data() + i) = 1.0 / (i + k + 1);
		}
	}
	else if (tem < 0)
	{
		for (size_t i = 0, size = s.size(); i < size; i++)
		{
			*(s.data() + i) = -1.0 / (i + k + 1);
		}
	}
	else
		s.setZero();
}
