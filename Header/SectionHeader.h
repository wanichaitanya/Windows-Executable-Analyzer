#ifndef SECTION_HEADER_H
#define SECTION_HEADER_H

#include "Header.h"
class sec_header
{
  private: 
    IMAGE_SECTION_HEADER secHeader;  //Represents the image section header format.
    int NoOfSec;
    int file_descriptor;
  public:
    sec_header(int f);
    void show_header();
};

#endif /* SECTION_HEADER_H*/