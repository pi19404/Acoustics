/*
 * common.h
 *
 *  Created on: May 8, 2014
 *      Author: root
 */

#ifndef COMMON_H_
#define COMMON_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "netmain.h"
#include <_stack.h>
#include "cgiparse.h"
#include "cgiparsem.h"
#include "console.h"
#include "servers.h"
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/bios/include/swi.h>
#include "platform.h"
#include "resource_mgr.h"
#include <stack/inc/nimuif.h>

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

#ifdef C665_PLATFORMS
#include "emac_drv.h"
#endif

/* Our version */
#define BLM_VERSION	"2.00.00.04"

/* Max size of a file that can be posted...
 *   including form fields and boundary markers!
 */
#define MAX_POST_FILESZ	 20000000

/*
 *  COFF MAGIC NUMBERS for checking COFF images
 */
#define COFF_MAGIC_0    0xc0      /* ORIGINAL VERSION OF COFF */
#define COFF_MAGIC_1    0xc1
#define COFF_MAGIC_2    0xc2

/*
 * The following defines are used for the Flash (for the older C64 Platforms)
 */
#define APP_MAGIC_NUM				(0xA1ACED11)		/* Magic number for a bootable image 		*/
#define START_BLOCK_NUM 			(1)					/* Block where we write the botoable image	*/

#ifdef C66_PLATFORMS
#include "csl_cpsw_3gfAux.h"
#endif

#define STATICIP   0
#define DHCPSERVER 1
#define DHCPCLIENT 2

#include "platform.h"
#include "ti/platform/evmc6670l/platform_lib/include/platform_internal.h"
#endif /* COMMON_H_ */
