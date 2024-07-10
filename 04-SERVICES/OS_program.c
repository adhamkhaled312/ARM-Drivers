/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 9 July 2024                            */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"


void SOS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay)
{
	OStasks[Copy_u8TaskID].Period = period;
	OStasks[Copy_u8TaskID].TaskHandler = ptr;
	OStasks[Copy_u8TaskID].firstDelay = Copy_u16firstDelay;
	OStasks[Copy_u8TaskID].State = TASK_READY;
}

void SOS_voidStart(void)
{
	MSTK_voidInit();

	/*when HSE=8Mhz , sytem tick is 1ms*/
	MSTK_voidSetIntervalPeriodic(1000 , SCHEDULER );

}

void SOS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_SUSPENDED;
}

void SOS_voidResumeTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_READY;
}

void SOS_voidDeleteTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].TaskHandler=NULL;
}

static void SCHEDULER(void)
{
	//static u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;
	/*Increment of Scheduler tick counter*/

		/*Loop on the tasks*/
		for(Local_u8TaskCounter=0;Local_u8TaskCounter<NUM_OF_TASKS;Local_u8TaskCounter++)
		{
			/*chack that task isn't deleted or suspended */
			if((OStasks[Local_u8TaskCounter].TaskHandler != NULL) && (OStasks[Local_u8TaskCounter].State == TASK_READY) )
			{
				/*Check until the first delay equal to zero*/
				if(OStasks[Local_u8TaskCounter].firstDelay == 0)
				{
					OStasks[Local_u8TaskCounter].firstDelay=OStasks[Local_u8TaskCounter].Period-1;
					/*Invoke the task function*/
					OStasks[Local_u8TaskCounter].TaskHandler();
				}
				else
				{
					/*Decrement the first delay*/
					OStasks[Local_u8TaskCounter].firstDelay--;
				}
			}
			else
			{
				/*Do nothing*/
			}
		}
}