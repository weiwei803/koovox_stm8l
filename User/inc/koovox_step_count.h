/****************************************************************************
Copyright (C) JoySoft . 2015-2025
Part of KOOVOX 1.0.1

FILE NAME
    koovox_step_count.h

*/

#ifndef	__KOOVOX_STEP_COUNT_H
#define __KOOVOX_STEP_COUNT_H

#include "stm8l15x.h"

#define STEP_COUNT_MIN_THRESHOLD	82
#define STEP_COUNT_MAX_THRESHOLD	143
#define TIME_THRESHOLD				6

typedef struct{
	uint8_t status ;/* 0:表示上升沿； 1:表示下降沿 */
	uint8_t max_flag ;
	uint8_t min_flag;
	uint16_t min_value;
	uint16_t max_value;
	uint16_t pre_value;
	uint32_t index_max;	/* 前一个极大值下标 */
	uint32_t index_min;	/* 前一个极小值下标 */
}Acc_step_var;


uint8_t Koovox_enable_step_count(void);
uint8_t Koovox_disable_step_count(void);
void Koovox_step_count(int16_t axis_x, int16_t axis_y, int16_t axis_z, uint32_t index_acc);
void Koovox_step_count_event(void);
void Koovox_judge_walk_status(void);

extern bool step_count_enable;

#endif

