/* Consider a student database of SEIT class
(at least 15 records). 
Database contains different fields of every
student like Roll No, Name and SGPA.
(array ofstructure). */
#include <iostream>
using namespace std;

 struct s{
   string name;
   int roll;
   float SGPA;
};
 class student{
   int n;
   struct s stu[20];
   public:
   void getinfo();
   void sort();
   void inssort();
   int searchName();
   int  quickSort(int left,int right);
   void toppers ();
   int  partition(int left,int right);
   void search_SGPA();
    int num()
   {
      return n;
   }   
   void display();
   
};
 
  void student :: getinfo()
   {
      
      cout<<"Enter the number of students in class ";
      cin>>n;
      for(int i=0;i<n;i++)
      {
	  cout<<"Enter the Name:  ";
	  cin>>stu[i].name;
	  cout<<"Enter the Roll no:  ";
	  cin>>stu[i].roll;
	  cout<<"Enter the SGPA:  ";
	  cin>>stu[i].SGPA;
	  cout<<endl;
      }
   }

  void student :: sort ()
   { struct s temp;
      for(int i=0;i<n-1;i++)
      {
         for(int j=0;j<n-1;j++)
         {
            if (stu[j].roll > stu[j+1].roll)
            {
               
               temp=stu[j];
               stu[j]=stu[j+1];
               stu[j+1]=temp;
            }
         }
      }
      cout<<"List of students according to roll no in ascending order=>:"<<endl;
   }
   
   void student ::inssort()
   {
   int j;
   struct s key;
   
      for(int i=1;i<n;i++)
      {
         key=stu[i];
         j=i-1;
         while (j>=0 && stu[j].name>key.name)
         {	
               stu[j+1]=stu[j];
               j=j-1;
         }
         stu[j+1] =key;
      }
       cout<<"List of students according to name in alphabetical order=>:"<<endl;
   }
   int student::searchName()
{
	int flag=0,left=0,right=(n-1);
	string check;
	cout<<"Enter the Name of the Student to check = ";
	cin>>check;
	
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(stu[mid].name==check)
		{
		    cout<<"Element found at"<<mid<<endl;
			flag=1;
			break;
		}
		if(stu[mid].name>check)
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	if(flag==0)
	{
		cout<<" Element is not found "<<endl;
		return 0;
	}
	return 0;
}
int student::partition(int left,int right)
{
	int temp,i=left,j=right-1;
	float pivot=stu[right].SGPA;
	
	while(i<=j)
	{
		while(stu[i].SGPA<pivot)
		{	
			i=i+1;
		}
		
		while(j>0 && stu[j].SGPA>pivot)	
		{		
			j=j-1;
		}
			
		if(i<j)
		{
			swap(stu[i].SGPA,stu[j].SGPA);
		}
		j=j-1;
	}
	swap(stu[i].SGPA,stu[right].SGPA);
	
	return i;
}
int student::quickSort(int left,int right)
{
	if(left>=right)
	{
		return 0;
	}
	
	else
	{
		float p=partition(left,right);
		quickSort(left,p-1);
		quickSort(p+1,right);
		
		return 0;	
	}
	cout << endl << " List of 10 toppers : " << endl;	
}
void student::toppers ()
{
  for (int i = 0; i < 10; i++)
    {
      cout << stu[i].name << endl;
      cout << stu[i].roll << endl;
      cout << stu[i].SGPA << endl;

    }
}
 void student::search_SGPA()
{
	int flag=0,i;
	float check;
	cout<<"Enter the SGPA of the Student to Search = ";
	cin>>check;
	
	cout<<"The Students are : "<<endl<<endl;
	for(i=0;i<n;i++)
	{
		if(check==stu[i].SGPA)
		{
			cout<<"Name = "<<stu[i].name<<" "<<endl;
			cout<<"Roll No = "<<stu[i].roll<<" "<<endl;
			cout<<"SGPA = "<<stu[i].SGPA<<" "<<endl<<endl;
			flag++;
		}
		
	}
	if(flag==0)
		{
			cout<<" There is no student with this SGPA "<<endl<<endl;
		}
	cout<<endl;
}

  void student :: display()
   {
      for(int i=0;i<n;i++)
      {
         cout<<"Name: "<<stu[i].name<<endl;
         cout<<"Roll NO: "<<stu[i].roll<<endl;
         cout<<"SGPA: "<<stu[i].SGPA<<endl;
         cout<<endl;
      }
     
     /* cout<<"\n------Students Details---------\n";
      cout<<"\n\tStudent_Name"<<"  "<<"Roll No"<<"  "<<" SGPA";
      for(int i=0;i<n;i++)
      {
         
         
         cout<<"\n\t"<<stu[i].name<<"           "<<stu[i].roll<<"     "<<stu[i].SGPA<<endl;
      }*/
   }
   

int main()
{
   student s1;
   int choice;
   cout<<" <<< Program to Display the Data of the Students >>> "<<endl;
   
   s1.getinfo();
   cout<<"*** Program to Display the Sortings *** "<<endl;
  
   //s1.getdata();

   while(1)
   {
   
                cout<<"***Enter the choice as follows***"<<endl;
                cout<<"1: Sort Data by roll no"<<endl;
                cout<<"2: Sort Data by name"<<endl;
                cout<<"3: Search by Name"<<endl;
                cout<<"4: First 10 toppers"<<endl;
                cout<<"5: Search by SGPA"<<endl;
                cout<<"6: Exit the Program"<<endl;
  		cout<<"Enter the Operation to be Performed = ";
   		cin>>choice;
   		cout<<endl;
 
		if(choice==6)
     		{
  			cout<<" *** Program Exited Successfully *** "<<endl<<endl;
 			break;
   
 		}
 		else
 		{
 			switch (choice)
 			{
  
      				case 1:
      				s1.sort();
      				s1.display();
      				break;
      
				case 2:
			        s1.inssort();
		 	        s1.display();
			        break;
      
			        case 3:
			        s1.searchName();
			        break;
			      
			        case 4:
			        s1.quickSort(0, s1.num());
			        s1.toppers();
			        break;	
      
			        case 5:
		                s1.search_SGPA();
			        break;
                                default:
                                cout<<"Invalid Input"<<endl;
   			 }
                }
  }
  //s1.display();
  return 0;
  	
}

