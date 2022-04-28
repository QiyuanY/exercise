//
// Created by yqy1277 on 2022/4/23.
//

#include "FileRead.h"

FileRead::FileRead(const char *f) {
  FILE *input = fopen(f,"r");
  fclose(input);
}

FileRead::~FileRead() {

}