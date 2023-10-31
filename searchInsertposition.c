#include <stdio.h>
int searchInsert(int* arr, int arraySize, int target){
  int left = 0;
 int  right = arraySize - 1;
  while(left <= right){
  int mid = left + (right - left) / 2;
  if(arr[mid] == target)
  {
      return mid;
  }
  else if(arr[mid] < target)
  left = mid +1;
  else
  right = mid - 1;
  }
  return left;
}
int main() {
    int arr[] = {1,3,4,5,7,9};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int n = 5;
    int result = searchInsert(arr,arraySize,n);
    
    printf("%d",result);

    return 0;
}