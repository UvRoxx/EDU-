#include<iostream>
#include<string>
using namespace std;
//---------------------
float subnm,submarks[10],promarks,hwmarks,totmarks=0,bst,wst,tot1marks;//marks
string sname, status, title[5]={"Phd","Masters","Bachelors","CGEP","HIGH-SCHOOL"};
int age, expage;
float attendance,totdays=1,medlev,latecoming,udlev;//Attendance and Experience
int qual, itskill, stskill;//Skills
int eventp,wins,parti;//Event Participation
float edumarks,eduattendance,eduageexp,eduextra,eduskills;//5 Main EDU integers
//---------------------


void access();
void accept();
void display();
void eduplus();
int main()
{
	int ch;
	cout << "\n\t----------- WELCOME TO EDU + -----------\n";
	bk:
	cout << "\nEnter (1) To Add New Record\nEnter (2) To Access Existing Record\nEnter (3) To Exit\nEnter Choice:"; cin >> ch;
	switch(ch)
	{ 
	case 1:accept(); break;
	case 2:access(); break;
	case 3:exit(0);
	default:cout << "\nInvalid Input\n"; system("pause"); goto bk;
	}
	
}

void accept()
{


	cout << "\nEnter Student Name:";
	cin>>sname;

	cout << "\n\t----MARKS----";
re:
	cout << "\nEnter Number Of Subjcts(1-10):"; cin >> subnm;
	if (subnm > 10 || subnm < 1) { goto re; }
	for (int i = 0; i < subnm; i++)
	{
		cout << "\nEnter Marks For Subject (" << i + 1 << ")[0-100]:";
		cin >> submarks[i];
		if (i == 0)
		{
			bst = submarks[i];
			wst = submarks[i];
		}

		if (submarks[i] > bst)
		{
			bst = submarks[i];
		}
		else if (submarks[i] < wst)
		{
			wst = submarks[i];
		}
		tot1marks = tot1marks + submarks[i];




	}
	hwb:
		cout << "\nEnter Marks For Home-Work[0-100]:"; cin >> hwmarks;
		if (hwmarks < 0) { goto hwb; }

		totmarks = hwmarks + tot1marks;

	prob:
		cout << "\nEnter Project Marks[0-100]:"; cin >> promarks;
		if (promarks < 0 || promarks>100) { goto prob; }
		totmarks = promarks + totmarks;
	
	//--------------------------------------------------
ageb:
	cout << "\n\t----AGE-EXPERIENCE----";
	cout << "\nEnter Age:";
	if (age < 0) { goto ageb; }
	cin >> age;

expb:
	cout << "\nEnter Years Of Work Experience:";
	cin >> expage;
	if (age<0||age>99) { goto expb; }

		//--------------------------------------------------
		cout << "\n\t----ATTENDANCE----";
		atdb:
		cout << "\nEnter Total Days Of Attendance(Max 365):";
		cin >> totdays;
		if (totdays > 365 || totdays < 1) { goto atdb; }
		
		mlevb:
		cout << "\nEnter Number Of Medical Leaves:";
		cin >> medlev;
		if (medlev > totdays) { goto mlevb; }
	
		ulevb:
		cout << "\nEnter The Number Of Undefined Absences:";
		cin >> udlev;
		if (udlev > totdays) { goto ulevb; }

		lcb:
		cout << "\nEnter Number Of Late Comings:";
		cin >> latecoming;
		if (latecoming > totdays) { goto lcb; }
		attendance = totdays - ((medlev*1.5)+(udlev*2)+(0.5*latecoming));
		//-----------------------------------------------
		cout << "\n\t----SKILLS-ACQUIRED---- ";
		b:
		cout <<"\nSELECT YOUR QUALIFICATION:";
		cout << "\n(1)Phd\n(2)Masters\n(3)Bachelors\n(4)CGEP\n(5)HIGH-SCHOOL";
		cout << "\nEnter Your Choice"; cin >> qual;
		if (qual > 5 || qual < 1) { goto b; }
		stb:
		cout << "\nEnter Number Of Self Taught Skills[1-10]:";
		cin >>stskill;
		if (stskill > 10) { goto stb; }
		itb:
		cout << "\nEnter The Number Of Institute Taught Skills[1-10]:";
		cin >>itskill;
		if (itskill > 10) { goto itb; }
		//----------------------------------------------
		cout << "\n\t----Extra------";
		cout << "\nEnter The Number Of Events You Have Participated:";
		cin >> eventp;
		winb:
		cout << "\nEnter The Number Of Events You Won:";
		cin >> wins;
		if (wins > eventp) { goto winb; }
		parti = eventp - wins;
		display();
}


void display()

