#pragma once
#include <string>
#include <stdlib.h>
int& current_page();
std::string& current_filename();
void save_page_numbers(const std::string& filename = std::string(getenv("HOME")) + "/.xpdf/pagenumbers.txt");
void load_page_numbers(const std::string& filename = std::string(getenv("HOME")) + "/.xpdf/pagenumbers.txt");
