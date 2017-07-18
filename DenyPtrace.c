//
//  DenyPtrace.c
//  NoteTaker
//
//  Created by Patrick Li on 7/17/17.
//  Copyright © 2017 Shane Doyle. All rights reserved.
//


#include <stdio.h>
#import <dlfcn.h>
#import <sys/types.h>

typedef int (*ptrace_ptr_t)(int _request, pid_t _pid, caddr_t _addr, int _data);
#if !defined(PT_DENY_ATTACH)
#define PT_DENY_ATTACH 31
#endif

void callptrace(ptrace_ptr_t ptrace_ptr);

void disable_gdb() {
    void* handle = dlopen(0, RTLD_GLOBAL | RTLD_NOW);
    ptrace_ptr_t ptrace_ptr = dlsym(handle, "ptrace");
    callptrace(ptrace_ptr);
    dlclose(handle);
}





