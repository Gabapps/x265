/*
 * Profiling.h
 *
 *  Created on: 22 mars 2016
 *      Author: gab
 */

#ifdef PROFILING

#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <papi.h>

#ifndef ENCODER_PROFILING_H_
#define ENCODER_PROFILING_H_

#define PROFILING_FOLDER "./"

#define PATH8 PROFILING_FOLDER"profiling_8.txt"
#define PATH16 PROFILING_FOLDER"profiling_16.txt"
#define PATH32 PROFILING_FOLDER"profiling_32.txt"

typedef long_long profile_type;

/*
#pragma pack(push)
#pragma pack(1)

struct Profile_data {
	clock_t cu8time;
	clock_t cu16time;
	clock_t cu32time;
};

#pragma pack(pop)
*/

FILE* profile_file1 = NULL;
FILE* profile_file2 = NULL;
FILE* profile_file3 = NULL;
std::vector<profile_type> profile_cu8time;
std::vector<profile_type> profile_cu16time;
std::vector<profile_type> profile_cu32time;

void profile_open();
void profile_close();
void profile_write();

void profile_open() {
	if(!profile_file1) {
		profile_file1 = fopen(PATH8, "ab+");
		profile_file2 = fopen(PATH16, "ab+");
		profile_file3 = fopen(PATH32, "ab+");
		profile_cu8time.reserve(4096);
		profile_cu16time.reserve(4096);
		profile_cu32time.reserve(4096);
		if(PAPI_library_init(PAPI_VER_CURRENT) != PAPI_VER_CURRENT) {}
	}
}

void profile_close() {
	if(profile_file1) {
		fclose(profile_file1);
		fclose(profile_file2);
		fclose(profile_file3);
		profile_file1 = NULL;
	}
}

void profile_write() {
	fwrite(&profile_cu8time.front(), profile_cu8time.size(), sizeof(profile_type), profile_file1);
	fwrite(&profile_cu16time.front(), profile_cu16time.size(), sizeof(profile_type), profile_file2);
	fwrite(&profile_cu32time.front(), profile_cu32time.size(), sizeof(profile_type), profile_file3);

	profile_cu8time.clear();
	profile_cu16time.clear();
	profile_cu32time.clear();
}

#endif /* ENCODER_PROFILING_H_ */

#endif
