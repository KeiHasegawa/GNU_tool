#ifndef SIM_MAIN_H
#define SIM_MAIN_H

#include "sim-basics.h"
#include "sim-base.h"

struct sim_state {
  sim_cpu *cpu[MAX_NR_PROCESSORS];
  sim_state_base base;
};

struct _sim_cpu {
  sim_cpu_base base;
};

#endif // SIM_MAIN_H
