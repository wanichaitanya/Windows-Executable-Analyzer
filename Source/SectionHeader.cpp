#include "SectionHeader.h"

extern long int OffFileHeader;
long int OffSecHeader;


sec_header::sec_header(int f)
{
  IMAGE_FILE_HEADER fileheader;
  file_descriptor=f;
  _lseek(file_descriptor,OffFileHeader,0);
  _read(f,&fileheader,sizeof(fileheader));

  NoOfSec=fileheader.NumberOfSections;
  _lseek(f,OffSecHeader,0);
  _read(f,&secHeader,sizeof(secHeader));
}

void sec_header::show_header()
{
  cout<<endl<<"--------------------SECTION HEADER INFO-----------------"<<endl;
  while(NoOfSec!=0)
  {
    cout<<"Name:"<<secHeader.Name<<endl;
    cout<<"Virtual address: "<<secHeader.VirtualAddress<<endl;
    cout<<"Size of raw data: "<<secHeader.SizeOfRawData<<endl;
    cout<<"Pointer to raw data: "<<secHeader.PointerToRawData<<endl;
    cout<<"Pointer to relocation: "<<secHeader.PointerToRelocations<<endl;
    cout<<"Pointer to line number: "<<secHeader.PointerToLinenumbers<<endl;
    cout<<"No of line no: "<<secHeader.NumberOfLinenumbers<<endl;
    cout<<"No of relocation: "<<secHeader.NumberOfRelocations<<endl;
    cout<<"Characteristics: "<<secHeader.Characteristics<<endl;
    NoOfSec--;
    cout<<endl<<"--------------------"<<endl;
    _read(file_descriptor,&secHeader,sizeof(secHeader));
  }
}
