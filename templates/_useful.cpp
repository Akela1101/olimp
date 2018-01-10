// get bits from high to low
for (int i = n - 1; i >= 0; i--) 
{
	int b = x / (1 << i);
	x -= b << i;
}