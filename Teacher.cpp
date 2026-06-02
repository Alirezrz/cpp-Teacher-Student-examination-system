#include"Header.hpp"

// Teacher Methods-----
//                    |
//                    |
//                    |
//                    V

Teacher::Teacher() {
    this->setName();
    this->setCourses();
    cout << "Enter your ID: " << endl;
    int flag = 0;
    while (flag == 0) {
        string id;
        getline(cin, id);
        string tmp = id;
        if (Check_logout_exit_command(tmp) == 1) {
            Logout();
            return;
        } else if (Check_logout_exit_command(tmp) == 2) {
            lists_deleter();
            exit(0);
        }
        // Ceking out the used ids for the  id to be unique
         
         
        if (Valid_ID(id)==true) {
            this->setID(id);
            flag = 1;
        } else {
            cout << "\033[31minvalid ID!\033[31m" << endl << "\e[0;33mPlease enter new ID:\033[0m" << endl;
        }
    }
    this->setPass();
}

Teacher::~Teacher() {
}

void Teacher::setCourses() {
    cout << "How many courses are you teaching?" << endl;
    cin >> number_of_courses;
    string tmp = Name;
    if (Check_logout_exit_command(tmp) == 1) {
        Logout();
        return;
    } else if (Check_logout_exit_command(tmp) == 2) {
        lists_deleter();
        exit(0);
    }
    cin.ignore();
    if (number_of_courses == "0") return;
    cout << "Please enter your courses:" << endl;
    for (int i = 0; i < number_of_courses.at(0) - '0'; i++) {
        string tmp;
        getline(cin, tmp);
        string tmp2 = tmp;
        if (Check_logout_exit_command(tmp2)) {
            Logout();
            return;
        }
        Courses.push_back(tmp);
    }
    return;
}
void Teacher::Show_personal_information(){
    cout << endl << "Name : " << this->Name << endl;
    cout << "ID : " << this->ID << endl;
    cout << "Courses :" << endl;
    for (int i = 0; i < Courses.size(); i++) {
        cout << i + 1 << "- " << Courses.at(i) << endl;
    }
    return;
}