{
	system("cls");
	cout << "\n<------------------------------GRADE-SHEET--------------------------->";
	cout << "\nName:"<<sname<<"\tAge:"<<age<<"\tQualification:"<<title[qual-1]<<"\n\n";
	for (int i = 0; i < subnm; i++)
	{
		if (i > 0) {cout<<"\t";}
		cout << "Marks In Subject (" << i + 1 << ")" << "="<<submarks[i];
		if (i == 2||i==5)
		{
			cout << "\n";
		}
		
	}
	cout << "\n\nMarks In Homework:"<<hwmarks<<"\tMarks In Projects:"<<promarks<<"\tTotal Score:"<<tot1marks;
	cout << "\n\nAttendance:"<<attendance<<"\tMedical Leaves:"<<medlev<<"\tUndefined Leaves:"<<udlev<<"\n\nLate Coming:"<<latecoming;
	cout << "\nEvents Participated In:"<<eventp<<"\nEvents Won"<<wins;
	cout << "\n<------------------------------------------------------------------->\n";
	cout << "\nBest Scoring Subject Grades:"<< bst<<"\n\nWorst Scoring Grades:"<<wst << "\n-------------------------------------------------------------------\n"<<"\nYour EDU+ Score Is Ready.\n";
	system("pause");
	
	eduplus();
}

void eduplus()
{
	//-------Marks------
	float marks = subnm * 100;
	edumarks=tot1marks*100/marks;
	edumarks = edumarks / 2;
	edumarks = ((edumarks + (hwmarks / 4) + (promarks / 4)))/100;
	cout << "\nEDU+ In Marks:" << edumarks;
	//-----------------------

	
	//--------Age and Experience------
	if (age < 19 && expage==3)
	{
		eduageexp = 0.5;
	}
	else if (age < 19 && expage<3)
	{
		eduageexp = 0.2;
	}


	if (age < 31 && age>18)
	{
		if (age - expage == 15)
		{
			eduageexp = 1;
		}
		
		else
		{
			eduageexp = 0.7;
		}
	}
	

	
	if (age < 99 )
	{
		if (expage >= 35)
		{
			eduageexp = 0.8;
		}
		else
		{
			eduageexp = 0.5;
		}
	}
	cout << "\nEDU+ In Age And Experience:" << eduageexp;

	//--------------ATTENDANCE----------
	eduattendance=((attendance)/totdays);
	
	
	cout << "\nEDU+ In Attendance:" << eduattendance;
	//----------------------------


	//-----------SKILLS-ACQUIRED-------
	eduskills = ((6 - qual) + stskill + itskill);
	eduskills = (eduskills * 4);
	eduskills = eduskills / 100;
	cout << "\nEDU+ In Skills:" << eduskills;
	//---------------------------------
	
	//----------EVENT-PARTICIAPTION----------
	if (wins >=(eventp)/2)
	{
		eduextra = 1;
	}
	else if (wins >= (eventp) / 3)
	{
		eduextra = 0.8;
	}
	else if (wins >= (eventp) / 4)
	{
		eduextra = 0.6;
	}
	else if (wins >= (eventp) / 6)
	{
		eduextra = 0.4;
	}

	else if (wins >= (eventp) / 8)
	{
		eduextra = 0.2;
	}
	else
	{
		eduextra = 0;
	}
	cout << "\nEDU+ In Extracarricular Participation:" << eduextra;
	//--------------------------------------
	cout << "\nYour Total EDU+ Score Is:" << eduageexp + eduattendance + eduextra + edumarks + eduskills<<"";
	system("pause");

}


void access()
{
	system("cls");
	cout << "\n<------------------------------GRADE-SHEET--------------------------->";
	cout << "\nName:Student One\tAge:19\tQualification:Phd\n\n";
	cout << "Marks In Subject (1)=75\tMarks In Subject (2)=55\tMarks In Subject (3)=65";
	cout << "\n\nMarks In Homework:66\tMarks In Projects:50\tTotal Score:311";
	cout << "\n\nAttendance:180\tMedical Leaves:20\tUndefined Leaves:5\tLate Coming:5";
	cout << "\nEvents Participated In:4 \nEvents Won:2";
	cout << "\n<------------------------------------------------------------------->\n";
	cout << "\nBest Scoring Subject Grades:75\n\nWorst Scoring Grades:55\n-------------------------------------------------------------------\n\nYour EDU+ Score Is Ready.\n";
	system("pause");
	cout << "\nEDU+ In Marks:0.7004\nEDU + In Age and Experience:0.4\EDU+ Score In Attendance:0.6\nEDU+ Score In Skills Is:0.7\nEDU+n Score In Extracarricular Participation:0.5";
	cout << "\nYour Total EDU+ Score Is:2.9";
	system("pause");
}

