#include<stdio.h>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<iostream>
#include<conio.h>
#include<fcntl.h>
#include<io.h>
#define TRUE 0
#define FALSE 1
typedef int BOOL;
using namespace std;
long int OffDosHeader;
long int OffFileHeader;
long int OffOptHeader;
long int OffSecHeader;

void CalculateOffset(int fd)
{
 IMAGE_DOS_HEADER dosheader;
 _read(fd, &dosheader, sizeof(dosheader));
 OffDosHeader = 0;
 OffFileHeader = dosheader.e_lfanew + 4;
 OffOptHeader = OffFileHeader + 0x14;
 OffSecHeader = OffOptHeader + sizeof(IMAGE_OPTIONAL_HEADER);
 _lseek(fd, 0, 0);

}
class dos_header
{
public:
 IMAGE_DOS_HEADER dosheader;
 int fp;
 unsigned short magic = 0x00;
 dos_header(int f)
 {
  fp = f;
  _lseek(fp, OffDosHeader, 0);
  _read(f, &dosheader, sizeof(dosheader));
  magic = dosheader.e_magic;
 }

 void Show_Header()
 {
  cout << endl << "*****************************DOS HEADER INFO*****************************************" << endl;
  cout << "Magic Number:   " << std::hex << dosheader.e_magic << endl;
  cout << "Byte on last page of File:   " << dosheader.e_cblp << endl;
  cout << "Page in File:   " << dosheader.e_cp << endl;
  cout << "Relocation:   " << dosheader.e_crlc << endl;
  cout << "Size of Header in Paragraph:   " << dosheader.e_cparhdr << endl;
  cout << "Minimum extra paragraph needed:   " << dosheader.e_minalloc << endl;
  cout << "Maximum extra paragraph needed:   " << dosheader.e_maxalloc << endl;
  cout << "Initial (relative) SS value:   " << dosheader.e_ss << endl;
  cout << "Initial SP Value:   " << dosheader.e_sp << endl;
  cout << "CheckSum:   " << dosheader.e_csum << endl;
  cout << "Initial Stack Pointer:   " << dosheader.e_ip << endl;
  cout << "Ïnitial (relative) CS Value:   " << dosheader.e_cs << endl;
  cout << "File Address of relocation table:   " << dosheader.e_lfarlc << endl;
  cout << "Overlay Number:   " << dosheader.e_ovno << endl;
  cout << "OEM indentifier:   " << dosheader.e_oemid << endl;
  cout << "OEM information(e_oemid specific):   " << dosheader.e_oeminfo << endl;
  cout << "RVA address of PE Header:   " << dosheader.e_lfanew << endl;
 }
 BOOL CheckMagic() // check magic number
 {
  if (magic == 0x5A4D)
  {
   return TRUE;
  }
  else
  {
   return FALSE;
  }
 }
};


