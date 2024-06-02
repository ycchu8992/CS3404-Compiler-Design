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
// by redleaf23477
const signed int a[3];
const signed long int a[c&b];
const signed long long int a[a||b];
const signed short int a[+c];

const unsigned int a[-a];
const unsigned long int a[2.0];
const unsigned long long int a[-3];
const unsigned short int a[1-2+c*d-c^e];

const int a[b&&c&&d];
const long int a[3][3];
const long long int a[3][4];
const short int a[3][3][b*c&&d];

int a[3][4][5][6][7];
long int a[3][x][y][+x];
long long int a[3][foo()][bar(a,b)];
short int a[&c];

const unsigned int a[b++];
const unsigned long int a[b--];
const unsigned long long int a[--b*c(d)];
const unsigned short int a[(int)3];

const signed int a[NULL];
const signed long int a[++a];
const signed long long int a[*b];
const signed short int a[arr[3][4][5]];

const signed long long a[3<<1];
const signed long a[2+1>>3&4%5][7];
const signed char a[3][(double)8787+a];
const signed short a[(char*)str];

signed a[3];
unsigned a[3];
float a[3];
double a[3];
void a[3];
const a[3];
// by redleaf23477
const signed int a[3] = {1, 2, 3, 4, 5};
const signed long int a[c&b] = {2342};
const signed long long int a[a||b];
const signed short int a[+c];

const unsigned int a[-a];
const unsigned long int a[2.0];
const unsigned long long int a[-3];
const unsigned short int a[1-2+c*d-c^e];

const int a[b&&c&&d];
const long int a[4][3] = { {234234}, {"a", "aaaa", 1234234}, {+___+__+___+___++}};
const long long int a[3][4];
const short int a[3][3][b*c&&d];

int a[3][4][5][6][7];
long int a[3][x][y][+x];
long long int a[3][foo()][bar(a,b)] = {
    {
        {sakldfjsd, 23423432, "sldfkjslf", 'a'}, {
                                                     "hahfshsdhsdhsdjfkjlsdkjlsdfkjlsdflkjsdfkjlsfkdjlsdfkjldfs"
                                                 }
    },
    {
        { asdfasf, safsadfsd, asdfasdfsdf, asdfasdfadsfsdf, adfasdfsadfsadfasdfasdfasdfasdf }, 
        { "lkjdfslkjdfslkjdfoiuw3oiwriuorwe", (char*)&a&aa&a&a }
    },
    { (NULL)*(NULL&NULL)+(NULL+NULL&NULL*NULL)}
};
short int a[&c];

const unsigned int a[b++];
const unsigned long int a[b--];
const unsigned long long int a[--b*c(d)];
const unsigned short int a[(int)3];

const signed int a[NULL];
const signed long int a[++a];
const signed long long int a[*b];
const signed short int a[arr[3][4][5]];

const signed long long a[3<<1];
const signed long a[2+1>>3&4%5][7];
const signed char a[3][(double)8787+a];
const signed short a[(char*)str];

