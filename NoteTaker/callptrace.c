//
//  callptrace.c
//  NoteTaker
//
//  Created by Patrick Li on 7/18/17.
//  Copyright © 2017 Shane Doyle. All rights reserved.
//


#include "callptrace.h"
#include <stdio.h>
#import <dlfcn.h>
#import <sys/types.h>

typedef int (*ptrace_ptr_t)(int _request, pid_t _pid, caddr_t _addr, int _data);

#if !defined(PT_DENY_ATTACH)
#define PT_DENY_ATTACH 31
#endif

void callptrace(ptrace_ptr_t ptrace_ptr) {
    ptrace_ptr(PT_DENY_ATTACH, 0, 0, 0);
}
