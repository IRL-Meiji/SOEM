#ifndef CUSTOM_PDO_NAME_H
#define CUSTOM_PDO_NAME_H

//-------------------------------------------------------------------//
//                                                                   //
//     This file has been created by the Easy Configurator tool      //
//                                                                   //
//     Easy Configurator project IRL-LW_HogeSlave.prj
//                                                                   //
//-------------------------------------------------------------------//


#define CUST_BYTE_NUM_OUT	19
#define CUST_BYTE_NUM_IN	19
#define TOT_BYTE_NUM_ROUND_OUT	20
#define TOT_BYTE_NUM_ROUND_IN	20


typedef union												//---- output buffer ----
{
	uint8_t  Byte [TOT_BYTE_NUM_ROUND_OUT];
	struct
	{
		double      double_Output;
		uint32_t    uint32_Output;
		float       float_Output;
		uint16_t    uint16_Output;
		uint8_t     uint8_Output;
	}Cust;
} PROCBUFFER_OUT;


typedef union												//---- input buffer ----
{
	uint8_t  Byte [TOT_BYTE_NUM_ROUND_IN];
	struct
	{
		double      double_Input;
		uint32_t    uint32_Input;
		float       float_Input;
		uint16_t    uint16_Input;
		uint8_t     uint8_Input;
	}Cust;
} PROCBUFFER_IN;

#endif