signed a[3];
unsigned a[3];
float a[3];
double a[3];
void a[3];
const a[3];
// by redleaf23477
int main() {
    (const signed int)a;
    (const signed long int)a;
    (const signed long long int)a;
    (const signed short int)a;
    (const unsigned int)a;
    (const unsigned long int)a;
    (const unsigned long long int)a;
    (const unsigned short int)a;
    (const int)a;
    (const long int)a;
    (const long long int)a;
    (const short int)a;
    (int)a;
    (long int)a;
    (long long int)a;
    (short int)a;

    (const unsigned int)a;
    (const unsigned long int)a;
    (const unsigned long long int)a;
    (const unsigned short int)a;

    (const signed int)a;
    (const signed long int)a;
    (const signed long long int)a;
    (const signed short int)a;

    (const signed long long)a;
    (const signed long)a;
    (const signed char)a;
    (const signed short)a;

    (signed)a;
    (unsigned)a;
    (float)a;
    (double)a;
    (void)a;
    (const)a;

    (const signed int *)a;
    (const signed long int *)a;
    (const signed long long int *)a;
    (const signed short int *)a;

    (const signed long long *)a;
    (const signed long *)a;
    (const signed char *)a;
    (const signed short *)a;

    (const signed int*)a;
    (const signed long int*)a;
    (const signed long long int*)a;
    (const signed short int*)a;

    (const signed long long*)a;
    (const signed long*)a;
    (const signed char*)a;
    (const signed short*)a;

    (const signed int *)a;
    (const signed long int *)a;
    (const signed long long int *)a;
    (const signed short int *)a;

    (const signed long long *)a;
    (const signed long *)a;
    (const signed char *)a;
    (const signed short *)a;

}
// by redleaf23477
int main() {
    a + b;
    +a;
    -a;
    a - b;
    a * b;
    a / b;
    a % b;
    a++;
    ++a;
    a--;
    --a;
    a < b;
    a <= b;
    a > b;
    a >= b;
    a == b;
    a != b;
    a = b;
    a && b;
    a || b;
    !a;
    ~a;
    a ^ b;
    a | b;
    a >> b;
    a << b;
    a[b];
    a[b][c][d];
    foo();
    foo(a, b, ++a);
    *a;
    &a;
    (char)a;
    (char*)a;
    (a+b)*c;

    a;
    1234;
    1234.029482;
    .0234313;
    0.;
    98438.;
    'c';
    '"';
    "aslfjsldfkjsad";
    "'";



         +123  ;
+0; 0; -0;    
           -3654;


+23.032;   3112.32304;       +.32143;
+2132.   ;
+0.; +.0; -0.; -.0;
-123645.313       ;   -321321432. ;     -1232342.313    ;    -.312445;

'c'  ;    '\n';
'\\'   ;   '\''  ;    '\?'     ;
'\321';'\2'    ; '\12'    ;
'\xabcde' ;    '\x123312dda'     ;
'\uffff'  ;   '\uaa12'    ;
'\U3123dabc' ;    '\U314575FF' ;

"simple string";
" escaped \" string";
      "escaped char '\\n'\' \"";

"complex escape \123 \32 \443 \\";

"\x85354DBCEE    \102 \uffed \Ufaaaaaad   ";

NULL;

}
// by redleaf23477
const signed int a();
const signed long int a();
const signed long long int a();
const signed short int a();

const unsigned int a(int a, int b);
const unsigned long int a(char *a, void b);
const unsigned long long int a();
const unsigned short int a();

int a();
long int a();
long long int a();
short int a();
signed a();
unsigned a();
float a();
double a();
void a();
const a();
    
const signed int *a();
const signed long int *a();
const signed long long int *a();
const signed short int *a();
    

void foo(
    const signed int a,
    const signed long int a,
    const signed long long int a,
    const signed short int a,
    
    const unsigned int a,
    const unsigned long int a,
    const unsigned long long int a,
    const unsigned short int a,
    
    const int a,
    const long int a,
    const long long int a,
    const short int a,
    
    int a,
    long int a,
    long long int a,
    short int a,
    
    const unsigned int a,
    const unsigned long int a,
    const unsigned long long int a,
    const unsigned short int a,
    
    const signed int a,
    const signed long int a,
    const signed long long int a,
    const signed short int a,
    
    const signed long long a,
    const signed long a,
    const signed char a,
    const signed short a,
    
    signed a,
    unsigned a,
    float a,
    double a,
    void a,
    const a,
    
    const signed int *a,
    const signed long int *a,
    const signed long long int *a,
    const signed short int *a,
    
    const signed long long *a,
    const signed long *a,
    const signed char *a,
    const signed short *a,
    
    const signed int*a,
    const signed long int*a,
    const signed long long int*a,
    const signed short int*a,
    
    const signed long long*a,
    const signed long*a,
    const signed char*a,
    const signed short*a,
    
    const signed int * a,
    const signed long int * a,
    const signed long long int * a,
    const signed short int * a,
    
    const signed long long * a,
    const signed long * a,
    const signed char * a,
    const signed short * a);
