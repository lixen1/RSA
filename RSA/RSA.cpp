#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b, int& x, int& y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}

	int x1 = 0;
	int y1 = 0;

	int d = gcd(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;

	return d;
}

unsigned long gcd(unsigned long a, unsigned long b)
{
	while (b > 0)
	{
		unsigned long tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

unsigned long gcd_rec(unsigned long a, unsigned long b)
{
	if (b == 0)
		return a;
	return gcd_rec(b, a % b);
}

void f()
{
	/*for (int i = 0; i < 10000000; i++)
	{
		for (int j = 0; j < 10000000; j++)
		{
			if (i * e == j * f + 1)
			{
				d = i;
				k = j;
				b = true;
				break;
			}
		}

		if (b == true) break;
	}*/
}

void key_generate(int p, int q, int& e, int& d, int& k)
{
	int f = 0;
	bool b = false;

	f = (p - 1) * (q - 1);

	for (int i = 2; i < f; i++)
	{
		if (gcd(i, f) == 1)
		{
			e = i;
			break;
		}
	}

	gcd(e, f, d, k);

	d = abs(d);
	k = abs(k);


}

void print_vector(vector<int> vp)
{
	size_t size = vp.size();
	for (int i = 0; i < size; i++)
	{
		cout << vp[i] << " ";
	}
	cout << endl;
}

vector<int> encrypt(vector<int> seq, int n, int e)
{
	vector<int> res;
	size_t size = seq.size();

	for (int i = 0; i < size; i++)
	{
		res.push_back((int)pow(seq[i], e) % n);
	}
	return res;
}

vector<int> decrypt(vector<int> seq, int n, int d)
{
	vector<int> res;
	size_t size = seq.size();

	for (int i = 0; i < size; i++)
	{
		res.push_back((int)pow(seq[i], d) % n);
	}
	return res;
}

int main()
{
	int p = 0;
	int q = 0;
	int numb = 0;
	int y = 0;
	int n = 0;
	int e = 0;
	int d = 0;
	int k = 0;

	vector<int> sequence;
	vector<int> encrypted;
	vector<int> decrypted;

	cout << "Input p and q: ";
	cin >> p >> q;
	n = p * q;

	key_generate(p, q, e, d, k);
	//cout << d << "\t" << k << "\t" << e << endl;

	cout << "Input numbers from 0 to " << n - 1 << " (-1 as end of input) : ";
	cin >> numb;
	while (numb != -1)
	{
		sequence.push_back(numb);
		cin >> numb;
	}

	encrypted = encrypt(sequence, n, e);
	cout << "Encrypt message: ";
	print_vector(encrypted);

	decrypted = decrypt(encrypted, n, d);
	cout << "Decrypt message: ";
	print_vector(decrypted);

	return 0;
}
