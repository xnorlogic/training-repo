#include "Std_types.h"
#include "CntConfigurable.h"
#include "CntConfigurable_cfg.h"

#ifdef COUNT_GLOBAL_VALUE
	/*Global declaration for the counter value*/
	#ifdef CONFIG_CNT_UP
		/*Counter increment*/
		int ThisCounter = COUNT_UP_RESET_VALUE;
	#else
		/*Counter decrement*/
		int ThisCounter = COUNT_DOWN_RESET_VALUE;	
	#endif
	#else
	/*No global for the counter value*/
#endif

int CntConfigurable(void)
{
	static int CounterCompleteFlag = FALSE;
	
	#ifdef COUNT_GLOBAL_VALUE
		/*Global declaration for the counter value*/
	#else
	    /*No global for the counter value*/
		#ifdef CONFIG_CNT_UP
	        /*Counter increment*/
			static int ThisCounter = COUNT_UP_RESET_VALUE;
		#else
			/*Counter decrement*/
			static int ThisCounter = COUNT_DOWN_RESET_VALUE;	
		#endif
	#endif

	#ifdef CONFIG_CNT_UP
		/*Counter increment*/
		if(ThisCounter >= COUNT_UP_THRESHOLD)
		{
			ThisCounter = ThisCounter + COUNT_UP_STEP;
			/*To-do: add some code to review status of the counter*/
		}
		else
		{
			ThisCounter = COUNT_UP_RESET_VALUE;
			CounterCompleteFlag = TRUE;
		}
	#else
		/*Counter decrement*/
		if(ThisCounter == COUNT_DOWN_THRESHOLD)
		{
			ThisCounter = ThisCounter - COUNT_DOWN_STEP;
		}
		else
		{
			ThisCounter = COUNT_DOWN_RESET_VALUE;
			CounterCompleteFlag = TRUE;
		}
	#endif

	return CounterCompleteFlag;
}
