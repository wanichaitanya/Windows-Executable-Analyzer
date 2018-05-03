#include "FileHeader.h"
long int OffFileHeader;
file_header::file_header(int f) //constructor
{
  file_descriptor=f;
  _lseek(file_descriptor,OffFileHeader,0);
  _read(f,&fileHeader,sizeof(fileHeader));
}

void file_header::show_header()
{
  cout<<endl<<"--------------FILE HEADER INFO-------------------"<<endl;
  cout<<"machine: "<<fileHeader.Machine<<endl;
  cout<<"number of section: "<<fileHeader.NumberOfSections<<endl;
  cout<<"time date stamp: "<<fileHeader.TimeDateStamp<<endl;
  cout<<"pointer to symbol table: "<<fileHeader.PointerToSymbolTable<<endl;
  cout<<"number of symbols: "<<fileHeader.NumberOfSymbols<<endl;
  cout<<"sizeof optional header: "<<fileHeader.SizeOfOptionalHeader<<endl;
  cout<<"characteristics: "<<fileHeader.Characteristics<<endl;
}