class file_header
{
public:
 IMAGE_FILE_HEADER fileheader;
 int fp;
 file_header(int f)
 {
  fp = f;
  _lseek(fp, OffFileHeader, 0);
  _read(f, &fileheader, sizeof(fileheader));
 }
 void Show_Header()
 {
  cout << endl << "*****************************File Header Info********************************************";
  cout << "Machine:		" << fileheader.Machine << endl;
  cout << "Number of sections:		" << fileheader.NumberOfSections << endl;
  cout << "Time Date Stamp:		" << fileheader.TimeDateStamp << endl;
  cout << "Pointer To Symbol Table:		" << fileheader.PointerToSymbolTable << endl;
  cout << "Number Of Symbols:		" << fileheader.NumberOfSymbols << endl;
  cout << "size of optional header:		" << fileheader.SizeOfOptionalHeader << endl;
  cout << "Characteristics:		" << fileheader.Characteristics << endl;
 }
 void CheckExe()
 {
  if ((fileheader.Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) && (!(fileheader.Characteristics & IMAGE_FILE_DLL)))//only executable
  {
   cout << "This is self executable file" << endl;
  }
  else if (fileheader.Characteristics & IMAGE_FILE_DLL)// dependable
  {
   cout << "This is dependable executable file" << endl;
  }
  else //rest of the type of file
  {
   cout << "This is nor self executable not dependable executable file" << endl;
  }
 }
};
class opt_header
{
public:
 IMAGE_OPTIONAL_HEADER optHeader;
 int fp;
 opt_header(int f)
 {
  fp = f;
  _lseek(fp, OffOptHeader, 0);
  _read(fp, &optHeader, sizeof(optHeader));
 }
 void Show_Header()
 {
  cout << endl << "***************************************Optional Header*********************************";
  cout << "Magic:		" << optHeader.Magic << endl;
  cout << "Size of code:		" << optHeader.SizeOfCode << endl;
  cout << "Size of Initialized data:		" << optHeader.SizeOfInitializedData << endl;
  cout << "Size of Unitialized data:		" << optHeader.SizeOfUninitializedData << endl;
  cout << "Address of Entry Point:		" << optHeader.AddressOfEntryPoint << endl;
  cout << "Base of Code:		" << optHeader.BaseOfCode << endl;
  cout << "Base of Data:		" << optHeader.BaseOfData << endl;
  cout << "Image Base:		" << optHeader.ImageBase << endl;
  cout << "Section Allingnment:		" << optHeader.SectionAlignment << endl;
  cout << "File Alignment:		" << optHeader.FileAlignment << endl;
  cout << "Major Operating system version:		" << optHeader.MajorOperatingSystemVersion << endl;
  cout << "Minor Operating system version:		" << optHeader.MinorOperatingSystemVersion << endl;
  cout << "Major Image version:		" << optHeader.MajorImageVersion << endl;
  cout << "Minor Image version:		" << optHeader.MinorImageVersion << endl;
  cout << "Major Subsystem version:		" << optHeader.MajorSubsystemVersion << endl;
  cout << "Minor Subsystem version:		" << optHeader.MinorSubsystemVersion << endl;
  cout << "Size of Image:		" << optHeader.SizeOfImage << endl;
  cout << "Size of Headers:		" << optHeader.SizeOfHeaders << endl;
  cout << "Checksum:		" << optHeader.CheckSum << endl;
  cout << "Subsystem:		" << optHeader.Subsystem << endl;
  cout << "Dll Characteristics:		" << optHeader.DllCharacteristics << endl;
  cout << "Size of Stack Reserve:		" << optHeader.SizeOfStackReserve << endl;
  cout << "Size of Stack Commit:		" << optHeader.SizeOfStackCommit << endl;
  cout << "Size of Heap Reserve:		" << optHeader.SizeOfHeapReserve << endl;
  cout << "Size of Heap Commit:		" << optHeader.SizeOfHeapCommit << endl;
  cout << "Loader Flags:		" << optHeader.LoaderFlags << endl;
  cout << "Number of RVA and sizes:		" << optHeader.NumberOfRvaAndSizes << endl;
 }
};

