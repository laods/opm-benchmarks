// Date: 2013-04-25 08:35:45 MDT
// This file is created from createInputDataFiles.sh.
// It contains input data and reference solution stored as strings.
// To be included in upscale_relperm_benchmark.

static const char* ECLIPSEFILENAME = "benchmark_tiny.grdecl";
static const char* ROCKFILENAME = "stonefile_benchmark.txt";
static const char* REFERENCEFILENAME = "benchmark_tiny_upscaled_relperm_20points.txt";

#define EXTERN_FILE(type,name,file) \
  __asm__ (               \
    ".global " #name "\n" \
    ".data\n"             \
    ".p2align 3\n"        \
    "1:\n"                \
    ".incbin " #file "\n" \
    ".byte 0, 0\n"        \
    ".p2align 3\n"        \
    #name ":\n"           \
    ".int 1b\n"           \
    );                    \
  extern type *name

EXTERN_FILE(const char,eclipseInput,"../benchmarks/input/benchmark_tiny.grdecl");
EXTERN_FILE(const char,stone_string,"../benchmarks/input/stonefile_benchmark.txt");
EXTERN_FILE(const char,result_string,"../benchmarks/input/benchmark_tiny_upscaled_relperm_20points.txt");
