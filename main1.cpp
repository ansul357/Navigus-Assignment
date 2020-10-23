#include<bits/stdc++.h>
using namespace std;
class Exam {
    int no_of_questions;
    public:
    	bool is_ans[4], is_mcq, is_msq;
		int question, options[4][30];
		string ques;
        Exam() {
            no_of_questions = 2;
            is_ans[0] = false;
            is_ans[1] = false;
            is_ans[2] = false;
            is_ans[3] = false;
        
            is_mcq = false;
            is_msq = false;
        }
		
		void writeQuestionInFile() {
			ofstream fout("fileOfQuestions.dat",ios::out | ios::binary);
			Exam ex;
			ex.addQuestions();
			fout.write((char*)&ex, sizeof(Exam));
		
			cout << "data saved: " <<ex.question<<endl;
			fout.close();
		}
		
        void addQuestions() {
        	cout << "Enter No of Questions" << endl;
        	cin>>question;
        	
        	int temp =question;
        	while(temp--)
        	{
        	cout<<(question-temp)<<endl;
        	//getline(cin,ques);
            int ch;
        	cout << "1. For MCQ" << endl;
        	cout << "2.FOR MSQ" << endl;
        	cin >> ch;
        	if(ch == 1) {
        		int ans = 0;
				cout << "Enter correct option";
        			cin >> ans;
        		is_ans[ans - 1] = true;
			} else {
				int count;
				cout << "Enter How many answers are correct : " << endl;
				cin >> count;
				while(count--) {
	        		int ans = 0;
					cout << "Enter correct option";
	        			cin >> ans;
	        		is_ans[ans - 1] = true;					
				}
			}
		}
			//writeQuestionInFile();
			
        }
        void displayQuestion()
        {
        	fstream fp;
            cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
            fp.open("fileOfQuestions.dat",ios::in);
            Exam ex;
            while(fp.read((char*)&ex,sizeof(Exam)))
            {
               cout<<ex.ques<<endl;
               cout<<"\n\n====================================\n";
        
			 }
    fp.close();
		}
};
Exam ex;
void page1(){
    system("Color 02"); 
	cout<<"\t\t\t\t-----------------------------------------";
	cout<<endl;
	cout<<"\t\t\t\tWELCOME TO THE ADAPTIVE LEARNING PLATFORM";
	cout<<endl;
	cout<<"\t\t\t\t-----------------------------------------"<<endl;
	cout<<endl;
}
void addQuestion()
{
	string ques;
	cout<<"Enter the question"<<endl;
	getline(cin,ques);
}

int main() {
    page1();
    
    
    Exam *exam = new Exam();
    exam->writeQuestionInFile();
    int choice;
    do{
        cout << "1. Student" << endl;
        cout << "2. Teacher" << endl;
        cout << "3. EXIT" << endl;
        cout << "Enter your Choice\n";
        cin >> choice;
        
        switch(choice) {
            case 1: cout << "student";
            
                break;
            case 2:
            cout << "teacher";
            break;
            case 3:
                exit(0);
        }
    } while(choice != 3);
}
