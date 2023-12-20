bool isHappy(int n) {
  int nextnum = n;

  do
    {
      int cp = nextnum;
      nextnum = 0;

      while (cp > 0)
        {
	  nextnum += pow(cp % 10, 2);
	  cp /= 10;
        }

      if (nextnum == 1 || nextnum == 7)
	return true;        
      if (nextnum > 1 && nextnum < 10)
	return false;
    } while (nextnum != n);

  return false;
}
