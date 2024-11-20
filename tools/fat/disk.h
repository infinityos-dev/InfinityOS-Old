#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define far

typedef struct {
    FILE* File;
} DISK;

bool DISK_Initialize(DISK* disk, const char* fileName);
bool DISK_ReadSectors(DISK* disk, uint32_t lba, uint8_t sectors, void far* dataOut);
