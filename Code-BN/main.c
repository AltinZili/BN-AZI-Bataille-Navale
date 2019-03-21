#include <stdio.h>

#define size 4
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center

void topborder(int si) {
    printf("%c", STLC);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHTB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHTB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", STRC);
}

void horizontalborder(int si) {
    printf("%c", SVLB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SC);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SC);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SHSB);
    printf("%c", SC);



}

void verticalborder(int si) {}

void bottomborder(int si) {}


void affgrille() {
    topborder(size);
    for (int row = 0; row<size; row++) {
        if (row > 0) {
            horizontalborder(size);
        }
        verticalborder(size);
    }
    bottomborder(size);
};

int main() {
    affgrille();
}