/*************************************************************************
** File:
**   $Id: lc_def_wdt.c 1.3 2015/03/04 16:09:49EST sstrege Exp  $
**
**  Copyright � 2007-2014 United States Government as represented by the 
**  Administrator of the National Aeronautics and Space Administration. 
**  All Other Rights Reserved.  
**
**  This software was created at NASA's Goddard Space Flight Center.
**  This software is governed by the NASA Open Source Agreement and may be 
**  used, distributed and modified only pursuant to the terms of that 
**  agreement.
**
** Purpose: 
**   Limit Checker (LC) default watchpoint definition table (WDT)
**
** Notes:
**   This file provides a default WDT table that simply sets all
**   watchpoint entries to "not used". It has been formatted to make
**   it easy for mission developers to edit as needed (see the 
**   examples section below).
**
**   Compiler Note
**   -------------
**   This file may generate the following warning when compiling 
**   with gcc if you are using the flags "-ansi -pedantic":
** 
**   "warning: ISO C90 forbids specifying subobject to initialize"
**
**   Removing "-pedantic" should eliminate the warning. An alternate
**   solution is to replace "-ansi" with "-std=c99" and leave the
**   "-pedantic" flag in place
**
**   $Log: lc_def_wdt.c  $
**   Revision 1.3 2015/03/04 16:09:49EST sstrege 
**   Added copyright information
**   Revision 1.2 2012/08/06 17:59:42EDT lwalling 
**   Add ResultAgeWhenStale to WP definition table
**   Revision 1.1 2012/07/31 13:53:42PDT nschweis 
**   Initial revision
**   Member added to project c:/MKSDATA/MKS-REPOSITORY/CFS-REPOSITORY/lcx/fsw/tables/project.pj
**   Revision 1.4 2012/07/20 13:50:19EDT lwalling 
**   Remove compiler warning for unused data structure
**   Revision 1.3 2010/04/20 12:03:23PDT lwalling 
**   Fix ART vs ADT and WRT vs WDT typo in LC table files
**   Revision 1.2 2009/12/22 13:18:56EST lwalling 
**   Update list of included header files, modify contents of table file header structure
**   Revision 1.1 2009/12/18 14:10:50EST lwalling 
**   Initial revision
**   Member added to project c:/MKSDATA/MKS-REPOSITORY/CFS-REPOSITORY/lc/fsw/tables/project.pj
**   Revision 1.4 2009/01/15 15:36:18EST dahardis 
**   Unit test fixes
**   Revision 1.3 2008/12/10 16:00:29EST dahardis 
**   Changed the size of the template definition table from
**   256 to 176 entries
**   Revision 1.2 2008/12/03 13:59:47EST dahardis 
**   Corrections from peer code review
**   Revision 1.1 2008/10/29 14:19:19EDT dahardison 
**   Initial revision
**   Member added to project c:/MKSDATA/MKS-REPOSITORY/CFS-REPOSITORY/lc/fsw/src/project.pj
** 
*************************************************************************/

/*************************************************************************
** Includes
*************************************************************************/
#include "cfe_tbl_filedef.h"
#include "lc_platform_cfg.h"
#include "lc_msgdefs.h"
#include "lc_tbl.h"
#include "lc_app.h"

#include "../whe/fsw/platform_inc/whe_msgids.h"

/*************************************************************************
** Examples
** (note that comment delimiters have been changed to '**')
**
** Incremental tests on the same data point:
** (see lc_def_adt.c for companion actionpoint definitions)
** 
**    ** #112 (Diviner - low s/c bus voltage, level 1) **
**    {
**        .DataType                   = LC_DATA_UWORD_BE,
**        .OperatorID                 = LC_OPER_LT,
**        .MessageID                  = PSE_FAST_HK_TLM_MID,
**        .WatchpointOffset           = 184,
**        .BitMask                    = LC_NO_BITMASK,
**        .CustomFuncArgument         = 0,
**        .ResultAgeWhenStale         = 0,
**        .ComparisonValue.Unsigned16in32.Unsigned16 = 3417,
**    },
**
**    ** #113 (Diviner - low s/c bus voltage, level 2) **
**    {
**        .DataType                   = LC_DATA_UWORD_BE,
**        .OperatorID                 = LC_OPER_LT,
**        .MessageID                  = PSE_FAST_HK_TLM_MID,
**        .WatchpointOffset           = 184,
**        .BitMask                    = LC_NO_BITMASK,
**        .CustomFuncArgument         = 0,
**        .ResultAgeWhenStale         = 0,
**        .ComparisonValue.Unsigned16in32.Unsigned16 = 3319,
**    },
**
** Use of bitmasking and a custom function: 
**  
**    ** #154 (IRU - 24 bit value with custom transform) **
**    {
**        .DataType                   = LC_DATA_UDWORD_BE,
**        .OperatorID                 = LC_OPER_CUSTOM,
**        .MessageID                  = IRU_FAST_HK_TLM_MID,
**        .WatchpointOffset           = 76,
**        .BitMask                    = 0x00FFFFFF,
**        .CustomFuncArgument         = LC_CUSTOM_XYZ_TRANSFORM,
**        .ResultAgeWhenStale         = 0,
**        .ComparisonValue.Unsigned32 = 1050000,
**    },
** 
*************************************************************************/

