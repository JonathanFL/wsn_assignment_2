#include "dct_utilities.h"

/*---------------------------------------------------------------------------*/
PROCESS(dct_process, "Compute dct");
AUTOSTART_PROCESSES(&dct_process);

/*-----------------------------------PROCESSES----------------------------------------*/

PROCESS_THREAD(dct_process, ev, data)
{
  PROCESS_BEGIN();
  LOG_DBG("START - Transforming signal \n");
  clock_init();
  unsigned long t1;
  unsigned long t2;
  unsigned long execution_time;
  LOG_DBG("N = %d and M = %d\n", _N, _M);
  t1 = clock_seconds();
  dct();
  t2 = clock_seconds();
  execution_time = t2-t1;
  printf("Energy consumption: %lu mA\n", (unsigned long)energy_consumption(execution_time));
  to_minutes(&execution_time);
  printf("Execution time: %lu minutes\n", (unsigned long)(execution_time));
  printf("Transformed signal:\n");
  print_array(transformed_signal, _N);
  LOG_DBG("END - Process stopped\n");
  PROCESS_END();
}