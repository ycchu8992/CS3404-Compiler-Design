11:#pragma source on										   |	5:#pragma source on
12:#pragma token on										   |	6:#pragma token on
13:int main(const int argc, const char ** argv) {						   |	7:int main(const int argc, const char ** argv) {
14:  /* Hope the stack can survive this call (finger-crossed x) */				   |	8:  /* Hope the stack can survive this call (finger-crossed x) */
#macro:__LINE__											   |	#id:__LINE__
15:  const int ret = printf("Call factorial(%d) \100 line (%d)\n", factorial(atoi(argv[1])), __L   |	9:  const int ret = printf("Call factorial(%d) \100 line (%d)\n", factorial(atoi(argv[1])), __LI
16:  return ret;										   |	10:  return ret;
17:};												   |	11:};
18:												   |	12:
