bool isPerfectSquare(int num) {
  if (num == 1)
    return true;

  for (int index = 1; index <= num / 2 && index <= 46340; ++index)
    {
      if (index * index == num)
	return true;
    }

  return false;
}
