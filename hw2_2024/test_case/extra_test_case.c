void codegen();
void codegen()
{
  digitalWrite(26, HIGH);
  delay(1000);
  digitalWrite(26, LOW);
  delay(1000);
}
void codegen();
int dp_fib(int *dp, const int fi);

void codegen() {
  int dp[5];
  int i;
  for (i = 0; i < 5; i = i + 1) { /* initialize dp */
    *(dp + i) = 0;
  }
  const int a = dp_fib(dp, 6); /* a = 8 */
  const int b = dp_fib(dp, 4); /* b = 3 */
  digitalWrite(26, HIGH);
  delay(a * 1000);
  digitalWrite(26, LOW);
  delay(b * 1000);
}

int dp_fib(int *dp, const int fi) {
  if (fi == 0) {
    return 0;
  }
  if (fi == 1) {
    return 1;
  }
  const int shifted_fi = fi - 2;
  if (dp[shifted_fi] == 0) {
    const int ret = dp_fib(dp, fi - 2) + dp_fib(dp, fi - 1);
    dp[shifted_fi] = ret;
    return ret;
  } else {
    return dp[shifted_fi];
  }
}
void codegen();
void codegen()
{
  int a = 4; // a = 4
  int b = (a - 2) * (a - 1); // b = 6
  digitalWrite(27, HIGH);
  delay(a * 1000); // delay 4 seconds
  digitalWrite(27, LOW);
  delay(b * 1000); // delay 6 seconds
}
void codegen();
void codegen()
{
  int a = 1 + 2 * 1; // a = 3
  int b = (a + 3) / 2; // b = 3
  digitalWrite(26, HIGH);
  delay(a * 1000); // delay 3 seconds
  digitalWrite(26, LOW);
  delay(b * 1000); // delay 3 seconds
}
void codegen();

void codegen() {
  int input_data[17];
  int i;
  for (i = 0; i < 17; i = i + 1) {
    input_data[i] = i;
  }

  int end = 0;
  int data[17];
  for (i = 0; i < 17; i = i + 1) {
    int *id = input_data + i;
    
    int slot = end;
    int cont = slot != 0;
    while (cont) {
      const int parent = (slot - 1) / 2;
      if (data[parent] < *id) {
        *(data + slot) = *(data + parent);
        slot = parent;
      } else {
        cont = 0;
      }
      if (slot == 0) {
        cont = 0;
      }
    }
    data[slot] = *id;
    end = end + 1;
  }

  digitalWrite(26, HIGH);
  delay((data[0] - data[2]) * 1000); /* data[0] - data[2] = 3 */
  digitalWrite(26, LOW);
  delay((end - data[0]) * 1000); /* end - data[0] = 1 */
}
void codegen();

void codegen() {
  int fib[7];
  int i = 0;
  do {
    if (i == 0) {
      fib[i] = 0;
    } else {
      if (i == 1) {
        fib[i] = 1;
      } else {
        int *f1 = fib + i - 1, *f2 = fib + i - 2;
        fib[i] = *f1 + *f2;
      }
    }
    i = i + 1;
  } while (i < 7);

  digitalWrite(28, HIGH);
  delay((fib[6] - fib[3]) * 1000); // fib[6] - fib[3] = 6
  digitalWrite(28, LOW);
  delay((fib[5] - fib[1]) * 1000); // fib[5] - fib[1] = 4
}
void codegen();
int modulo(const int *a, const int *b);
int gcd(const int a, const int b);

void codegen()
{
  int a = gcd(12, 18); // a = 6
  int b = gcd(8, 9); // b = 1
  const int c6 = 6, c4 = 4;
  digitalWrite(26 + modulo(&c6, &c4), HIGH);
  delay(a * 1000);
  digitalWrite(26 + modulo(&c6, &c4), LOW);
  delay(b * 1000);
}

int modulo(const int *a, const int *b)
{
  if (*a < *b) {
    return *a;
  }

  int ret = *a;
  while (1) {
    ret = ret - *b;
    if (ret < *b) {
      break;
    }
  }
  return ret;
}

int gcd(const int a, const int b)
{
  if (b != 0) {
    return gcd(b, modulo(&a, &b));
  } else {
    return a;
  }
}

void codegen();

void codegen() {
  int a = 42 - 53 * 2; /* a = -64 */
  int *b = &a; /* *b = -64 */
  *b = -a / 8; /* a = 8, *b = 8 */
  a = *b - 4; /* a = 4, *b = 4 */
  digitalWrite(28, HIGH);
  delay(a * 1000);
  digitalWrite(28, LOW);
  delay(*b * 1000);
}
void codegen();

void codegen() {
  int a = 58 / 17; /* a = 3 */
  int b = a * 2 + 10; /* b = 16 */
  int *c = &a; /* *c = 3 */
  *c = *c + 1; /* *c = 4, a = 4 */
  c = &b; /* *c = 16 */
  *c = b / a; /* *c = 4, b = 4 */
  digitalWrite(29, HIGH);
  delay(a * 1000 + 1000); /* 5 seconds */
  digitalWrite(29, LOW);
  delay(b * 1000 - 250 * 8); /* 2 seconds */
}
void codegen();

void codegen() {
  int a = 58 / 17; /* a = 3 */
  int b = a * 2 + 10; /* b = 16 */
  int *c = &a; /* *c = 3 */
  *c = *c + 1; /* *c = 4, a = 4 */
  c = &b; /* *c = 16 */
  *c = b / a; /* *c = 4, b = 4 */
  digitalWrite(29, HIGH);
  delay(a * 1000 + 1000); /* 5 seconds */
  digitalWrite(29, LOW);
  delay(b * 1000 - 250 * 8); /* 2 seconds */
}


