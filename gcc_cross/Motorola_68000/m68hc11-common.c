#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tm_p.h"
#include "common/common-target.h"
#include "common/common-target-def.h"
#include "opts.h"
#include "flags.h"

static const default_options m68hc11_option_optimization_table[] = {
  { OPT_LEVELS_NONE, 0, nullptr, 0 }
};

unwind_info_type m68hc11_except_unwind_info(gcc_options *opts)
{
  return UI_SJLJ;
}

const char* m68hc11_rewrite_selected_cpu(const char* name)
{
  asm("int3");
  return nullptr;
}

const char*
m68hc11_rewrite_mcpu (int argc, const char **argv)
{
  asm("int3");
  return nullptr;
}

#undef  TARGET_DEFAULT_TARGET_FLAGS
#define TARGET_DEFAULT_TARGET_FLAGS TARGET_DEFAULT

#undef  TARGET_OPTION_OPTIMIZATION_TABLE
#define TARGET_OPTION_OPTIMIZATION_TABLE m68hc11_option_optimization_table

#undef TARGET_EXCEPT_UNWIND_INFO
#define TARGET_EXCEPT_UNWIND_INFO  m68hc11_except_unwind_info

gcc_targetm_common targetm_common = TARGETM_COMMON_INITIALIZER;