// by redleaf23477
void foo(
    const signed int a,
    const signed long int a,
    const signed long long int a,
    const signed short int a,
    
    const unsigned int a,
    const unsigned long int a,
    const unsigned long long int a,
    const unsigned short int a,
    
    const int a,
    const long int a,
    const long long int a,
    const short int a,
    
    int a,
    long int a,
    long long int a,
    short int a,
    
    const unsigned int a,
    const unsigned long int a,
    const unsigned long long int a,
    const unsigned short int a,
    
    const signed int a,
    const signed long int a,
    const signed long long int a,
    const signed short int a,
    
    const signed long long a,
    const signed long a,
    const signed char a,
    const signed short a,
    
    signed a,
    unsigned a,
    float a,
    double a,
    void a,
    const a,
    
    const signed int *a,
    const signed long int *a,
    const signed long long int *a,
    const signed short int *a,
    
    const signed long long *a,
    const signed long *a,
    const signed char *a,
    const signed short *a,
    
    const signed int*a,
    const signed long int*a,
    const signed long long int*a,
    const signed short int*a,
    
    const signed long long*a,
    const signed long*a,
    const signed char*a,
    const signed short*a,
    
    const signed int * a,
    const signed long int * a,
    const signed long long int * a,
    const signed short int * a,
    
    const signed long long * a,
    const signed long * a,
    const signed char * a,
    const signed short * a) {
bar ; { int a = 87; { int a = 87; } if( 878787878 ){ while ( bar = 878787878 >> bar ) if( bar ){ continue;  }else{ if( foo( NULL , 878787878 , NULL , 878787878 ) ){ return bar ; }else{ if( NULL ){ for ( NULL ; bar ; bar ) continue;  }else{ if( NULL ){ break;  }else{ if( ~ NULL ){ (int) 878787878 ; } } } } } }else{ while ( 878787878 ) 878787878 != ! bar && 878787878 = bar ; } int a = 87; } return ; continue;  (int) 878787878 ; break;  bar ; bar < bar ; return 878787878 -- ; return + NULL + NULL - bar ; if( NULL == bar != bar ){ while ( NULL ) if( NULL <= NULL ){ return ; } } { int a = 87; while ( bar ) bar != bar ; int a = 87; int a = 87; int a = 87; switch( NULL - bar ) { case NULL -- : case 878787878 : case - bar <= NULL | NULL / 878787878 : case bar : } { int a = 87; int a = 87; if( bar / + bar ){ break;  } break;  int a = 87; int a = 87; int a = 87; for ( bar * 878787878 ; foo( bar = (int) NULL >> -- ( NULL ) , NULL == bar ++ , -- ( NULL ) ++ , foo( bar , bar , ! ++ 878787878 , bar , arr [ 878787878 ] [ NULL ] [ (int) NULL ] [ (int) NULL ] , 878787878 , bar , ++ bar <= NULL ) / & bar , -- 878787878 , foo( (int) bar , bar <= 878787878 - bar , NULL , 878787878 , ( 878787878 ) , 878787878 % 878787878 ^ 878787878 , bar >> NULL , NULL ) , bar ) ; NULL ++ ) return NULL <= 878787878 -- -- ; } int a = 87; while ( bar - bar ) while ( arr [ bar ] [ foo( 878787878 || bar -- , ++ NULL , ++ bar , ( bar ) , ~ bar ) ] ) { int a = 87; int a = 87; break;  int a = 87; int a = 87; int a = 87; int a = 87; continue;  int a = 87; } } while ( ( (int) NULL ) ) 878787878 ; do break;  while ( arr [ (int) 878787878 ] [ bar || bar ] ) ; do continue;  while ( NULL -- ) ; switch( ~ bar ) { case 878787878 - NULL ++ : case bar <= bar : case - -- 878787878 -- - NULL : case ( foo( bar , bar , bar , 878787878 , NULL , NULL ) ) : default : } for ( foo( NULL , 878787878 ) - ~ (int) 878787878 ; bar ++ ; ++ bar ) continue;  for ( ; ~ bar ; ++ 878787878 = 878787878 * bar ^ (int) + NULL <= NULL ) if( foo( 878787878 | bar == foo( NULL , 878787878 ) , 878787878 + bar , 878787878 ) ++ ){ } bar ; switch( foo( NULL , ! bar , NULL , 878787878 >= NULL , NULL * bar ) ) { case & NULL : case NULL >= arr [ bar * bar ] [ ( NULL ) ] [ 878787878 ] [ - bar % 878787878 ] : case NULL : if( foo() ){ for ( bar && NULL && 878787878 != bar ; ; bar ^ 878787878 ) bar ; }else{ do { int a = 87; for ( arr [ NULL ] [ 878787878 ] [ 878787878 ] != NULL ; bar << foo( bar <= bar ) ; + foo( bar , (int) bar , 878787878 % bar , bar , 878787878 ) ) switch( ( arr [ NULL ] [ NULL ] [ (int) NULL ] [ 878787878 ] ) ) { case (int) NULL << NULL : case bar : continue;  case arr [ bar ] : default : } } while ( NULL ) ; } case ~ 878787878 : if( arr [ 878787878 ] [ 878787878 ] [ bar ] [ 878787878 ] [ NULL ] && bar ){ }else{ } default : break;  } if( ~ bar ++ || ( foo( arr [ 878787878 ] [ bar ] [ NULL ] [ 878787878 ] , NULL == 878787878 ) ) ){ }else{ while ( arr [ NULL ] [ arr [ bar ] [ NULL ] [ bar ] [ NULL ] [ 878787878 ] ] [ 878787878 ] [ foo( bar , 878787878 , bar , 878787878 , bar , NULL ) ] ) continue;  } while ( (int) bar >> 878787878 ) if( ( -- 878787878 && NULL < bar ) ){ }else{ } continue;
}
int main(){
    for(a = 0; a < 0 ; a++)
        a = 3 + 5;
    for(a = 0; a < 0 ; a++){
        a = 3 + 5;
        b = 5 % 2;
    }
    while ( a-- )
    {
        a++;
        --a;
    }
    while(++a)
        a++;
    do{
        a++;
    }while(a--);
    do
        a++;
    while(a--);
    for(x;y;z){}
    for(;;){}
}
// by redleaf23477
const signed int a, b;
const signed long int a, b;
const signed long long int a, b;
const signed short int a, b;

