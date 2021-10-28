#include<stdio.h>

void merge(int arr[],int l, int mid, int u)
{
	int i,j,k;
	int n1=mid-l+1;
	int n2=u-mid;

	int L[n1],R[n2];

	for(i=0;i<n1;i++)
	L[i]=arr[l+i];
	for(i=0;i<n2;i++)
	R[i]=arr[mid+1+i];
	
	i=0;j=0;k=0;

	while(i<n1 && j< n2){
		if(L[i]<=R[j]){
		  arr[k] = L[i];
		  i++;
		}
		else{
		arr[k]=R[j];
		j++;
		}
		k++;
		}
	while (i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}

	while (j < n2) {
        	arr[k] = R[j];
        	j++;
        	k++;
    }
}


void mergesort(int arr[],int l,int u)
{
	if(l<u){
		int mid = l+(u-l)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,u);
		merge(arr,l,mid,u);
	}
}

void print_array(int arr[],int x)
{	
	int k=0;
	while(k<x)
	{
		printf("\n%d\n",arr[k]);
		k++;
	}
}

int main()
{
	int arr[]={12,54,65,9,7,8};
	int size_arr= sizeof(arr)/sizeof(arr[0]);
	print_array(arr,size_arr);
	mergesort(arr,0,size_arr-1);
	
        printf("\nSorted array is \n");
	print_array(arr,size_arr);


return 0;
}
