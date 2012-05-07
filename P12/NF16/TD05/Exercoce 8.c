pow_a(float x, unsigned int n){
	if (n==0) return 1;
	else return (x*pow_a(x, n-1));
}

pow_b(float x, unsigned int n){
	if (n==0) return 1;
	else if (n%2==0) return (pow_b(x*x, n/2));
	else return (x*pow_b(x*x, n/2));
}

