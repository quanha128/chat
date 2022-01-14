def roundSquare(n):
  sum = 0;
  while (n>0):
    digit = n%10
    sum += digit
    n/=10

  if (sum!=10):
    return False;

  for i in range (n+1):
    if(i*i == n):
      return False;
  return True;