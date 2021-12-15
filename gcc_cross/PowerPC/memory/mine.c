#include "config.h"
#include "sim-main.h"

static void
free_state (SIM_DESC sd)
{
  if (STATE_MODULES (sd) != NULL)
    sim_module_uninstall (sd);
  sim_cpu_free_all (sd);
  sim_state_free (sd);
}

sim_cia my_pc_fetch(sim_cpu* cpu)
{
  asm("int3");
}

void my_pc_store(sim_cpu* cpu, sim_cia addr)
{
  cpu_set_program_counter(cpu->handle, addr);
}

SIM_DESC
sim_open (SIM_OPEN_KIND kind,
	  struct host_callback_struct *callback,
	  struct bfd *abfd, char * const *argv)
{
  SIM_DESC sd = sim_state_alloc(kind, callback);

  if (sim_cpu_alloc_all(sd, 1, 0) != SIM_RC_OK) {
    free_state(sd);
    return 0;
  }

  if (sim_pre_argv_init (sd, argv[0]) != SIM_RC_OK) {
    free_state (sd);
    return 0;
  }

  if (sim_parse_args (sd, argv) != SIM_RC_OK) {
    free_state (sd);
    return 0;
  }

  if (sim_analyze_program (sd,
			   (STATE_PROG_ARGV (sd) != NULL
			    ? *STATE_PROG_ARGV (sd)
			    : NULL),
			   abfd) != SIM_RC_OK) {
    free_state (sd);
    return 0;
  }
  
  if (sim_config (sd) != SIM_RC_OK) {
    free_state (sd);
    return 0;
  }

  if (sim_post_argv_init (sd) != SIM_RC_OK) {
    free_state (sd);
    return 0;
  }

  sim_cpu* cpu = sd->cpu[0];
  cpu->handle = cpu_create(0, 0, 0, 0, 0);
  
  CPU_PC_FETCH(cpu) = my_pc_fetch;
  CPU_PC_STORE(cpu) = my_pc_store;

  return sd;
}

SIM_RC
sim_create_inferior (SIM_DESC sd,
		     struct bfd *abfd,
		     char * const *argv,
		     char * const *envp)
{
  cpu_set_program_counter(sd->cpu[0]->handle, bfd_get_start_address (abfd));
  return SIM_RC_OK;
}

SIM_DESC g_sd;

void
sim_engine_run (SIM_DESC sd,
		int next_cpu_nr ATTRIBUTE_UNUSED,
		int nr_cpus ATTRIBUTE_UNUSED,
		int siggnal ATTRIBUTE_UNUSED)
{
  g_sd = sd;
  void* handle = sd->cpu[0]->handle;
  idecode_run(0, 0, &handle, 1);
}

uint32_t vm_instruction_map_read(void* map,
				 void* processor,
				 unsigned_word cia)
{
  return sim_core_read_aligned_4(g_sd->cpu[0], cia, read_map, cia);
}

void vm_data_map_write_1(void *map,
			 unsigned_word ea,
			 unsigned_1 val,
			 void *processor,
			 unsigned_word cia)
{
  sim_core_write_aligned_1(g_sd->cpu[0], cia, write_map, ea, val);
}

void vm_data_map_write_2(void *map,
			 unsigned_word ea,
			 unsigned_2 val,
			 void *processor,
			 unsigned_word cia)
{
  sim_core_write_aligned_2(g_sd->cpu[0], cia, write_map, ea, val);
}

void vm_data_map_write_4(void *map,
			 unsigned_word ea,
			 unsigned_4 val,
			 void *processor,
			 unsigned_word cia)
{
  sim_core_write_aligned_4(g_sd->cpu[0], cia, write_map, ea, val);
}

void vm_data_map_write_8(void *map,
			 unsigned_word ea,
			 unsigned_8 val,
			 void *processor,
			 unsigned_word cia)
{
  sim_core_write_aligned_8(g_sd->cpu[0], cia, write_map, ea, val);
}

unsigned_1
vm_data_map_read_1(void* map,
		   unsigned_word ea,
		   void* processor,
		   unsigned_word cia)
{
  return sim_core_read_aligned_1(g_sd->cpu[0], cia, read_map, ea);
}

unsigned_2
vm_data_map_read_2(void* map,
		   unsigned_word ea,
		   void* processor,
		   unsigned_word cia)
{
  return sim_core_read_aligned_2(g_sd->cpu[0], cia, read_map, ea);
}

unsigned_4
vm_data_map_read_4(void* map,
		   unsigned_word ea,
		   void* processor,
		   unsigned_word cia)
{
  return sim_core_read_aligned_4(g_sd->cpu[0], cia, read_map, ea);
}

unsigned_8
vm_data_map_read_8(void* map,
		   unsigned_word ea,
		   void* processor,
		   unsigned_word cia)
{
  return sim_core_read_aligned_8(g_sd->cpu[0], cia, read_map, ea);
}

void cpu_halt(void* processor,
	      unsigned_word nia,
	      int reason,
	      int signal)
{
  switch (reason) {
  case 1:
    sim_engine_halt(g_sd, g_sd->cpu[0], 0, nia, sim_stopped, 66);
    break;
  default:
    asm("int3");
  }
}

int
sim_fetch_register (SIM_DESC sd, int regno, unsigned char *buf, int length)
{
  const char *regname = regnum2name (regno);
  if (!regname)
    return -1;
  return psim_read_register(sd->cpu[0]->handle, MAX_NR_PROCESSORS,
			    buf, regname, 1);
}

int
sim_store_register (SIM_DESC sd, int regno, unsigned char *buf, int length)
{
  const char *regname = regnum2name (regno);
  if (!regname)
    return 0;
  return psim_write_register(sd->cpu[0]->handle, MAX_NR_PROCESSORS,
			     buf, regname, 1);
}

 
