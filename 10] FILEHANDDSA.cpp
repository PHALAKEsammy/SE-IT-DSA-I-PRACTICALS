#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student
  {		int roll;
		char name[10];
		char div;
		char add[10];
	};
	class records{
			public:
		student rec;
	  void create();
	  void display();
	  void search();
	  void Delete();
	  void insert();
	  void modify();
  };
void records::create()
  {
	char ans;
	ofstream fout;

	fout.open("studrec.txt",ios::out|ios::binary);
	if(!fout.is_open())
    {
        cout <<"File can not be opened";
        exit(0);
    }
	do
	  {
		cout<<"\nEnter Roll No of Student    : ";
		cin>>rec.roll;
		cout<<"\nEnter a Name of Student     : ";
		cin>>rec.name;
		cout<<"\nEnter a Division of Student : ";
		cin>>rec.div;
		cout<<"\nEnter a Address of Student  : ";
		cin>>rec.add;
		fout.write((char *)&rec,sizeof(rec));
		cout<<"\nDo You Want to Add More Records:'y'for yes ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
	fout.close();
  }
void records::display()
  {
  ifstream fin;
    fin.open("studrec.txt", ios::in | ios::binary);
    if(!fin)  //file not found
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        fin.read((char*)&rec, sizeof(rec));  //read first record
        	cout<<"\nRoll\tName\tDiv\tAddress"; 
        while(!fin.eof())  //read file till  end of file
        {
        	 cout<<"\n"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
       		  fin.read((char *)&rec,sizeof(rec));
             //read next record
        }
    }
    fin.close();
}


void records::search()
  {
  		int r,i=0;
	ifstream fin;
	fin.open("studrec.txt",ios::in|ios::binary);  //open file in reading mode
        bool flag = false;
        cout<<"\nEnter a Roll No: ";
	cin>>r;
if(!fin){
	cout<<"Error";
}
else{
	  //read first record
        while(!fin.eof())  //search till end of file
        {
        	fin.read((char*) &rec ,sizeof(rec));
            if(rec.roll==r)  //if key is equal to correct roll number
            {
                flag = true;  //set flag
               cout<<"\nRecord Found...\n";
			cout<<"\nRoll\tName\tDiv\tAddress";
			cout<<"\n"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
			break;
            }
           
        }
    }
        if(flag==0)  //if roll no. is not found
            cout<<"\nRecord not found !\n";
        fin.close();
    }

    
void records::Delete()
  {
  	 cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    fstream fin("studrec.txt", ios::in | ios::binary);  //open file in read mode
    fstream fout("temp.txt", ios::out | ios::binary);  //create new temp file for temporary data storage
    if(!fin)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        fin.read((char*)&rec, sizeof(rec));
        while(!fin.eof())
        {
            if(rec.roll != rno)  //if current record is not that to be updated
            {
                fout.write((char*)&rec, sizeof(rec));  //write to the temp file
            }
            else  //if current record is that ts to be updated
            {
                cout<<"\nRecord Found and Deleted!\n";
                flag = 1;
            }
            fin.read((char*)&rec, sizeof(rec));  //read next record from the
        }
        fin.close();
        fout.close();
        remove("studrec.txt");
        rename("temp.txt", "studrec.txt");
        if(flag == 0)  //flag remained same then
        {
            cout<<"\nRecord with roll no. "<<rno<<" is not found in the file 'StudentData.dat'\n";
        }
    }
}

void records::insert(){
	cout<<"\nFill student details :\nRoll No. : ";
    cin>>rec.roll;
    cin.ignore();
    fstream fout("studrec.txt", ios::app | ios::binary); //open file in append mode
    fstream fin("studrec.txt", ios::in | ios::binary); //open file in read with different pointer
    student rec1;
    fin.read((char*)&rec1, sizeof(rec1));
    int flag = 1;
    while(!fin.eof())  //read file till end for roll no. validity check
    {
        if(rec1.roll == rec.roll)
        {
            cout<<"\nStudent with roll no. "<<rec.roll<<" already exist !\n";
           flag= 0;
            break;
        }
        else
        {
            fin.read((char*)&rec1, sizeof(rec1));  //read next record
        }
    }
    if(flag == 1)  //if roll no. is unique then only write to the file
    {
        cout<<"\nName : ";
        cin>>rec.name;
        cout<<"\nAddress : ";
        cin>>rec.add;
       cout<<"\nroll : ";
        cin>>rec.roll;
        cout<<"\ndivision : ";
       cin>>rec.div;
       
        fout.write((char*)&rec, sizeof(rec));  //write to the file
        cout<<"\nRecord added successfully to the file !\n";
    }
    fin.close();
}

void records::modify(){
	 cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    ifstream fin;
	fin.open("studrec.txt", ios::in | ios::binary);  //open file in read mode
    ofstream fout;
	fout.open("temp.txt", ios::out | ios::binary);  //create new temp file for temporary data storage
    if(!fin)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        fin.read((char*)&rec, sizeof(rec));
        while(!fin.eof())
        {
            if(rec.roll != rno)  //if current record is not that to be updated
            {
                fout.write((char*)&rec, sizeof(rec));  //write to the temp file
            }
            else  //if current record is that ts to be updated
            {
                cout<<"\nRecord Found !\n";
                flag = 1;
                cout<<"\nFill student details :\nRoll No. : "<<rno;
                rec.roll = rno;
                cin.ignore();
                cout<<"\nName : ";
                cin>>rec.name;
                cout<<"\nAddress : ";
                cin>>rec.add;
               cout<<"\ndivision";
               cin>>rec.div;
                fout.write((char*)&rec, sizeof(rec));  //write to the file
                cout<<"\nRecord updated successfully to the file !\n";  //write updated record to the temp file
            }
            fin.read((char*)&rec, sizeof(rec));  //read next record from the
        }
        fin.close();
        fout.close();
        remove("studrec.txt");
        rename("temp.txt", "studrec.txt");
        if(flag == 0)  //flag remained same then
        {
            cout<<"\nRecord with roll no. "<<rno<<" is not found in the file 'studrec.txt'\n";
        }
    }
}

int main()
  {
	records obj;
	int ch,key;
	char ans;
		cout<<"\n=======================================";
        cout<<"\n||ASSIGNMENT OF FILE HANDLING        ||";
        cout<<"\n=======================================";
        cout<<endl;
	do
	  {
		cout<<"***** Student Information *****";
		cout<<"\n1. Create\n2. Display\n3. Delete\n4. Search\n5. insert\n6. modify\n7. Exit";
		cout<<"\nEnter Your Choice: ";
		cin>>ch;
		switch(ch)
		  {
			case 1: obj.create();
				break;
			case 2:	obj.display();
				break;
			case 3: obj.Delete();
				break;
			case 4:
				obj.search();
				break;
					case 5: obj.insert();
				break;
					case 6: obj.modify();
				break;
			case 7:
				break;
		  }
		cout<<"\nDo You Want to Continue in Main Menu: 'y' for yes ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
return 1;
  }

