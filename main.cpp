#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
struct Job_Sch{
	int job_id;
	string job_name;
	int exe_time;
	Job_Sch *next;
};
Job_Sch *head = NULL;
void addJob(int id, string name, int time){
	Job_Sch *newNode = new Job_Sch();
	newNode->job_id = id;
	newNode->job_name = name;
	newNode->exe_time = time;
	if(head == NULL){
		head = newNode;
		newNode->next = head;
	} 
	else{
		Job_Sch *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
	}
}
void deleteJob(int id){
	if(head == NULL){
		cout<<"Empty....!";
		return;
	}
	if(head->next == head){
		if(head->job_id == id){
			delete head;
			head = NULL;
		}
		return;
	}
	if (head->job_id == id) {
        Job_Sch *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }
    Job_Sch *temp = head;
    while (temp->next != head) {
        if (temp->next->job_id == id) {
            Job_Sch *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
}
void executeJobs() {
    if (head == NULL) {
        cout << "No jobs to execute!" << endl;
        return;
    }
    Job_Sch *temp = head;
    int cycles = 2; 
    for (int i = 0; i < cycles; i++) {
        cout << "\n--- Cycle " << (i + 1) << " ---\n";
        Job_Sch *current = head;
        do {
            cout << "Executing Job: " << current->job_id << " (" << current->job_name << ") for " << current->exe_time << " seconds..." << endl;
            cout << "Job " << current->job_id << " execution completed!" << endl;
            current = current->next;
        } 
        while (current != head);
    }
    cout << "\nAll jobs executed twice!\n";
}

void display(){
	if (head == NULL) {
    cout << "No jobs in the queue!" << endl;
    return;
}
	Job_Sch *temp = head;
	do{
		cout<<"Job ID: "<<temp->job_id<<", Job Name: "<<temp->job_name<<", Job Time: "<<temp->exe_time<<endl;
		temp = temp->next;
	}
	while(temp != head);
}
int main(){
	addJob(101, "Database Backup", 3);
    addJob(102, "System Update", 2);
    addJob(103, "Report Generation", 5);
    
    cout << "Initial Job List:" << endl;
    display();
    cout<<endl;
    
    cout << "Job List After Deleting:" << endl;
    deleteJob(102);
    display();
    cout<<endl;
    
    cout << "\nStarting Job Execution...\n";
    executeJobs();
    
    return 0;
}
