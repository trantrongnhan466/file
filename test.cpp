#include<stdio.h>
int main()
{
	int a[]= {1,1,0,0,0,2,2,3,3};
	int flag=0;
	for(int i= flag; i<9;i=flag)
	{
		int dem=1;
		for(int j=flag+1; j<9;j++)
	     {
	     	if(a[i]==a[j])
	     	{
	     		dem++;
			}
			else
			{
				break;
			}
		 }
		if(dem>0)
		{
		   printf("\nSo %d co %d",a[flag],dem);
		   flag=flag+dem;	
		} 
		   
	}

}

