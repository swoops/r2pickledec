#ifndef DUMP_PICKLE
#define DUMP_PICKLE
#include "pyobjutil.h"
#include <stdbool.h>

typedef struct print_state {
	bool first, ret, prepend;
	int tabs;
	RStrBuf *out; // where  script is stored
} PrState;

typedef struct print_info {
	RCons *cons;
	bool stack, popstack, metastack; // input from user

	PyObj *reduce;

	RFlag *flags;
	bool setflags;

	bool stack_start; // first on stack
	RConsPrintablePalette *pal;

	ut64 recurse;
	bool verbose;

	RList /*PrState* */*outstack;
} PrintInfo;

bool dump_obj(PrintInfo *nfo, PyObj *obj);
bool dump_machine(PMState *pvm, PrintInfo *nfo, bool warn);
void print_info_clean(PrintInfo *nfo);
bool print_info_init(PrintInfo *nfo, ut64 recurse, RCore *core);
#endif
