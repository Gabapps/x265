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
#include <cstring>
#include <time.h>
#include <papi.h>
#include <pthread.h>

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

pthread_mutex_t mut;

FILE* profile_file1 = NULL;
FILE* profile_file2 = NULL;
FILE* profile_file3 = NULL;
std::vector<profile_type> profile_cu8time;
std::vector<profile_type> profile_cu16time;
std::vector<profile_type> profile_cu32time;

void profile_open();
void profile_close();
void profile_write();

void profile_lock();
void profile_unlock();

void profile_open() {
	if(!profile_file1) {
		profile_file1 = fopen(PATH8, "wb+");
		profile_file2 = fopen(PATH16, "wb+");
		profile_file3 = fopen(PATH32, "wb+");
		profile_cu8time.resize(64);
		profile_cu16time.resize(16);
		profile_cu32time.resize(4);
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

	memset(&profile_cu8time.front(), 0, profile_cu8time.size()*sizeof(profile_type));
	memset(&profile_cu16time.front(), 0, profile_cu16time.size()*sizeof(profile_type));
	memset(&profile_cu32time.front(), 0, profile_cu32time.size()*sizeof(profile_type));
}

void profile_lock() {
	pthread_mutex_lock(&mut);
}
void profile_unlock() {
	pthread_mutex_unlock(&mut);
}

#endif /* ENCODER_PROFILING_H_ */

#endif
