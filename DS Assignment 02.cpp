#include<iostream> 
#include<time.h> 
#include<cstdlib>
#include<fstream>
using namespace std;

//Prototypes
void merge(int arr[],int lb,int mid,int ub);
int MedianOfThreePartition(int arr[],int p, int r);
int Updated_MedianOfThree_Partition(int arr[],int p,int r);

//Global variable (i.e used in Quick-II/III)
int count=0;

//Sorting Algorithms
void Insertion_Sort(int arr[],int size)
{
	for(int i=1;i<size;i++)
	{
		int temp;
		temp=arr[i];
		int j=i-1;
		
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

void merge(int arr[], int lb, int mid, int ub) // lb - lower bound(start)
{                                              // ub - upper bound (end)
   int i,j,k,nl,nr;                            // mid - middle value
   
   nl = mid-lb+1; nr = ub-mid;
   int larr[nl], rarr[nr];
   
   for(i = 0; i<nl; i++)
   {
      larr[i] = arr[lb+i];
   }
   for(j = 0; j<nr; j++)
   {
      rarr[j] = arr[mid+1+j];
   }
   i = 0; j = 0; k = lb;
   
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      arr[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      arr[k] = rarr[j];
      j++; k++;
   }
}
void Merge_Sort(int arr[], int lb, int ub)
{
   if(lb < ub) {
      //int mid = lb+(ub-lb)/2;
      int mid = (lb+ub)/2;
      // Sort first and second arrays
      Merge_Sort(arr, lb, mid);
      Merge_Sort(arr, mid+1, ub);
      merge(arr, lb, mid, ub);
   }
}


int Partition(int arr[],int lb,int ub)
{
	int pivot=arr[lb];  //Random number of array as pivot (i.e first value of array)
	int start=lb;
	int end=ub;
	
	while(start<end)
	{
		while(arr[start]<=pivot)
		{
			start++;
		}
		while(arr[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(arr[start],arr[end]);
		}
	}
	swap(arr[lb],arr[end]);
	return end;
	
}
int Quick_Sort_RandomPivot(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int location=Partition(arr,lb,ub);
		Quick_Sort_RandomPivot(arr,lb,location-1);
		Quick_Sort_RandomPivot(arr,location+1,ub);
	}
}

void Quick_Sort_MiddlePivot(int arr[], int lb, int ub) {

      int start = lb, end = ub;
      int temp;
      int pivot = arr[(lb + ub) / 2];

      /* partition */

      while (start <= end) {

            while (arr[start] < pivot)
            {
                start++;
            }

            while (arr[end] > pivot)
            {
                end--;
            }

            if (start <= end)
            {
                temp=arr[start];
                arr[start]=arr[end];
                arr[end]=temp;
                start++;
                end--;
            }

      }
      /* recursion */

      if (lb < end)
      {
        Quick_Sort_MiddlePivot(arr, lb, end);
      }

      if (start < ub)
      {
        Quick_Sort_MiddlePivot(arr, start, ub);
      }
  }



void Quick_Sort_MedianPivot(int arr[],int start,int end)
{
    int med;
    count++;
    if (end-start<2) 
		return;
    med=MedianOfThreePartition(arr,start,end);
    Quick_Sort_MedianPivot(arr,start,med);
    Quick_Sort_MedianPivot(arr,med,end);
}

int MedianOfThreePartition(int arr[],int p, int r)
{
    int x=arr[p];
	int y=arr[(r-p)/2+p];
	int z=arr[r-1];
	int i=p-1,j=r;
	
    if (y>x && y<z || y>z && y<x )
	{
	 	x=y;
	}
    else if (z>x && z<y || z>y && z<x ) 
	{
		x=z;
	}
    while (1) {
        do  {j--;count++;} while (arr[j] > x);
        do  {i++;count++;} while (arr[i] < x);
        if  (i < j)
        {
        	int temp=arr[i];
        	arr[i]=arr[j];
        	arr[j]=temp;
		}
        else return j+1;
    }
}

void Quick_Sort_UpdatedMedianPivot(int arr[],int start,int end)
{
    int med;
    count++;
    if (end-start<2) 
		return;
    med=Updated_MedianOfThree_Partition(arr,start,end);
    Quick_Sort_UpdatedMedianPivot(arr,start,med);
    Quick_Sort_UpdatedMedianPivot(arr,med,end);
}

int Updated_MedianOfThree_Partition(int arr[],int p, int r)
{
    int x=arr[p];
	int y=arr[(r-p)/2+p];
	int z=arr[r-1];
	int i=p-1,j=r;
	
    if (y>x && y<z || y>z && y<x )
	{
	 	x=y;
	}
    else if (z>x && z<y || z>y && z<x ) 
	{
		x=z;
	}
    while (1) {
        do  {j--;count++;} while (arr[j] > x);
        do  {i++;count++;} while (arr[i] < x);
        if  (i < j)
        {
        	int temp=arr[i];
        	arr[i]=arr[j];
        	arr[j]=temp;
		}
        else return j+1;
    }
}


int main() 
{
	//FILE 1 FOR HANDLING 50 NUMBERS
    ofstream o1("D:\\check1.txt");
	int i; 
	bool arr1[50]={0};
	int s_arr1[50];
	time_t t1; 
	srand((unsigned)time(&t1)); 
	
	cout<<"50 NUMBERS: "<<endl;
	for(i=0;i<50;++i) 
	{ 
	    int r1=rand()%50; 
	    if(!arr1[r1])
	    {
	    	s_arr1[i]=r1;
	    	o1<<r1<<endl;
	    	cout<<s_arr1[i]<<endl;
		}
	    else 
	      i--; 
	    arr1[r1]=1;     
	}
	o1.close(); 
	
	cout<<"\n\n\n\n\n SORTED 50 NUMBERS (INSERTION SORT)"<<endl;
	o1.open("D:\\check1.txt");
	Insertion_Sort(s_arr1,50);
	
	for(int i=0;i<50;i++)
	{
		o1<<s_arr1[i]<<endl;
		cout<<s_arr1[i]<<endl;
	}
	o1.close();
	
	cout<<"\n\n\n\n\n SORTED 50 NUMBERS (MERGE SORT)"<<endl;
	o1.open("D:\\check1.txt");
	Merge_Sort(s_arr1,0,49);
	
	for(int i=0;i<50;i++)
	{
		o1<<s_arr1[i]<<endl;
		cout<<s_arr1[i]<<endl;
	}
	o1.close();
	

	//(QUICK)
	cout<<"\n\n\n\n\n SORTED 50 NUMBERS (QUICK SORT | MIDDLE PIVOT)"<<endl;
	o1.open("D:\\check1.txt");
	Quick_Sort_MiddlePivot(s_arr1,0,49);
	
	for(int i=0;i<50;i++)
	{
		o1<<s_arr1[i]<<endl;
		cout<<s_arr1[i]<<endl;
	}
	o1.close();

	//(QUICK I)
	cout<<"\n\n\n\n\n SORTED 50 NUMBERS (QUICK SORT | RANDOM PIVOT)"<<endl;
	o1.open("D:\\check1.txt");
	Quick_Sort_RandomPivot(s_arr1,0,49);
	
	for(int i=0;i<50;i++)
	{
		o1<<s_arr1[i]<<endl;
		cout<<s_arr1[i]<<endl;
	}
	o1.close();


	//(QUICK II)
	cout<<"\n\n\n\n\n SORTED 50 NUMBERS (QUICK SORT | MEDIAN PIVOT)"<<endl;
	o1.open("D:\\check1.txt");
	Quick_Sort_MedianPivot(s_arr1,0,50);
	
	for(int i=0;i<50;i++)
	{
		o1<<s_arr1[i]<<endl;
		cout<<s_arr1[i]<<endl;
	}
	o1.close();
	
	//(QUICK III)
	cout<<"\n\n\n\n\n SORTED 50 NUMBERS (QUICK SORT | UPDATED MEDIAN PIVOT)"<<endl;
	o1.open("D:\\check1.txt");
	Quick_Sort_UpdatedMedianPivot(s_arr1,0,50);
	
	for(int i=0;i<50;i++)
	{
		o1<<s_arr1[i]<<endl;
		cout<<s_arr1[i]<<endl;
	}
	o1.close();
	
	
	
	//FILE 2 FOR HANDLING 100 NUMBERS
	ofstream o2("D:\\check2.txt");
	bool arr2[100]={0};
	int s_arr2[100];
	time_t t2; 
	srand((unsigned)time(&t2)); 
	
	cout<<"\n\n\n 100 NUMBERS: "<<endl;
	for(i=0;i<100;++i) 
	{ 
	    int r2=rand()%100; 
	    if(!arr2[r2])
	    {
	    	s_arr2[i]=r2;
	    	o2<<r2<<endl;
	    	cout<<s_arr2[i]<<endl;
		}
	    else 
	      i--; 
	    arr2[r2]=1;     
	}
	o2.close();
	
	cout<<"\n\n\n\n\n SORTED 100 NUMBERS (INSERTION SORT)"<<endl;
	o2.open("D:\\check2.txt");
	Insertion_Sort(s_arr2,100);
	
	for(int i=0;i<100;i++)
	{
		o2<<s_arr2[i]<<endl;
		cout<<s_arr2[i]<<endl;
	}
	o2.close();
	
	cout<<"\n\n\n\n\n SORTED 100 NUMBERS (MERGE SORT)"<<endl;
	o2.open("D:\\check2.txt");
	Merge_Sort(s_arr2,0,99);
	
	for(int i=0;i<100;i++)
	{
		o2<<s_arr2[i]<<endl;
		cout<<s_arr2[i]<<endl;
	}
	o2.close();
	
	 //(QUICK)
	cout<<"\n\n\n\n\n SORTED 100 NUMBERS (QUICK SORT | MIDDLE PIVOT)"<<endl;
	o2.open("D:\\check2.txt");
	Quick_Sort_MiddlePivot(s_arr2,0,99);
	
	for(int i=0;i<100;i++)
	{
		o2<<s_arr2[i]<<endl;
		cout<<s_arr2[i]<<endl;
	}
	o2.close();
	
	// (QUICK I)
	cout<<"\n\n\n\n\n SORTED 100 NUMBERS (QUICK SORT | RANDOM PIVOT)"<<endl;
	o2.open("D:\\check2.txt");
	Quick_Sort_RandomPivot(s_arr2,0,99);
	
	for(int i=0;i<100;i++)
	{
		o2<<s_arr2[i]<<endl;
		cout<<s_arr2[i]<<endl;
	}
	o2.close();
	

	//(QUICK II)
	cout<<"\n\n\n\n\n SORTED 100 NUMBERS (QUICK SORT | MEDIAN PIVOT)"<<endl;
	o2.open("D:\\check2.txt");
	Quick_Sort_MedianPivot(s_arr2,0,100);
	
	for(int i=0;i<100;i++)
	{
		o2<<s_arr2[i]<<endl;
		cout<<s_arr2[i]<<endl;
	}
	o2.close();
	
    //(QUICK III)
	cout<<"\n\n\n\n\n SORTED 100 NUMBERS (QUICK SORT | UPDATED MEDIAN PIVOT)"<<endl;
	o2.open("D:\\check2.txt");
	Quick_Sort_UpdatedMedianPivot(s_arr2,0,100);
	
	for(int i=0;i<100;i++)
	{
		o2<<s_arr2[i]<<endl;
		cout<<s_arr2[i]<<endl;
	}
	o2.close();
	

	
	//FILE 3 FOR HANDLING 200 NUMBERS
	ofstream o3("D:\\check3.txt");
	bool arr3[200]={0};
	int s_arr3[200];
	time_t t3; 
	srand((unsigned)time(&t3)); 
	
	cout<<"\n\n\n 200 NUMBERS: "<<endl;
	for(i=0;i<200;++i) 
	{ 
	    int r3=rand()%200; 
	    if(!arr3[r3])
	    {
	    	s_arr3[i]=r3;
	    	o3<<r3<<endl;
	    	cout<<s_arr3[i]<<endl;
		}
	    else 
	      i--; 
	    arr3[r3]=1;     
	}
	o3.close(); 
	
	cout<<"\n\n\n\n\n SORTED 200 NUMBERS (INSERTION SORT)"<<endl;
	o3.open("D:\\check3.txt");
	Insertion_Sort(s_arr3,200);
	
	for(int i=0;i<200;i++)
	{
		o3<<s_arr3[i]<<endl;
		cout<<s_arr3[i]<<endl;
	}
	o3.close();
	
	cout<<"\n\n\n\n\n SORTED 200 NUMBERS (MERGE SORT)"<<endl;
	o3.open("D:\\check3.txt");
	Merge_Sort(s_arr3,0,199);
	
	for(int i=0;i<200;i++)
	{
		o3<<s_arr3[i]<<endl;
		cout<<s_arr3[i]<<endl;
	}
	o3.close();
	
	cout<<"\n\n\n\n\n SORTED 200 NUMBERS (QUICK SORT | MIDDLE PIVOT)"<<endl;
	o3.open("D:\\check3.txt");
	Quick_Sort_MiddlePivot(s_arr3,0,199);
	
	for(int i=0;i<200;i++)
	{
		o3<<s_arr3[i]<<endl;
		cout<<s_arr3[i]<<endl;
	}
	o3.close();
	
	//QUICK I
	cout<<"\n\n\n\n\n SORTED 200 NUMBERS (QUICK SORT | RANDOM PIVOT)"<<endl;
	o3.open("D:\\check3.txt");
	Quick_Sort_RandomPivot(s_arr3,0,199);
	
	for(int i=0;i<200;i++)
	{
		o3<<s_arr3[i]<<endl;
		cout<<s_arr3[i]<<endl;
	}
	o3.close();
	
	 //QUICK II
	cout<<"\n\n\n\n\n SORTED 200 NUMBERS (QUICK SORT | MEDIAN PIVOT)"<<endl;
	o3.open("D:\\check3.txt");
	Quick_Sort_MedianPivot(s_arr3,0,200);
	
	for(int i=0;i<200;i++)
	{
		o3<<s_arr3[i]<<endl;
		cout<<s_arr3[i]<<endl;
	}
	o3.close();
	
	// (QUICK III)
	cout<<"\n\n\n\n\n SORTED 200 NUMBERS (QUICK SORT | UPDATED MEDIAN PIVOT)"<<endl;
	o3.open("D:\\check3.txt");
	Quick_Sort_UpdatedMedianPivot(s_arr3,0,200);
	
	for(int i=0;i<200;i++)
	{
		o3<<s_arr3[i]<<endl;
		cout<<s_arr3[i]<<endl;
	}
	o3.close();
	
	
	//FILE 4 FOR HANDLING 300 NUMBERS
	ofstream o4("D:\\check4.txt");
	bool arr4[300]={0};
	int s_arr4[300];
	time_t t4; 
	srand((unsigned)time(&t4)); 
	
	cout<<"\n\n\n 300 NUMBERS: "<<endl;
	for(i=0;i<300;++i) 
	{ 
	    int r4=rand()%300; 
	    if(!arr4[r4])
	    {
	    	s_arr4[i]=r4;
	    	o4<<r4<<endl;
	    	cout<<s_arr4[i]<<endl;
		}
	    else 
	      i--; 
	    arr4[r4]=1;     
	}
	o4.close(); 
	
	cout<<"\n\n\n\n\n SORTED 300 NUMBERS (INSERTION SORT)"<<endl;
	o4.open("D:\\check4.txt");
	Insertion_Sort(s_arr4,300);
	
	for(int i=0;i<300;i++)
	{
		o4<<s_arr4[i]<<endl;
		cout<<s_arr4[i]<<endl;
	}
	o4.close();
	
	cout<<"\n\n\n\n\n SORTED 300 NUMBERS (MERGE SORT)"<<endl;
	o4.open("D:\\check4.txt");
	Merge_Sort(s_arr4,0,299);
	
	for(int i=0;i<300;i++)
	{
		o4<<s_arr4[i]<<endl;
		cout<<s_arr4[i]<<endl;
	}
	o4.close();
	
	//QUICK
	cout<<"\n\n\n\n\n SORTED 300 NUMBERS (QUICK SORT | MIDDLE PIVOT)"<<endl;
	o4.open("D:\\check4.txt");
	Quick_Sort_MiddlePivot(s_arr4,0,299);
	
	for(int i=0;i<300;i++)
	{
		o4<<s_arr4[i]<<endl;
		cout<<s_arr4[i]<<endl;
	}
	o4.close();
	
	//QUICK I
	cout<<"\n\n\n\n\n SORTED 300 NUMBERS (QUICK SORT | RANDOM PIVOT)"<<endl;
	o4.open("D:\\check4.txt");
	Quick_Sort_RandomPivot(s_arr4,0,299);
	
	for(int i=0;i<300;i++)
	{
		o4<<s_arr4[i]<<endl;
		cout<<s_arr4[i]<<endl;
	}
	o4.close();
	
	// QUICK II
	cout<<"\n\n\n\n\n SORTED 300 NUMBERS (QUICK SORT | MEDIAN PIVOT)"<<endl;
	o4.open("D:\\check4.txt");
	Quick_Sort_MedianPivot(s_arr4,0,300);
	
	for(int i=0;i<300;i++)
	{
		o4<<s_arr4[i]<<endl;
		cout<<s_arr4[i]<<endl;
	}
	o4.close();
	
	// (QUICK III)
	cout<<"\n\n\n\n\n SORTED 300 NUMBERS (QUICK SORT | UPDATED MEDIAN PIVOT)"<<endl;
	o4.open("D:\\check4.txt");
	Quick_Sort_UpdatedMedianPivot(s_arr4,0,300);
	
	for(int i=0;i<300;i++)
	{
		o4<<s_arr4[i]<<endl;
		cout<<s_arr4[i]<<endl;
	}
	o4.close();
	
	//FILE 5 HANDLING 400 NUMBERS
	ofstream o5("D:\\check5.txt");
	bool arr5[400]={0};
	int s_arr5[400];
	time_t t5; 
	srand((unsigned)time(&t5)); 
	
	cout<<"\n\n\n 400 NUMBERS: "<<endl;
	for(i=0;i<400;++i) 
	{ 
	    int r5=rand()%400; 
	    if(!arr5[r5])
	    {
	    	s_arr5[i]=r5;
	    	o5<<r5<<endl;
	    	cout<<s_arr5[i]<<endl;
		}
	    else 
	      i--; 
	    arr5[r5]=1;     
	}
	o5.close();
	
	cout<<"\n\n\n\n\n SORTED 400 NUMBERS (INSERTION SORT)"<<endl;
	o5.open("D:\\check5.txt");
	Insertion_Sort(s_arr5,400);
	
	for(int i=0;i<400;i++)
	{
		o4<<s_arr5[i]<<endl;
		cout<<s_arr5[i]<<endl;
	}
	o5.close();
	
	cout<<"\n\n\n\n\n SORTED 400 NUMBERS (MERGE SORT)"<<endl;
	o5.open("D:\\check5.txt");
	Merge_Sort(s_arr5,0,399);
	
	for(int i=0;i<400;i++)
	{
		o5<<s_arr5[i]<<endl;
		cout<<s_arr5[i]<<endl;
	}
	o5.close(); 
	
	
	//QUICK
	cout<<"\n\n\n\n\n SORTED 400 NUMBERS (QUICK SORT | MIDDLE PIVOT)"<<endl;
	o5.open("D:\\check5.txt");
	Quick_Sort_MiddlePivot(s_arr5,0,399);
	
	for(int i=0;i<400;i++)
	{
		o5<<s_arr5[i]<<endl;
		cout<<s_arr5[i]<<endl;
	}
	o5.close();
	
	//QUICK I
	cout<<"\n\n\n\n\n SORTED 400 NUMBERS (QUICK SORT | RANDOM PIVOT)"<<endl;
	o5.open("D:\\check5.txt");
	Quick_Sort_RandomPivot(s_arr5,0,399);
	
	for(int i=0;i<400;i++)
	{
		o5<<s_arr5[i]<<endl;
		cout<<s_arr5[i]<<endl;
	}
	o5.close();
	
	// QUICK II
	cout<<"\n\n\n\n\n SORTED 400 NUMBERS (QUICK SORT | MEDIAN PIVOT)"<<endl;
	o5.open("D:\\check5.txt");
	Quick_Sort_MedianPivot(s_arr5,0,400);
	
	for(int i=0;i<400;i++)
	{
		o5<<s_arr5[i]<<endl;
		cout<<s_arr5[i]<<endl;
	}
	o5.close();
	
	// (QUICK III)
	cout<<"\n\n\n\n\n SORTED 400 NUMBERS (QUICK SORT | UPDATED MEDIAN PIVOT)"<<endl;
	o5.open("D:\\check5.txt");
	Quick_Sort_UpdatedMedianPivot(s_arr5,0,400);
	
	for(int i=0;i<400;i++)
	{
		o5<<s_arr5[i]<<endl;
		cout<<s_arr5[i]<<endl;
	}
	o5.close();
	
	
	//FILE 6 FOR HANDLING 500 NUMBERS
	ofstream o6("D:\\check6.txt");
	bool arr6[500]={0};
	int s_arr6[500];
	time_t t6; 
	srand((unsigned)time(&t6)); 
	
	//cout<<"\n\n\n 500 NUMBERS: "<<endl;
	for(i=0;i<500;++i) 
	{ 
	    int r6=rand()%500; 
	    if(!arr6[r6])
	    {
	    	s_arr6[i]=r6;
	    	o6<<r6<<endl;
	    	//cout<<s_arr6[i]<<endl;
		}
	    else 
	      i--; 
	    arr6[r6]=1;     
	}
	o6.close();
	
	//cout<<"\n\n\n\n\n SORTED 500 NUMBERS (INSERTION SORT)"<<endl;
	o6.open("D:\\check6.txt");
	Insertion_Sort(s_arr6,500);
	
	for(int i=0;i<500;i++)
	{
		o6<<s_arr6[i]<<endl;
		//cout<<s_arr6[i]<<endl;
	}
	o6.close();
	
	//cout<<"\n\n\n\n\n SORTED 500 NUMBERS (MERGE SORT)"<<endl;
	o6.open("D:\\check6.txt");
	Merge_Sort(s_arr6,0,499);
	
	for(int i=0;i<500;i++)
	{
		o6<<s_arr6[i]<<endl;
		//cout<<s_arr6[i]<<endl;
	}
	o6.close();
	
	//QUICK
	//cout<<"\n\n\n\n\n SORTED 500 NUMBERS (QUICK SORT | MIDDLE PIVOT)"<<endl;
	o6.open("D:\\check6.txt");
	Quick_Sort_MiddlePivot(s_arr6,0,499);
	
	for(int i=0;i<500;i++)
	{
		o6<<s_arr6[i]<<endl;
		//cout<<s_arr6[i]<<endl;
	}
	o6.close();
	
	//QUICK I
	//cout<<"\n\n\n\n\n SORTED 500 NUMBERS (QUICK SORT | RANDOM PIVOT)"<<endl;
	o6.open("D:\\check6.txt");
	Quick_Sort_RandomPivot(s_arr6,0,499);
	
	for(int i=0;i<500;i++)
	{
		o6<<s_arr6[i]<<endl;
		//cout<<s_arr6[i]<<endl;
	}
	o6.close();
	
	 //QUICK II
	//cout<<"\n\n\n\n\n SORTED 500 NUMBERS (QUICK SORT | MEDIAN PIVOT)"<<endl;
	o6.open("D:\\check6.txt");
	Quick_Sort_MedianPivot(s_arr6,0,500);
	
	for(int i=0;i<500;i++)
	{
		o6<<s_arr6[i]<<endl;
		//cout<<s_arr6[i]<<endl;
	}
	o6.close();
	
	// (QUICK III)
	//cout<<"\n\n\n\n\n SORTED 500 NUMBERS (QUICK SORT | UPDATED MEDIAN PIVOT)"<<endl;
	o6.open("D:\\check6.txt");
	Quick_Sort_UpdatedMedianPivot(s_arr6,0,500);
	
	for(int i=0;i<500;i++)
	{
		o6<<s_arr6[i]<<endl;
		//cout<<s_arr6[i]<<endl;
	}
	o6.close(); 
	
	
	//FILE 7 FOR HANDLING 1000 NUMBERS
	ofstream o7("D:\\check7.txt");
	bool arr7[1000]={0};
	int s_arr7[1000];
	time_t t7; 
	srand((unsigned)time(&t7)); 
	
	//cout<<"\n\n\n 1000 NUMBERS: "<<endl;
	for(i=0;i<1000;++i) 
	{ 
	    int r7=rand()%1000; 
	    if(!arr7[r7])
	    {
	    	s_arr7[i]=r7;
	    	o7<<r7<<endl;
	    	//cout<<s_arr7[i]<<endl;
		}
	    else 
	      i--; 
	    arr7[r7]=1;     
	}
	o7.close();
	
	//cout<<"\n\n\n\n\n SORTED 1000 NUMBERS (INSERTION SORT)"<<endl;
	o7.open("D:\\check7.txt");
	Insertion_Sort(s_arr7,1000);
	
	for(int i=0;i<1000;i++)
	{
		o7<<s_arr7[i]<<endl;
		//cout<<s_arr7[i]<<endl;
	}
	o7.close();
	
	//cout<<"\n\n\n\n\n SORTED 1000 NUMBERS (MERGE SORT)"<<endl;
	o7.open("D:\\check7.txt");
	Merge_Sort(s_arr7,0,999);
	
	for(int i=0;i<1000;i++)
	{
		o7<<s_arr7[i]<<endl;
		//cout<<s_arr7[i]<<endl;
	}
	o7.close();
	
	//QUICK
	//cout<<"\n\n\n\n\n SORTED 1000 NUMBERS (QUICK SORT | MIDDLE PIVOT)"<<endl;
	o7.open("D:\\check7.txt");
	Quick_Sort_MiddlePivot(s_arr7,0,999);
	
	for(int i=0;i<1000;i++)
	{
		o7<<s_arr7[i]<<endl;
		//cout<<s_arr7[i]<<endl;
	}
	o7.close();
	
	//QUICK I
	//cout<<"\n\n\n\n\n SORTED 1000 NUMBERS (QUICK SORT | RANDOM PIVOT)"<<endl;
	o7.open("D:\\check7.txt");
	Quick_Sort_RandomPivot(s_arr7,0,999);
	
	for(int i=0;i<1000;i++)
	{
		o7<<s_arr7[i]<<endl;
		//cout<<s_arr7[i]<<endl;
	}
	o7.close();
	
	
	//QUICK II
	//cout<<"\n\n\n\n\n SORTED 1000 NUMBERS (QUICK SORT | MEDIAN PIVOT)"<<endl;
	o7.open("D:\\check7.txt");
	Quick_Sort_MedianPivot(s_arr7,0,1000);
	
	for(int i=0;i<1000;i++)
	{
		o7<<s_arr7[i]<<endl;
		//cout<<s_arr7[i]<<endl;
	}
	o7.close();
	
	// (QUICK III)
	//cout<<"\n\n\n\n\n SORTED 1000 NUMBERS (QUICK SORT | UPDATED MEDIAN PIVOT)"<<endl;
	o7.open("D:\\check7.txt");
	Quick_Sort_UpdatedMedianPivot(s_arr7,0,1000);
	
	for(int i=0;i<1000;i++)
	{
		o7<<s_arr7[i]<<endl;
		//cout<<s_arr7[i]<<endl;
	}
	o7.close();  
	
} 
