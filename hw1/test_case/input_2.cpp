#pragma token                  off
int main() {
  int a = 1;
  int b = -1;
  char test[1000] = "      \n\n";
  printf("%d", a);
  return a + b;
}
#pragma   token     on
int iter(int n)
{
  int sum = 1;
	for(int i = 1; i <= n; i++){
    a=b+c;/*

    comment a=b+c;

    */a=b+c;//a=b+c;
		sum *= i;
	}
  return sum;
}
int main(void) {
	int sum = iter(10);
	printf("%d", sum);
	return 0;
}