const unsigned int a, b;
const unsigned long int a, b;
const unsigned long long int a, b, d, e, f;
const unsigned short int a, b;

const int a, b;
const long int a, b;
const long long int a, b;
const short int a, b;

int a, b;
long int a, b;
long long int a;
short int a, b;

const unsigned int a, b;
const unsigned long int a, b;
const unsigned long long int a, b, _asdf8Alskdf;
const unsigned short int a, b;

const signed int a, b;
const signed long int a, b;
const signed long long int a, b, ____sdfda_asdf23i47akjfI, _, __, _____;
const signed short int a, b;

const signed long long a, b;
const signed long a, b;
const signed char a, b;
const signed short a, b;

signed a, b;
unsigned a, b;
float a, b;
double a, b;
void a, b;
const a, b;

const signed int *a, b;
const signed long int *a, b;
const signed long long int *a, b;
const signed short int *a, b;

const signed long long *a, b, *a, * as87asdfALFJAisljsijosl;
const signed long *a, b;
const signed char *a, b;
const signed short *a, b;

const signed int*a, b;
const signed long int*a, b;
const signed long long int*a, b;
const signed short int*a, b;

const signed long long*a, b;
const signed long*a, b;
const signed char*a, b;
const signed short*a, b;

const signed int * a, b;
const signed long int * a, b;
const signed long long int * a, b;
const signed short int * a, b;

const signed long long * a, b;
const signed long * a, b;
const signed char * a, b;
const signed short * a, b;
// by redleaf23477
const signed int a = 8787, b = 'c';
const signed long int a, b = 2374;
const signed long long int a = "sdfasfd", b = lsdjklsdfkjsdf;
const signed short int a, b = NULL;

