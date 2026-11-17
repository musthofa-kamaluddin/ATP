#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct vbmeta_hdr {
    char magic[4];
    uint32_t version_major;
    uint32_t version_minor;
    uint32_t auth_block_size;
    uint32_t aux_block_size;
    char release_string[16];
};

int main(){
    struct vbmeta_hdr hdr;
    char label[64], tmp[64];

    scanf("%s", label);
    scanf("%s %s", label, tmp);
    memcpy(hdr.magic, tmp, 4);
    
    scanf("%s %u", label, &hdr.version_major);
    scanf("%s %u", label, &hdr.version_minor);
    scanf("%s %u", label, &hdr.auth_block_size);
    scanf("%s %u", label, &hdr.aux_block_size);
   
    scanf("%s %s", label, tmp);
    strncpy(hdr.release_string, tmp, 16);

    scanf("%s", label);

    if(strncmp(hdr.magic, "AVB0", 4) != 0){
        printf("ERROR: Invalid vbmeta magic!");
        return 0;
    }

    if(hdr.version_major != 1 || hdr.version_minor > 3){
        printf("ERROR: Unsupported libavb version!");
        return 0;
    }

    if(hdr.release_string[15] != '\0'){
        printf("ERROR: Release string does not end with NUL!");
        return 0;
    }

    if(hdr.auth_block_size % 64 != 0 || hdr.aux_block_size % 64 != 0){
        printf("ERROR: Block size is not a multiple of 64!");
        return 0;
    }

    printf("Release: %s\n", hdr.release_string);
    printf("Version: %u.%u\n", hdr.version_major, hdr.version_minor);
    printf("Auth block: %u bytes\n", hdr.auth_block_size);
    printf("Aux block: %u bytes\n", hdr.aux_block_size);
    printf("Total: %u bytes\n", 256 + hdr.auth_block_size + hdr.aux_block_size);
    printf("STATUS: VBMETA OK");
    return 0;
}