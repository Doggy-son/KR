/*функция возводит число в целую степень*/
double get_pow(double b, int p)
{
  double result = 1.0;

  for(; p>0; p--)
      result *= (double)b;

  return result;
}