const unsigned int a, b;
const unsigned long int a, b;
const unsigned long long int a, b, d = 2134&asf||('c' + ++a), e, f;
const unsigned short int a, b;

const int a, b;
const long int a, b;
const long long int a, b;
const short int a, b;

int a, b;
long int a, b;
long long int a;
short int a, b;

const unsigned int a, b;
const unsigned long int a, b;
const unsigned long long int a, b, _asdf8Alskdf;
const unsigned short int a, b;

const signed int a, b;
const signed long int a, b;
const signed long long int a, b, ____sdfda_asdf23i47akjfI, _, __, _____;
const signed short int a, b;

const signed long long a, b;
const signed long a, b;
const signed char a, b;
const signed short a, b;

signed a, b;
unsigned a, b;
float a, b;
double a, b;
void a, b;
const a, b;

const signed int *a, b;
const signed long int *a, b;
const signed long long int *a, b;
const signed short int *a, b;

const signed long long *a, b, *a, * as87asdfALFJAisljsijosl;
const signed long *a, b;
const signed char *a, b;
const signed short *a, b;

const signed int*a, b;
const signed long int*a, b;
const signed long long int*a, b;
const signed short int*a, b;

const signed long long*a, b;
const signed long*a, b;
const signed char*a, b;
const signed short*a, b;

const signed int * a, b;
const signed long int * a, b;
const signed long long int * a, b;
const signed short int * a, b;

const signed long long * a, b;
const signed long * a, b;
const signed char * a, b;
const signed short * a, b;
//
/* hihihihi */
/*





*/
// single line comment 1
/// single line comment 2
// escaped char '\n' comment
/// escaped string "\0123" comment
  // com' something
	   		/// tabbed comment "string" \n
					// // marks a single line comment
					// /* also marks comments */ \t \b \n
/* multiline comment */
/* // single line comment
		in multiline env \\ \n */
/* this should\
			\			\	 not be escaped			 \*/
/* string """ in
	 multiline string *

	 */
/** @brief Nothing special
 * @note This is a docstring
 */
/*
#pragma source on

    #pragma       token    off


    #pragma source    off  

#pragma     source on

#pragma token on

*/
int main() {
}
int main() {
  "a"&&"aaaa";
}  
//test_case
int indd(int* sdf);
long* main() {
  (1+(2+3)(3)+(1)); (1+(2+3)+(3)+(1));  (int)a;  (char*)f(); "saca"||+1;
  while(j!=0){      &(123);      int a[b] = { b = c} ;      printf("as\n");      j++;    }
  if(a==b) {      1+2=c;      a[w] = b[2]-c[3];
  } else {
      int a = b = c; -1 && "asdv";  "saca" || +1;  a<<vc>>s;  a+1==b;  -c!=q;  a>=*b;  ~a<=b;  a<=b++-1;
      ++a;  a++;  0;  c%w;  +"ef\n";  -0.1+-"qwfq\n"&acsac|wq;  1+2+3;  1-2-3;  1%2%3;  1&w&e;  s|s|s;  !a;  ~q;
      int* s= &a & &a & &a;   int* addr = 1*2*3;  1/2/3;  int* ptr =  a * *ss * *s, v;
      int a = +1;    a=1;    a+b=1; +6; float a, b, c; char str = 'a'; char* str = "nvoabvoibw\0";
  }
    NULL; int arr[2];  f[2][a];    int arr[2] = {1.1};    if(1){}
    if(1){ 2;     return;        break;        continue;        return 1; } 
    else {  const unsigned long long int * ptr_57=5;  for(1;1;1){}   }
    switch(1){        case 2:    do  { 1;} while (2);    default:   while (2) 1;     default:    }
    int a[0] = {1,{2},{3,4,{5},{6}}}; int y=1; int x[0] = {1, 1, {2},{3,4,{5},{6}},7};
    int e[1][3], p[1][3]; char f[1][4]; float k[1], b[2][3] = {{0,1,2},{3,4,5}};
    const signed var_02=5; int var_42=5; const signed int var_43=5; const * ptr_01=5; 
    const unsigned long long int * ptr_57=5; 
}   