class sec_header
{
public:
 IMAGE_SECTION_HEADER secHeader;
 int fp;
 int NoOfSec, NoOfSec2;
 char **arr;
 sec_header(int f)
 {
  IMAGE_FILE_HEADER fileheader;
  fp = f;
  _lseek(fp, OffFileHeader, 0);
  _read(f, &fileheader, sizeof(fileheader));
  NoOfSec = fileheader.NumberOfSections;
  NoOfSec2 = NoOfSec;
  _lseek(fp, OffSecHeader, 0);
  _read(f, &secHeader, sizeof(secHeader));
 }
 void Show_Header()
 {
  cout << endl << "***************************************Section Header Info*********************************";
  while (NoOfSec != 0)
  {
   cout << "Name:		" << secHeader.Name << endl;
   cout << "Virtual Address:		" << secHeader.VirtualAddress << endl;
   cout << "Size Of Raw Data:		" << secHeader.SizeOfRawData << endl;
   cout << "Pointer to Raw Data:		" << secHeader.PointerToRawData << endl;
   cout << "Pointer to Relations:	+-	" << secHeader.PointerToRelocations << endl;
   cout << "Pointer to Line Number:		" << secHeader.PointerToLinenumbers << endl;
   cout << "Number of Relocations:		" << secHeader.NumberOfRelocations << endl;
   cout << "Number of Linenumbers:		" << secHeader.NumberOfLinenumbers << endl;
   cout << "Characteristics:		" << secHeader.Characteristics << endl;
   NoOfSec--;
   cout << endl << "--------------------------------------------------------------------------------------------------------" << endl;
   _read(fp, &secHeader, sizeof(secHeader));
  }
 }
 void CalculateSections() //display all the sections in given file
 {
  int i = 1;
  _lseek(fp, OffSecHeader, 0);
  _read(fp, &secHeader, sizeof(secHeader));
  while (NoOfSec != 0)
  {
   cout << i << ")" << secHeader.Name << endl;
   NoOfSec--;
   i++;
   _read(fp, &secHeader, sizeof(secHeader));
  }
 }
 void ShowSection(int iSection) // show selected section
 {
  _lseek(fp, OffSecHeader, 0);
  cout << endl << "***************************************Section Header Info*********************************";
  while (iSection != 0)
  {
   _read(fp, &secHeader, sizeof(secHeader));
   iSection--;
  }
  cout << endl;
  cout << "Name:		" << secHeader.Name << endl;
  cout << "Virtual Address:		" << std::hex << secHeader.VirtualAddress << endl;
  cout << "Size Of Raw Data:		" << secHeader.SizeOfRawData << endl;
  cout << "Pointer to Raw Data:		" << secHeader.PointerToRawData << endl;
  cout << "Pointer to Relations:		" << secHeader.PointerToRelocations << endl;
  cout << "Pointer to Line Number:		" << secHeader.PointerToLinenumbers << endl;
  cout << "Number of Relocations:		" << secHeader.NumberOfRelocations << endl;
  cout << "Number of Linenumbers:		" << secHeader.NumberOfLinenumbers << endl;
  cout << "Characteristics:		" << secHeader.Characteristics << endl;
 }
};
int main(int argc, char *argv[])
{
 int ip, fd = -1;
 char file_name[1024] = {'\0'};
 cout << "Enter Name of File" << endl;
 scanf("%s", file_name);
 fd = _open(file_name, O_RDONLY/*, _S_IREAD*/);
 if (fd == -1)
 {
  cout << endl << "Error: In File Opening" << endl;
  return -1;
 }
 CalculateOffset(fd);

 do
 {
  ip = 0;
  cout << "Enter Your Choice" << endl;
  cout << "1.Dos Header" << endl;
  cout << "2.File Header" << endl;
  cout << "3.Optional Header" << endl;
  cout << "4.Sec Header" << endl;
  cout << "5. Check Magic Number" << endl;
  cout << "6.Serach by section name" << endl;
  cout << "7.Check the type of executable file" << endl;
  cout << "8.Exit" << endl;
  cout << "Your Choice" << endl;
  cin >> ip;
  switch (ip)
  {
  case 1:
  {
   dos_header dh(fd);
   dh.Show_Header();
   break;
  }
  case 2:
  {
   file_header fh(fd);
   fh.Show_Header();
   break;
  }
  case 3:
  {
   opt_header oh(fd);
   oh.Show_Header();
   break;
  }
  case 4:
  {
   sec_header sh(fd);
   sh.Show_Header();
   break;
  }
  case 5:
  {
   dos_header dh(fd);
   if (dh.CheckMagic() == TRUE)
   {
    cout << "This executable can be run on windows NT Family" << endl;
   }
   else
   {
    cout << "This executable can't be run on windows NT Family" << endl;
   }
   break;
  }
  case 6:
  {
   int option;
   sec_header sh(fd);
   cout << "Select Option" << endl;
   sh.CalculateSections();
   cout << sh.NoOfSec2 + 1 << ") Break" << endl;
   cin >> option;
   if (option == sh.NoOfSec2 + 1)
   {
    break;
   }
   sh.ShowSection(option);
   break;
  }
  case 7:
  {
   file_header fh(fd);
   fh.CheckExe();
   break;
  }
  case 8:
  {
   _close(fd);
   exit(0);
   break;
  }
  }
 } while (ip != 8);
 return 0;
}
