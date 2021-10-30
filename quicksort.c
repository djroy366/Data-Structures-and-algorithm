#include<stdio.h>
#include<stdlib.h>

void swap(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
	

int partition(int arr[],int lb,int ub)
{
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	while(start<end)
	{
		while(arr[start]<=pivot)start++;
	 	while(arr[end]>pivot)end--;
		if(start<end)swap(arr[start],arr[end]);
	}
	swap(arr[lb],arr[end]);
	return end;
}

void quicksort(int arr[],int lb,int ub)
{
	if(lb<ub){
		int loc= partition(arr,lb,ub);
		quicksort(arr,lb,loc-1)	;
		quicksort(arr,loc+1,ub);
		}

}

int main()
{
	int arr[]={2,5,6,8,7,98,5,12,45,78,653,21,45};
	int size_arr=sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted Array\n");
	for(int i=0;i<size_arr;i++)  printf("%d\n",arr[i]);
	quicksort(arr,0,size_arr-1);
	printf("sorted Array\n");
	for(int i=0;i<size_arr;i++)  printf("%d\n",arr[i]);

	return 0;
}
