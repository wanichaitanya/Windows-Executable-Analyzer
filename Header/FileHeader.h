#ifndef FILE_HEADER_H
#define FILE_HEADER_H

#include "Header.h"

__declspec(dllexport) class file_header
{
  private :
    IMAGE_FILE_HEADER fileHeader; //Represents the COFF header format
    int file_descriptor;

  public:
    file_header(int f);
    void show_header();
};

#endif /*FILE_HEADER_H */
