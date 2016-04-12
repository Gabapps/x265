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

#define PATH8 "profiling_8.txt"
#define PATH16 "profiling_16.txt"
#define PATH32 "profiling_32.txt"

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
std::vector<long_long> profile_cu8time;
std::vector<long_long> profile_cu16time;
std::vector<long_long> profile_cu32time;

void profile_open();
void profile_close();

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

#endif /* ENCODER_PROFILING_H_ */

#endif
