#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ioe.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "error.h"


SemaphoreHandle_t sync_module_semaphore;
QueueHandle_t response_job_queue, request_job_queue,
			  drop_msg_queue, blending_msg_queue, sealing_msg_queue;

void prvInit()
{
	//LCD Init
	LCD_Init();
	IOE_Config();
	LTDC_Cmd( ENABLE );

	LCD_LayerInit();
	LCD_SetLayer( LCD_FOREGROUND_LAYER );
	LCD_Clear( LCD_COLOR_BLACK );
	LCD_SetTextColor( LCD_COLOR_WHITE );
}

/*
void commandControllerTask(void *pvParameters)
{
	DrinkItem todo_drink[10];
	int i, jobReqMsgFromMachine;
	xQueueReceive(request_job_queue, &jobReqMsgFromMachine, portMAX_DELAY);
	if (jobReqMsgFromMachine == 1) {
		// send out job from to-do drink list;
		xQueueSend(response_job_queue, &todo_drink[0], portMAX_DELAY);
		
		for (i=0; i<9; i++) {
			todoDrink[i] = todoDrink[i+1];
		}
	}
}

void rotateConveyor()
{
	//rotating~~
}

void machineControllerTask(void *pvParameters)
{
	DrinkItem dropping, blending, sealing;
	while (1) {
		//Wait -- wait until all semaphore give back
		xSemaphoreTake(sync_module_semaphore, portMAX_DELAY);
		xSemaphoreTake(sync_module_semaphore, portMAX_DELAY);
		xSemaphoreTake(sync_module_semaphore, portMAX_DELAY);
		
		//Dispatch -- get job and dispatch to all the task
		int reqMsg = 1;
		DrinkItem job;
		xQueueSend(request_job_queue, &reqMsg, portMAX_DELAY);
		xQueueReceive(response_job_queue, &job, portMAX_DELAY);	
		
		//report sealing drink has been done 

		//pipeline;
		sealing = blending;
		blending = dropping;
		dropping = job;
		
		//Rotate -- rotate the conveyor
		rotateConveyor();

		//execute job
	}
}

void dropCupControllerTask(void *pvParameters)
{
	// Wait until Job
	int drop_msg;
	xQueueReceive(drop_msg_queue, &drop_msg, portMAX_DELAY);
	
	if (drop_msg == 1) {
		// drop a cup;
	}
	
	//in the end, report back job done;
	xSemaphoreGive(sync_module_semaphore);
}

void blenderControllerTask(void *pvParameters)
{
	//do their job
	//in the end, report back job done;
	xSemaphoreGive(sync_module_semaphore);
}

void sealingControllerTask(void *pvParameters)
{
	//do their job
	//in the end, report back job done;
	xSemaphoreGive(sync_module_semaphore);
}


void module_init() {
	// initialize machine controller and command controller message queue; 
	request_job_queue = xQueueCreate(1, sizeof(DrinkItem));
	if (request_job_queue == 0) {
		reportError("request_job_queue cannot create");
	}
	response_job_queue = xQueueCreate(1, sizeof(int));
	if (response_job_queue == 0) {
		reportError("response_job_queue cannot create");
	}
	// initialize semaphore for synchronization of module and machine controller; 
	sync_module_semaphore = xSemaphoreCreateCouning(3, 3);
	if (sync_module_semaphore == NULL) {
		reportError("sync_module_semaphore cannot create");
	}
	// initialize message queue between module and machine controller; 
	drop_msg_queue = xQueueCreate(1, sizeof(int));
	if (drop_msg_queue == 0) {
		reportError("drop_msg_queue cannot create");
	}
	blending_msg_queue = xQueueCreate(1, sizeof(int));
	if (blending_msg_queue == 0) {
		reportError("blending_msg_queue cannot create");
	}
	sealing_msg_queue = xQueueCreate(1, sizeof(int));
	if (sealing_msg_queue == 0) {
		reportError("sealing_msg_queue cannot create");
	}
}

*/
int main()
{
	int a = 3;
	prvInit();
	reportError("GG.");
	a = 5;
	a = 8;
}
