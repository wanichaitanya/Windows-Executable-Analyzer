#include "Header.h"
#include "DosHeader.h"
#include "OptionalHeader.h"
#include "SectionHeader.h"
#include "FileHeader.h"


extern long int OffDosHeader;
extern long int OffFileHeader;
extern long int OffOptHeader;
extern long int OffSecHeader;
void CalculateOffset(int fd)
{
  IMAGE_DOS_HEADER dosheader;  //Allows the managed application programming interface (API) to have access to the unmanaged portions of the Microsoft DirectX API
  _read(fd,&dosheader,sizeof(dosheader)); //read system call

  OffDosHeader=0;
  OffFileHeader=dosheader.e_lfanew+4;
  OffOptHeader=OffFileHeader+0x14;
  OffSecHeader=OffOptHeader+sizeof(IMAGE_OPTIONAL_HEADER);

  _lseek(fd,0,0); //change the location system call

}

int main(int argc ,char *argv[])
{
  int ip;
  char file_name[256] = {'\0'};

  cout<<"enter file name";
  cin>>file_name;

  int fd= _open(file_name,O_RDONLY|O_BINARY);
  if(fd==-1)
  {
    cout<<endl<<"error:file not found"<<endl;
    return-1;
  }
  CalculateOffset(fd);

  do
  {
    ip=0;

    cout<<endl<<"enter ur choice"<<endl;
    cout<<"1.dos header"<<endl;
    cout<<"2.file header"<<endl;
    cout<<"3.optional header"<<endl;
    cout<<"4.section header"<<endl;
    cout<<"5.exit"<<endl;
    cout<<"Select Option"<<endl;
    cin>>ip;

    switch(ip)
    {
      case 1 : 
      {
        dos_header dosHeader(fd);
        dosHeader.show_header();
        break;
      }

      case 2 :
      {
        file_header fileHeader(fd);
        fileHeader.show_header();
        break;
      }

      case 3 :
      {
        opt_header optionalHeader(fd);
        optionalHeader.show_header();
        break;
      }

      case 4 : 
      {
        sec_header sectionHeader(fd);
        sectionHeader.show_header();
        break;
      }

      case 5 :
      {
        _close(fd);
        exit(0);
        break;
      }

      default : break;
    }
  }
  while(ip!=5);
  return 0;
}
