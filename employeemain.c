//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 
 
//gcc employeeMain.c employeeTable.c employeeTwo.c 
 
#include <string.h> 
#include <stdlib.h> 
#include "employee.h" 
int main(void){ 
    //defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind); 
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double SalaryToFind); 
 
    //defined in employeeTable.c 
    extern Employee EmployeeTable[];     
    extern const int EmployeeTableEntries;      
 
    PtrToEmployee matchPtr;  //Declaration 
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 5.55); 
    //Example not found (salary)
    if (matchPtr != NULL) 
        printf("Employee with salary 5.55 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with salary 5.55 is NOT found in the record\n"); 
 
    //Example found (salary)
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78); 
    if (matchPtr != NULL) 
        printf("Employee with salary 8.78 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with salary 8.78 is NOT found in the record\n"); 

    //Example not found (phone number)
    if (matchPtr != NULL) 
        printf("Employee with phone number 310-555-1235 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with phone number 310-555-1235 is NOT found in the record\n"); 
 
    //Example found (phone number)
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235"); 
    if (matchPtr != NULL) 
        printf("Employee with phone number 909-555-1235 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee with phone number 909-555-1235 is NOT found in the record\n"); 
     
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 
 
    //Example not found 
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee ID is NOT found in the record\n"); 
 
    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n"); 
    
        getchar();
        return EXIT_SUCCESS; 
}