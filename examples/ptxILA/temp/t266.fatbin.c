#include "fatBinaryCtl.h"
#define __CUDAFATBINSECTION  ".nvFatBinSegment"
#define __CUDAFATBINDATASECTION  ".nv_fatbin"
asm(
".section .nv_fatbin, \"a\"\n"
".align 8\n"
"fatbinData:\n"
".quad 0x00100001ba55ed50,0x00000000000007a8,0x0000004001010002,0x0000000000000568\n"
".quad 0x0000000000000000,0x0000001400010007,0x0000000000000000,0x0000000000000015\n"
".quad 0x0000000000000000,0x0000000000000000,0x33010102464c457f,0x0000000000000007\n"
".quad 0x0000005000be0002,0x0000000000000000,0x00000000000004c0,0x00000000000002c0\n"
".quad 0x0038004000140514,0x0001000800400003,0x7472747368732e00,0x747274732e006261\n"
".quad 0x746d79732e006261,0x746d79732e006261,0x78646e68735f6261,0x666e692e766e2e00\n"
".quad 0x2e747865742e006f,0x6950746f64335a5f,0x666e692e766e2e00,0x746f64335a5f2e6f\n"
".quad 0x732e766e2e006950,0x5a5f2e6465726168,0x2e006950746f6433,0x74736e6f632e766e\n"
".quad 0x335a5f2e30746e61,0x2e00006950746f64,0x6261747274736873,0x6261747274732e00\n"
".quad 0x6261746d79732e00,0x6261746d79732e00,0x2e0078646e68735f,0x006f666e692e766e\n"
".quad 0x6950746f64335a5f,0x5f2e747865742e00,0x006950746f64335a,0x6f666e692e766e2e\n"
".quad 0x50746f64335a5f2e,0x68732e766e2e0069,0x335a5f2e64657261,0x6e2e006950746f64\n"
".quad 0x6174736e6f632e76,0x64335a5f2e30746e,0x61705f006950746f,0x00000000006d6172\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x000700030000003b\n"
".quad 0x0000000000000000,0x0000000000000000,0x0006000300000070,0x0000000000000000\n"
".quad 0x0000000000000000,0x0007101200000032,0x0000000000000000,0x0000000000000098\n"
".quad 0x0000000300082304,0x0008120400000000,0x0000000000000003,0x0000000300081104\n"
".quad 0x00080a0400000000,0x0008002000000002,0x000c170400081903,0x0000000000000000\n"
".quad 0x00041e040021f000,0x000000000000000c,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x00005de400000000,0x84001c0428004404\n"
".quad 0x10015de22c000000,0x0401dc2318000000,0x80011ca3198ec000,0x90015ce3200b8000\n"
".quad 0xe00021e7208a8000,0x00409c8540000000,0x20401c8584000000,0xfc1fdc0384000000\n"
".quad 0xffffdc04207e0000,0x08009c0350ee0000,0x00409c8548000000,0x80001de794000000\n"
".quad 0xe0401c8540000000,0x00409c8587ffffff,0x00201c0384000000,0x00401c8548000000\n"
".quad 0x00001de794000000,0x0000000080000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000300000001,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000040,0x000000000000007e,0x0000000000000000\n"
".quad 0x0000000000000001,0x0000000000000000,0x000000030000000b,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000000000000be,0x000000000000008e,0x0000000000000000\n"
".quad 0x0000000000000001,0x0000000000000000,0x0000000200000013,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000150,0x0000000000000060,0x0000000200000002\n"
".quad 0x0000000000000008,0x0000000000000018,0x7000000000000029,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000000000001b0,0x0000000000000024,0x0000000000000003\n"
".quad 0x0000000000000004,0x0000000000000000,0x7000000000000041,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000000000001d4,0x0000000000000028,0x0000000700000003\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000100000067,0x0000000000000002\n"
".quad 0x0000000000000000,0x00000000000001fc,0x0000000000000028,0x0000000700000000\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000100000032,0x0000000000100006\n"
".quad 0x0000000000000000,0x0000000000000224,0x0000000000000098,0x0600000300000003\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000500000006,0x00000000000004c0\n"
".quad 0x0000000000000000,0x0000000000000000,0x00000000000000a8,0x00000000000000a8\n"
".quad 0x0000000000000008,0x0000000500000001,0x00000000000001fc,0x0000000000000000\n"
".quad 0x0000000000000000,0x00000000000000c0,0x00000000000000c0,0x0000000000000008\n"
".quad 0x0000000600000001,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000008,0x0000004801010001\n"
".quad 0x00000000000001b8,0x00000040000001b0,0x0000001400050000,0x0000000000000000\n"
".quad 0x0000000000002015,0x0000000000000000,0x000000000000028c,0x0000000000000000\n"
".quad 0x762e1cf200010a13,0x35206e6f69737265,0x677261742e0a302e,0x30325f6d73207465\n"
".quad 0x7365726464612e0a,0x3620657a69735f73,0x69736914f5002f34,0x746e652e20656c62\n"
".quad 0x6f64335a5f207972,0x61702e0a28695074,0x3436752e206d6172,0x09f300145f110016\n"
".quad 0x2e0a7b0a290a305f,0x6572702e20676572,0x3b3e323c70252064,0x2520323362960012\n"
".quad 0x00f2001231313c72,0x353c647225203436,0x5b646c0a0a0a3b3e,0x324c0017752e2200\n"
".quad 0x5d02f400615b202c,0x742e617476630a3b,0x6c61626f6c672e6f,0x7100332c3321002d\n"
".quad 0x6a752e766f6d0a3b,0x7425202c380cf200,0x65730a3b782e6469,0x33732e656c2e7074\n"
".quad 0x001e2c3170250932,0x2e6c756d0a3b31a1,0x004100001a646977,0x0a3b3482001b3413\n"
".quad 0x26005d732e646461,0x3b340bf100632c31,0x726220317025400a,0x3b315f3042422061\n"
".quad 0x696e752e6172620a,0x170a0a3b3241000f,0x00a40400d03a1000,0x5b202c3140005d01\n"
".quad 0x13001b3b5d2d004d,0x5d382b00f3001b32,0x79732e7261620a3b,0x3e0200853020636e\n"
".quad 0x257800292c302200,0x004174730a3b3172,0x301a001b01005702,0x00900a3b3332008f\n"
".quad 0x007534140090321e,0x3516000093382d2f,0x100087090a2c00ae,0x0b0087341f000535\n"
".quad 0x720a3a33c0007903,0x0a0a0a7d0a3b7465,0x0000000000000000\n"
".text\n");
#ifdef __cplusplus
extern "C" {
#endif
extern const unsigned long long fatbinData[247];
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
static const __fatBinC_Wrapper_t __fatDeviceText __attribute__ ((aligned (8))) __attribute__ ((section (__CUDAFATBINSECTION)))= 
	{ 0x466243b1, 1, fatbinData, 0 };
#ifdef __cplusplus
}
#endif