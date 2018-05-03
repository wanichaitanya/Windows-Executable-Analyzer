#include "DosHeader.h"

long int OffDosHeader;

dos_header::dos_header(int f)
	{
		file_descriptor=f;
		_lseek(file_descriptor,OffDosHeader,0);
		_read(f,&dosheader,sizeof(dosheader));
	}

void dos_header::show_header()
	{
		cout<<endl<<"---------------DOS HEADER INFO--------------"<<endl;
		cout<<"magic number: "<<std::hex<<dosheader.e_magic<<endl;  
		cout<<"bytes on last page of file: " <<dosheader.e_cblp<<endl;  
		cout<<"pages in file: " <<dosheader.e_cp<<endl;   
		cout<<"relocation: "<<dosheader.e_crlc<<endl;  
		cout<<"size of heaader in paragraphs: "<<dosheader.e_cparhdr<<endl; 
		cout<<"minimum extra paragraphs needed: "<<dosheader.e_minalloc<<endl;
		cout<<"maximum extra paragraphs needed: "<<dosheader.e_maxalloc<<endl;
		cout<<"initial (relative) SS values: "<<dosheader.e_ss<<endl;
		cout<<"initial sp value: "<<dosheader.e_sp<<endl;
		cout<<"checksum: "<<dosheader.e_csum<<endl;
		cout<<"initial ip value: "<<dosheader.e_ip<<endl;
		cout<<"initial (relative) CS value: "<<dosheader.e_cs<<endl;
		cout<<"file address of relocation table: "<<dosheader.e_lfarlc<<endl;
		cout<<"overlay number: "<<dosheader.e_ovno<<endl;
		cout<<"oem identifier: "<<dosheader.e_oemid<<endl;
		cout<<"oem information(e_oemid specific): "<<dosheader.e_oeminfo<<endl;
		cout<<"rva address of pe header: "<<dosheader.e_lfanew<<endl;

	}