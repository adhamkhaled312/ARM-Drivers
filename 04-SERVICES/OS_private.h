/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 9 July 2024                            */
/* Version   : V01                                    */
/******************************************************/
#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

#define 		NULL 					(0)

#define			TASK_SUSPENDED			1

#define			TASK_READY				2


typedef struct
{
	u16 Period;
	void (*TaskHandler)(void);
	u16	firstDelay;
	u8 State;
}Task;

static Task OStasks[NUM_OF_TASKS] = {NULL};


static void SCHEDULER(void);

#endif
