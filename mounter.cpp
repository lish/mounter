/*Developer Philassides Charalambos
This programm are giving you the power to mount and umount your input and ouput device's, you don't need to spent time for typing command's!
*/


#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//***********************************|fdisk|************************************
void fdisk_check(){

system("sudo fdisk -l ");
cout <<endl;
cout <<endl;
system("mount ");
}
//******************************************************************************


//***********************|mount device|*****************************************
bool mount(char *device_array, char *destination, char *root_mount){

char answer, directory[30], mkdir[12];
cout <<"Mount"<<endl;
cout<<endl;
cout<<"Give The Device Name"<<endl;
cin >> device_array;
cout<<endl;
cout <<"Do you want to Creat a new directory for mount?: ";
cin >>answer;

if ((answer == 'Y') || (answer == 'y'))
 {
 cout << endl;
 cout <<"Give the name of your directory and specific where"<<endl;
 cin >> directory;


 strcpy(mkdir, "sudo mkdir ");
 strcat(mkdir,directory);
 system(mkdir);
}

cout <<"Give The Path Thats you want to Mount"<<endl;
cin >> destination;

strcpy(root_mount, "sudo mount ");
strcat(root_mount,device_array);
strcat(root_mount, " ");
strcat(root_mount, destination);
system(root_mount);


return true;
}
//******************************************************************************

//***********************|umount device|****************************************
bool umount(char *device_array, char *destination, char *root_umount){

cout <<"UMOUNT"<<endl;
cout<<endl;
cout<<"Give The Device Name"<<endl;
cin>>device_array;
cout<<endl;

strcpy(root_umount, "sudo umount ");
strcat(root_umount,device_array);
system(root_umount);

return true;
}

//******************************************************************************

//****************************|main|********************************************

int main(){
int a;
bool status;
char menu, answer;
char device_array[9];
char destination[30];
char root_mount[30], root_umount[30];


cout <<"Welcome to the Mounter by Philassides"<<endl;
//**************************************|menu|***********************************
do{
do{
cout <<endl;
cout <<endl;
cout <<"(1) Check The Active Devices "<<endl;
cout <<"(2) Mount "<<endl;
cout <<"(3) Umount "<<endl;
cout <<"(4) Exit "<<endl;
cin>>a;
switch (a){
case 1:
fdisk_check();
break;
case 2:
mount(device_array, destination, root_mount);
break;
case 3:
umount(device_array, destination, root_umount);
break;
case 4:
status = false;
return 1;
}
}
while(status);
//****************************|The return of menu|*******************************
cout <<"Back to menu? Y or N"<<endl;
cin >> answer;

if (((answer != 'Y') && (answer != 'N')) || ((answer != 'y') && (answer != 'n')))
return false;
else
return true;

}while(false);

return 0;
}

//*****************************|End of Programm|*********************************

