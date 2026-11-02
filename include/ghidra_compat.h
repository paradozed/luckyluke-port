#ifndef GHIDRA_COMPAT_H
#define GHIDRA_COMPAT_H

#include <windows.h>
#include <stdint.h>
#include <stddef.h>

/* --- Ghidra "undefined" types (untyped, sized) --------------------- */
typedef unsigned char       undefined1;   /* 8-bit  */
typedef unsigned short      undefined2;   /* 16-bit */
typedef unsigned int        undefined3;   /* 24-bit value stored in 32 bits */
typedef unsigned int        undefined4;   /* 32-bit */
typedef unsigned long long  undefined5;   /* 40-bit value stored in 64 bits */
typedef unsigned long long  undefined8;   /* 64-bit */
typedef void                undefined;    /* untyped (used as undefined * = void *) */

/* Ghidra shorthand types used throughout the decompiled output */
typedef unsigned int        uint;         /* unsigned int */
typedef unsigned short      ushort;       /* unsigned short */
typedef unsigned char       uchar;        /* unsigned char */
typedef unsigned char       byte;         /* 8-bit byte */
typedef unsigned long long  ulonglong;    /* unsigned 64-bit */
typedef long long           longlong;     /* signed 64-bit */
typedef long double         float10;      /* 80-bit x87 float */

/* Windows / SEH types used in Ghidra signatures */
typedef void *EHExceptionRecord;
typedef void *EHRegistrationNode;
typedef void *_CONTEXT;
typedef struct _WIN32_FIND_DATAA _WIN32_FIND_DATAA;
typedef struct tagCHOOSECOLORA tagCHOOSECOLORA;
typedef struct tagPAINTSTRUCT tagPAINTSTRUCT;
typedef struct tagMSG tagMSG;
typedef signed char sbyte;

/* Windows / SEH types used in Ghidra signatures */
typedef void *_s_FuncInfo;
typedef void *_exception;

/* Ghidra cast types used in expressions like (int3)x / (uint3)x */
typedef int                 int3;         /* 24-bit signed */
typedef unsigned int        uint3;        /* 24-bit unsigned */

/* Ghidra emits (ghidra_code_fn **) casts for indirect calls through
 * pointers. ghidra_code_fn is variadic so any argument count works.     */
typedef int ghidra_code_fn(...);

/* --- Calling conventions (x86) ------------------------------------ */
#ifndef __cdecl
# define __cdecl
#endif
#ifndef __stdcall
# define __stdcall
#endif
#ifndef __fastcall
# define __fastcall
#endif
#ifndef __thiscall
# define __thiscall
#endif

/* --- Ghidra intrinsics -------------------------------------------- */
/* CARRY1(a,b): carry out of an 8-bit addition. Returns 0 or 1.        */
#define CARRY1(a,b) (((unsigned char)(a) + (unsigned char)(b)) > 0xFF ? 1u : 0u)

/* __chkesp(): stack-pointer consistency check (debug build).
 * Return 0 so it can be used in expressions (e.g. uVar1 = __chkesp();). */
#define __chkesp() (0)

/* CONCATxy(a,b): concatenate x bytes of a with y bytes of b.
 * Result width = (x + y) bytes. Simplified to avoid cast issues.       */
#define CONCAT11(a,b) (((unsigned char)(a) & 0xFFu) | ((unsigned short)((unsigned char)(b) & 0xFFu) << 8))
#define CONCAT12(a,b) (((unsigned char)(a) & 0xFFu) | ((unsigned int)((unsigned short)(b) & 0xFFFFu) << 8))
#define CONCAT13(a,b) (((unsigned char)(a) & 0xFFu) | ((unsigned int)((unsigned int)(b) & 0xFFFFFFu) << 8))
#define CONCAT14(a,b) (((unsigned char)(a) & 0xFFu) | ((unsigned long long)((unsigned int)(b) & 0xFFFFFFFFu) << 8))
#define CONCAT21(a,b) (((unsigned short)(a) & 0xFFFFu) | ((unsigned int)((unsigned char)(b) & 0xFFu) << 16))
#define CONCAT22(a,b) (((unsigned short)(a) & 0xFFFFu) | ((unsigned int)((unsigned short)(b) & 0xFFFFu) << 16))
#define CONCAT24(a,b) (((unsigned short)(a) & 0xFFFFu) | ((unsigned long long)((unsigned int)(b) & 0xFFFFFFFFu) << 16))
#define CONCAT28(a,b) (((unsigned short)(a) & 0xFFFFu) | ((unsigned long long)(b) << 16))
#define CONCAT31(a,b) (((unsigned int)(a) & 0xFFFFFFu) | ((unsigned int)((unsigned char)(b) & 0xFFu) << 24))
#define CONCAT44(a,b) (((unsigned long long)(a) << 32) | ((unsigned long long)(b) & 0xFFFFFFFFull))

/* --- SEH exception list ------------------------------------------ */
extern void *ExceptionList;

#endif /* GHIDRA_COMPAT_H */