#define i64 long long int
#define mod 1000000007

i64 multiply(i64 a, i64 b)
{
	i64 rem1 = a % mod;
	i64 rem2 = b % mod;
	return (rem1 * rem2) % mod;
}

i64 exponent(i64 base, i64 power)
{
	power = (power) % (mod - 1); // from Fermat's little theorem
	i64 result = multiply(base, base);
	for(int i = 2; i < power; i++)
	{	
		result = multiply(base, result);
	}
	return result;
}

i64 addition(i64 a, i64 b)
{
	i64 rem1 = a % mod;
	i64 rem2 = b % mod;
	return (rem1 + rem2) % mod;
}