/*************************************************************************
** Exported Data
*************************************************************************/
/*
** Table file header
*/
static CFE_TBL_FileDef_t CFE_TBL_FileDef __attribute__((__used__)) =
{
    "LC_DefaultWDT", LC_APP_NAME "." LC_WDT_TABLENAME,
    "LC watchpoint definition table", "lc_def_wdt.tbl",
    (sizeof(LC_WDTEntry_t) * LC_MAX_WATCHPOINTS)
};

/*
** Default watchpoint definition table (WDT) data
*/
LC_WDTEntry_t LC_DefaultWDT[LC_MAX_WATCHPOINTS] =
{
    /* #0 WHE Capacitor A Charge >= 95 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_GE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 14,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 95,
    },

    /* #1 WHE Capacitor B Charge >= 95 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_GE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 16,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 95,
    },

    /* #2 WHE Capacitor A Charge <= 5 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_LE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 14,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 5,
    },

    /* #3 WHE Capacitor B Charge <= 5 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_LE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 16,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 5,
    },

    /* #4 WHE Capacitor A State == CHARGING */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 15,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #5 WHE Capacitor B State == CHARGING */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 17,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #6 WHE Capacitor A State == DISCHARGING */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 15,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 1,
    },

    /* #7 WHE Capacitor B State == DISCHARGING */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 17,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 1,
    },

    /* #8 WHE Capacitor A State == LEAKING */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 15,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 2,
    },

    /* #9 WHE Capacitor B State == LEAKING */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 17,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 2,
    },

    /* #10 WHE Capacitor A State == BROKEN */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 15,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 3,
    },

    /* #11 WHE Capacitor B State == BROKEN */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 17,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 3,
    },

    /* #12 WHE Temperature >= 0 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_GE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 19,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #13 WHE Temperature >= 10 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_GE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 19,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 10,
    },

    /* #14 WHE Temperature <= 20 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_LE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 19,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 20,
    },

    /* #15 WHE Temperature <= 35 */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_LE,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 19,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 35,
    },

    /* #16 WHE SBC State == OFF */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 18,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #17 WHE SBC State == POWERED */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 18,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 1,
    },

    /* #18 WHE SBC State == OBSERVING */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 18,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 2,
    },

    /* #19 WHE SBC State == ERROR */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 18,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 3,
    },

    /* #20 WHE Louver State == CLOSED */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 20,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #21 WHE Louver State == OPEN */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 20,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 1,
    },

    /* #22 WHE Heater State == OFF  */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 21,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #23 WHE Heater State == ON */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 21,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 1,
    },

    /* #24 WHE Active Capacitor == A */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 22,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #25 WHE Active Capacitor == B */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 22,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 1,
    },

    /* #26 WHE Damage State == NONE */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 23,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #27 WHE Damage State == MINOR */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 23,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 1,
    },

    /* #28 WHE Damage State == MAJOR */
    {
        .DataType                   = LC_DATA_BYTE,
        .OperatorID                 = LC_OPER_EQ,
        .MessageID                  = WHE_HK_TLM_MID,
        .WatchpointOffset           = 23,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 2,
    },

    /* #29 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #30 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #31 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #32 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #33 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #34 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #35 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #36 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #37 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #38 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #39 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #40 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #41 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #42 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #43 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #44 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #45 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #46 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #47 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #48 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #49 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #50 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #51 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #52 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #53 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #54 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #55 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #56 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #57 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #58 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #59 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #60 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #61 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #62 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #63 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #64 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #65 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #66 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #67 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #68 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #69 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #70 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #71 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #72 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #73 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #74 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #75 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #76 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #77 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #78 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #79 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #80 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #81 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #82 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #83 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #84 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #85 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #86 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #87 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #88 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #89 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #90 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #91 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #92 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #93 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #94 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #95 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #96 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #97 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #98 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #99 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #100 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #101 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #102 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #103 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #104 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #105 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #106 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #107 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #108 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #109 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #110 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #111 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #112 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #113 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #114 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #115 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #116 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #117 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #118 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #119 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #120 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #121 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #122 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #123 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #124 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #125 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #126 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #127 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #128 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #129 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #130 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #131 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #132 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #133 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #134 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #135 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #136 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #137 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #138 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #139 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #140 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #141 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #142 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #143 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #144 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #145 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #146 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #147 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #148 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #149 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #150 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #151 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #152 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #153 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #154 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #155 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #156 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #157 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #158 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #159 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #160 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #161 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #162 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #163 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #164 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #165 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #166 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #167 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #168 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #169 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #170 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #171 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #172 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #173 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #174 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    },

    /* #175 (unused) */
    {
        .DataType                   = LC_WATCH_NOT_USED,
        .OperatorID                 = LC_NO_OPER,
        .MessageID                  = 0,
        .WatchpointOffset           = 0,
        .BitMask                    = LC_NO_BITMASK,
        .CustomFuncArgument         = 0,
        .ResultAgeWhenStale         = 0,
        .ComparisonValue.Unsigned32 = 0,
    }
}; /* end LC_DefaultWDT */

/************************/
/*  End of File Comment */
/************************/
