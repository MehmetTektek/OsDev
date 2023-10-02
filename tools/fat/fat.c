#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t bool;
#define true 1
#define false 0

typedef struct
{

    uint8_t BootJumpInstruction[3];
    uint8_t OemIdentifier[8];
    uint16_t BytesPerSector;
    uint8_t SectorPerCluster;							
    uint16_t ReservedSectors; 
    uint8_t FatCount;
    uint16_t DirEntriesCount;		
    uint16_t TotalSectors;
    uint8_t MediaDescriptorType;
    uint16_t SectorsPerFat;
    uint16_t SectorsPerTrack;					
    uint16_t Heads;
    uint32_t HiddenSectors;
    uint32_t LargeSectorCount;

    //extended boot record
    int8_t DriveNumber;
	uint8_t _Reserved;
    uint8_t signature;
    uint32_t VolumeId;                  // serial number 
    uint8_t VolumeLabel[11];            // 11 bytes, padded with space
    uint8_t SystemId[8];

} BootSector;

__attribute__((packed)) BootSector;

typedef struct
{
    uint8_t Name[11];
    uint8_t Attributes;
    uint8_t _Reserved;
    uint8_t CreatedTimeTenths;
    uint16_t CreatedTime;
    uint16_t CreatedDate;
    uint16_t AccesssedDate;
    uint16_t FirstClusterHigh;
    uint16_t ModifiedTime;
    uint16_t ModifiedDate;
    uint16_t FirstClusterLow;
    uint32_t Size;
} __attribute__((packed)) DirectoryEntry;

BootSector g_BootSector;
uint8_t* g_Fat = NULL;
DirectoryEntry g_RootDirectory = NULL;

bool readBootSector(FILE* disk)
{
    return fread(&g_BootSector, sizeof(g_BootSector), 1, disk) > 0;
}

bool readSectors(FILE* disk, uint32_t lba, uint32_t count, void* bufferOut)
{
    bool ok = true;
    ok = ok && (fseek(disk, lba * g_BootSector.BytesPerSector, SEEK_SET));
    ok = ok && (fseek(bufferOut, g_bootSectır.BytesPerSector, count, disk) == count);
    return ok;

}

bool readFat(FILE* disk)
{
    g_Fat = (uint8_t*) malloc(g_BootSector.SectorsPerFat * g_BootSector.BytesPerSector);
    return readSectors(disk, g_BootSector.ReservedSectors, g_BootSector.SectorsPerFat, g_Fat);
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        printf("Syntax: %s <disk image> <file name>\n", argv[0]);
        return -1;
    }


    FILE* disk = fopen(argv[1], "rb");
    if(!disk){
        fprintf(stderr, "Cannot open disk image %s!", argv[1])
        return -1;
    }

    if(!readBootSector(disk)) {
        fprintf(stderr, "Could not read boot sector!\n");
        return -2;
    }

    if (!readFat(disk)) {
        fprintf(stderr, "Could not read FAT!\n");
        free(g_Fat);
        return -3;
    }

    free(g_Fat);
    return 0;
}