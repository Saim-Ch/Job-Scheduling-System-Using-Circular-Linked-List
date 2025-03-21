# Job-Scheduling-System-Using-Circular-Linked-List
A simple job scheduler implemented in C++ using a circular linked list. The program allows adding, deleting, and executing jobs with specific execution times.
## Features
* Add jobs with unique IDs, names, and execution times
* Delete jobs by ID
* Execute jobs in a circular manner (Round-Robin Scheduling)
* Display the current job list
## Code Structure
The code consists of the following components:
* Job_Sch struct: Represents a job with attributes job_id, job_name, exe_time, and a pointer to the next job in the list.
* addJob function: Adds a new job to the list.
* deleteJob function: Deletes a job by ID.
* executeJobs function: Executes the jobs in a circular manner.
* display function: Displays the current job list.
## Example Use Case
The provided main function demonstrates how to use the job scheduler:
* Add three jobs with different execution times.
* Display the initial job list.
* Delete a job by ID.
* Display the updated job list.
* Start executing the jobs.

## Output ScreenShot:
![Image description](https://i.imgur.com/O5d52mH.png)

## Program in Memory:
![Image description](https://i.imgur.com/5KIkYBs.png)

# Stop Program Execution by Pressing Ctrl + C
