//expr
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
