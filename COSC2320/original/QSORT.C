void QuickSort(int a[], int n)
{  Qsort(a, 0, n - 1);
}

void Qsort(int a[], int left, int right)
{  int i;
   if (left >= right)
      ;/*do nothing*/
   else
   {  i = Partition(a, left, right);
      Qsort(a, left, i - 1);
      Qsort(a, i + 1, right);
   }
}

int Partition(int a[], int left, int right)
{  int i, j, mid; 
   int pivot, hold; /*these should be the type of the array*/
   mid = (left + right)/2;  pivot = a[mid];
   hold = a[mid];  a[mid] = a[right];  a[right] = hold;
   i = left;  j = right - 1;
   for ( ; ; )
   {  while (a[i] < pivot)
         i++;
      while ((i < j) && (a[j] > pivot))
         j--;
      if (i < j)
      {  hold = a[i];  a[i] = a[j];  a[j] = hold;
         i++;  j--;
      }
      else
         break;
   }
   hold = a[i];  a[i] = a[right];  a[right] = hold;
   return i;
}
