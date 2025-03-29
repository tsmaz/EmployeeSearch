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
 
    //defined in employeeTable.c 
    extern Employee EmployeeTable[];     
    extern const int EmployeeTableEntries;      
 
    PtrToEmployee matchPtr;  //Declaration 
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1235"); 
 
    //Example not found 
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
     
    
        getchar();
        return EXIT_SUCCESS; 
}