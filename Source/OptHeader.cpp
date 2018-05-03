#include "OptionalHeader.h"
long int OffOptHeader;
opt_header::opt_header(int f)
{
  file_descriptor=f;
  _lseek(file_descriptor,OffOptHeader,0);
  _read(f,&optHeader,sizeof(optHeader));
}

void opt_header::show_header()
{
  cout<<endl<<"-------------OPTIONAL HEADER INFO--------------"<<endl;
  cout<<"magic: "<<optHeader.Magic<<endl;
  cout<<"size of code: "<<optHeader.SizeOfCode<<endl;
  cout<<"size of size of initialized data: "<<optHeader.SizeOfInitializedData<<endl;
  cout<<"size of size of uninitialized data: "<<optHeader.SizeOfUninitializedData<<endl; 
  cout<<"address of entry point: "<<optHeader.AddressOfEntryPoint<<endl;
  cout<<"base of code: "<<optHeader.BaseOfCode<<endl;
  cout<<"base of data: "<<optHeader.BaseOfData<<endl;
  cout<<"image base: "<<optHeader.ImageBase<<endl;
  cout<<"section alignment: "<<optHeader.SectionAlignment<<endl;
  cout<<"file alignment: "<<optHeader.FileAlignment<<endl;
  cout<<"major operating system version: "<<optHeader.MajorOperatingSystemVersion<<endl;
  cout<<"minor operating system version: "<<optHeader.MinorOperatingSystemVersion<<endl;
  cout<<"major image version: "<<optHeader.MajorImageVersion<<endl;
  cout<<"minorimage version: "<<optHeader.MinorImageVersion<<endl;
  cout<<"major subsystem version: "<<optHeader.MajorSubsystemVersion<<endl;
  cout<<"minor subsystem version: "<<optHeader.MinorSubsystemVersion<<endl;
  cout<<"size of image: "<<optHeader.SizeOfImage<<endl;
  cout<<"size of header: "<<optHeader.SizeOfHeaders<<endl;
  cout<<"checksum: "<<optHeader.CheckSum<<endl;
  cout<<"subsystem: "<<optHeader.Subsystem<<endl;
  cout<<"dll characteristics: "<<optHeader.DllCharacteristics<<endl;
  cout<<"size of stack reverse: "<<optHeader.SizeOfStackReserve<<endl;
  cout<<"size of stack commit: "<<optHeader.SizeOfStackCommit<<endl;
  cout<<"size of heap reverse: "<<optHeader.SizeOfHeapReserve<<endl;
  cout<<"size of heap commit: "<<optHeader.SizeOfHeapCommit<<endl;
  cout<<"loader flags: "<<optHeader.LoaderFlags<<endl;
  cout<<"number of rva and size: "<<optHeader.NumberOfRvaAndSizes<<endl;
}