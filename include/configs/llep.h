/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2024, Hanyuan Zhao <zhaohy22@mails.tsinghua.edu.cn>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CFG_SYS_SDRAM_BASE		0x02000000
#define CFG_SYS_SDRAM_SIZE		0x01000000
#define RISCV_SMODE_TIMER_FREQ		10000

/* Environment options */

#define CFG_STD_DEVICES_SETTINGS	"stdin=serial,usbkbd\0" \
					"stdout=serial,vidconsole\0" \
					"stderr=serial,vidconsole\0"

#define BOOT_TARGET_DEVICES(func)

#include <config_distro_bootcmd.h>

#define CFG_EXTRA_ENV_SETTINGS \
	CFG_STD_DEVICES_SETTINGS \
	"fdt_high=0xffffffffffffffff\0" \
	"initrd_high=0xffffffffffffffff\0" \
	"kernel_addr_r=0x05a00000\0" \
	"kernel_comp_addr_r=0x09000000\0" \
	"kernel_comp_size=0x4000000\0" \
	BOOTENV

#endif /* __CONFIG_H */
