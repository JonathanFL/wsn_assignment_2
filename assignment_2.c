#include "dct_utilities.h"
#define LOG_MODULE "Assignment2 Log Module"
#define LOG_LEVEL LOG_LEVEL_DBG

/*---------------------------------------------------------------------------*/
PROCESS(dct_process, "Compute dct");
AUTOSTART_PROCESSES(&dct_process);

/*-----------------------------------PROCESSES----------------------------------------*/

PROCESS_THREAD(dct_process, ev, data)
{
  PROCESS_BEGIN();
  clock_init();
  ulong_t t1;
  ulong_t t2;
  ulong_t execution_time;

  SENSORS_ACTIVATE(button_sensor);
  while (1)
  {
    printf("Press any button to calculate the dct of the constant egc signal\n");
    PROCESS_WAIT_EVENT_UNTIL(ev == sensors_event && data == &button_sensor);
    //energest_flush(); // maybe to be used for power consumption
    t1 = clock_seconds();
    dct();
    t2 = clock_seconds();
    execution_time = t2-t1;
    execution_time = to_minutes(execution_time);
    printf("Execution time: %lu minutes\n", (ulong_t)(execution_time));
    printf("Energy consumption: %lu mA\n", energy_consumption(execution_time));
    printf("Transformed signal:\n");
    print_array(transformed_signal);
  }
  PROCESS_END();
}