double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int index1 = 0;
  int index2 = 0;
  int totalSize = (nums1Size + nums2Size)/2 + 1;
  int result[totalSize];

  while ((index1 < nums1Size || index2 < nums2Size) && (index1 + index2) < totalSize)
    {
      if (index2 == nums2Size || (index1 < nums1Size && nums1[index1] < nums2[index2]))
        {
	  result[index1 + index2] = nums1[index1];
	  index1++;
        }
      else
        {
	  result[index1 + index2] = nums2[index2];
	  index2++;
        }
    }

  if (!((nums1Size + nums2Size) % 2))
    {
      return (double) (result[totalSize - 1] + result[totalSize -2]) / 2.0;
    }
  return (double) result[totalSize - 1];
}