void Teacher::Change_Passsword(){
    cout << "Enter your current Password:" << endl;
    int flag = 0;
    while (flag == 0) {
        string pas;
        getline(cin, pas);
        string tmp = pas;
        if (Check_logout_exit_command(tmp) == 1) {
            cout<<"Loging out..."<<endl;
            Logout();
            Menu();
            return;
        } 
        else if (Check_logout_exit_command(tmp) == 2) {
            lists_deleter();
            exit(0);
        }
        if (this->check_Pass(pas)) {
            cout << "Enter your new Password :" << endl;
            string newpas;
            getline(cin, newpas);
            string tmp = newpas;
            if (Check_logout_exit_command(tmp) == 1) {
                cout<<"Loging out..."<<endl;
                Logout();
                Menu();
                return;
            } 
            else if (Check_logout_exit_command(tmp) == 2) {
                lists_deleter();
                exit(0);
            }
            int set_flag = 0;
            while (set_flag == 0) {
                cout << "Confirm your new Password:" << endl;
                string tmp;
                getline(cin, tmp);
                string tmp3 = tmp;
                if (Check_logout_exit_command(tmp3) == 1) {
                    cout<<"Loging out..."<<endl;
                    Logout();
                    Menu();
                    return;
                } 
                else if (Check_logout_exit_command(tmp3) == 2) {
                    lists_deleter();
                    exit(0);
                }
                if (tmp == newpas) {
                    flag = 1;
                    this->Password = newpas;
                    cout << "\e[0;32m***Password Updated Successfully ...***\033[0m" << endl;
                    this->Options();
                    set_flag = 1;
                } 
                else {
                    cout << "\e[0;33mEnter your new Password correctly!\033[0m" << endl;
                }
            }
        } else {
            cout << "\033[31m<< Wrong Password >>\033[31m" << endl << "\e[0;33mtry again\033[0m" << endl;
        }
    }
    return;
}
void Teacher::Options() {
    cout << endl << "\e[0;36m ------- Options -----------------------------\033[0m" << endl;
    cout << "\e[0;36m|\033[0m \e[0;94m1-\033[0m \e[1;34mLogout\033[0m                                   \e[0;36m|" << endl;
    cout << "\e[0;36m|\033[0m \e[0;94m2-\033[0m \e[1;34mShow Personal information\033[0m                \e[0;36m|" << endl;
    cout << "\e[0;36m|\033[0m \e[0;94m3-\033[0m \e[1;34mChange Passsword\033[0m                         \e[0;36m|" << endl;
    cout << "\e[0;36m|\033[0m \e[0;94m4-\033[0m \e[1;34mExams \033[0m                                   \e[0;36m|" << endl;
    cout << "\e[0;36m|\033[0m \e[0;94m5-\033[0m \e[1;34mExams scores lists\033[0m                       \e[0;36m|" << endl;
    cout << "\e[0;36m|\033[0m \e[0;94m6-\033[0m \e[1;34mCorrection list\033[0m                          \e[0;36m|" << endl;
    cout << "\e[0;36m ---------------------------------------------\033[0m" << endl;
    cout << "Enter number of your command:" << endl;
    string cmd;
    getline(cin, cmd);
    lower(&cmd);
    string tmp = cmd;
    if (cmd == "exit") {
        lists_deleter();
        exit(0);
    } 
    else if (cmd[0] == '1') {
        cout << "Good Bye " << Name << endl;
        Menu();
    } 
    else if (cmd[0] == '2') {
       this->Show_personal_information();
        this->Options();
    } 
    else if (cmd[0] == '3') {
        this->Change_Passsword();
        this->Logout();
        Menu();
    }
    else if (cmd[0] == '4') {
        Exams();
        Options();
    
    } 
    else if(cmd[0]=='5'){
        this->Exams_scores_lists();
        this->Options();
    }
    
    else if(cmd[0]=='6'){
        this->Correction();
        this->Options();
    }
    return;
}                                         
void Teacher::Exams() {
    while(true){
        cout << "\e[0;94m1-\033[0m\e[0;36m Create an exam\033[0m" << endl;
        cout << "\e[0;94m2-\033[0m\e[0;36m View  exams\033[0m" << endl;
        cout << endl << "Please enter your command:" << endl << "(create / view / exit): ";
        string cmd; 
        getline(cin, cmd); 
        if (cmd == "create") {
            Exam newExam;
            newExam.set_designer(this->Name,this->ID);
            while (true) { 
                cout << "\e[0;36m- Add question\033[0m" << endl;
                cout << "\e[0;36m- Remove question\033[0m" << endl;
                cout << "(add/remove/finish): ";
                string cmd; 
                getline(cin, cmd);
                if (cmd == "finish") {
                    newExam.Add_to_list();
                    created_Exams_list->push_back(newExam);
                    cout << "\e[0;32m******Exam created successfully!******\033[0m" << endl << endl;
                    break; 
                } 
                else if (cmd == "add") {
                    newExam.Add();
                } 
                else if (cmd == "remove") {
                    newExam.Remove();
                } 
                else {
                    cout << "\033[31mInvalid command!\033[31m \e[0;33mPlease enter 'add', 'remove', or 'finish'.\033[0m" << endl;
                }
            }
            return;
        } 
        
        else if (cmd == "view") {
            int step=1;
            bool flag=false;
           for(int i=0;i<exam_codes->size();i++){
            if(exam_codes->at(i).get_designer()==this->Name&&exam_codes->at(i).get_designer_id()==this->ID){
                cout<<step<<") "<<exam_codes->at(i).get_code()<<endl;
                step++;
                flag=true;
            }
           }
           if(!flag){
            cout<<"\033[31mNo available exam!\033[0m"<<endl;
           }
           else if(flag){
            cout<<"Enter the code you want to see :"<<endl;
            string code;
            
            getline(cin, code);
            cout<<"Code"<<code<<endl;
            bool found = false;
            for (int i = 0; i < created_Exams_list->size(); i++) {
                if (code == created_Exams_list->at(i).get_code()) {
                    created_Exams_list->at(i).Show_to_teacher();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Exam with code '" << code << "' \033[31mnot found!\033[0m" << endl;
            }
            return;

           }
        } 
        else if (cmd == "exit") {
            return;
        } 
        else {
            cout << "\033[31mInvalid command!\033[0m"<< endl<<endl;
        }
    }
    return;


    
}

//this function make a json type of the teacher:

json Teacher::teacher_to_json(){
    json teacher;
    teacher["Courses"]= json::array();
    for(auto course:this->Courses){
        teacher["Courses"].push_back(course);
    }
    teacher["ID"]=this->ID;
    teacher["Name"]=this->Name;
    teacher["Password"]=this->Password;
    teacher["number_of_courses"]=this->number_of_courses;
    teacher["correction_list"] = json ::array();
   for(auto ans : this->correction_list){
    teacher["correction_list"].push_back(ans.turn_to_json());
   }
    return teacher;

}


Teacher json_to_teacher(json j_teacher){
    Teacher tmp_teacher(-1);
    
    tmp_teacher.Name = j_teacher["Name"];
    tmp_teacher.ID = j_teacher["ID"];
    tmp_teacher.Password = j_teacher["Password"];
    tmp_teacher.number_of_courses = j_teacher["number_of_courses"];
    
    if (j_teacher.contains("Courses")) {
        for ( auto& course : j_teacher["Courses"]) {
            tmp_teacher.Courses.push_back(course.get<string>());
        }
    }

    if(j_teacher.contains("correction_list")){
        for(auto ans : j_teacher["correction_list"]){
            Student_answer tmp;
            tmp.student_id=ans["student_id"];
            tmp.Exam_code=ans["Exam_code"];
            tmp.student_answer=ans["student_answer"];
            tmp.sent_score=ans["sent_score"];
            tmp.Question_body=ans["Question_body"];
            tmp.Question_correct_answer=ans["Question_correct_answer"];
            tmp_teacher.correction_list.push_back(tmp);
        }
        
    }
    
    
    
    
    
    return tmp_teacher;
}
void Load_teachers(){
    ifstream file("teachers.json");
    if(file.is_open()){
        json teachers;
        file >> teachers;
        for(auto & teacher : teachers){
            Teacher *new_teacher = new Teacher(-1);
            *new_teacher = json_to_teacher(teacher);
            teacher_list->push_back(*new_teacher);
            delete new_teacher;
        }
        file.close();
    }
    else {
        ofstream new_file("teachers.json");
        new_file << json::array().dump(4);
        new_file.close();
        cout << "Created new empty teachers.json" << endl;
    }

}


void store_teachers(){
    json teachers = json :: array();

    for(auto& teacher : *teacher_list){
        teachers.push_back(teacher.teacher_to_json());
    }

    ofstream file("teachers.json");
    if(file.is_open()){
        file << teachers.dump(4);
        file.close();
    }
    else {
        cout << "Error: Failed to open teachers.json for writing!" << endl;
    }
}

void Teacher::Exams_scores_lists() {
    
    const string CYAN = "\033[0;36m";
    const string YELLOW = "\033[1;33m";
    const string RESET = "\033[0m";

    // Header
    cout << CYAN << "\nExam Code    Exam Name\n";
    cout << "-----------------------\n" << RESET;

    bool hasExams = false;

    // Display exams
    for (const Exam& exam : *created_Exams_list) {
        if (exam.designer == this->Name && exam.designer_id==this->ID){
            cout << CYAN << exam.Code << RESET << "    " << exam.Name << "\n";
            hasExams = true;
        }
    }

    if (!hasExams) {
        cout << YELLOW << "  You have no created exams.\n" << RESET;
        return;
    }


    cout << "\n-----------------------\n";
    cout << YELLOW << "Enter exam code: " << RESET;
    string code;
    getline(cin, code);

    // Find and display results
    bool found = false;
    for ( Exam& exam : *created_Exams_list) {
        if (exam.Code == code) {
            exam.display_grades_to_teacher();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << YELLOW << "\nInvalid exam code!\n" << RESET;
    }
}


void Teacher::Correction(){
    if(this->correction_list.size()==0){
        cout<<"\e[0;33m---There is no answer to check---\033[0m"<<endl<<endl;
        return;
    }

    cout<<"\e[4;35mStudents :\033[0m"<<endl;
    for(auto answer :this->correction_list){
       cout<<"\e[0;36mName :\033[0m"<<Find_name_of_person(answer.student_id)<<"   \e[0;36mID:\033[0m"<<answer.student_id<<endl;
    }
    bool flag =false;
    while(!flag){
        cout<<"\e[0;36mEnter student ID: \033[0m";
        string id;
        getline(cin,id);

    
        int index=0;
        for(auto std_ans : this->correction_list){
            index++;
            if(id==std_ans.student_id){
                flag = true;
                cout<<endl;
                cout<<"\e[0;36mExam Code : \033[0m"<<std_ans.Exam_code<<endl;
                cout<<"\e[0;36mQuestion : \033[0m"<<std_ans.Question_body<<"\t";
                cout<<"\e[0;36mStudent's Answer :\033[0m "<<std_ans.student_answer<<"\t";
                cout<<"\033[0mCorrect Answer : \033[0m"<<std_ans.Question_correct_answer<<endl;
                cout<<"\033[0mthis score is set for the student\033[0m \e[4;36m	---> \033[0m"<<std_ans.sent_score<<endl;

                // here we find the positive effect of the Question:

                double max_scr;
                for(auto exam : *created_Exams_list){
                    if(exam.Code==std_ans.Exam_code){
                        for(auto q : exam.Questions){
                            if(q.question_body==std_ans.Question_body){
                                max_scr = q.Positive_effect;
                                break;
                            }
                        }
                    }
                }
                Change_question_score(std_ans.Exam_code,std_ans.student_id,std_ans.sent_score,max_scr,std_ans.Question_body,std_ans.Question_correct_answer);

            }
            this->correction_list.erase(correction_list.begin()+index-1);
            return;
        }

        cout<<"\e[0;33m---Not Found---\033[0m"<<endl<<endl;
    }
    return;
    
}