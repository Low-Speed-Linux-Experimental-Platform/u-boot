/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2024, Hanyuan Zhao <zhaohy22@mails.tsinghua.edu.cn>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CFG_SYS_SDRAM_BASE		0x80000000
#define CFG_SYS_SDRAM_SIZE		0x01fa0000
#define RISCV_SMODE_TIMER_FREQ		10000

/* Environment options */

#define BOOT_TARGET_DEVICES(func)

#include <config_distro_bootcmd.h>

#define CFG_EXTRA_ENV_SETTINGS \
	"fdt_high=0x81ffd800\0" \
	"kernel_addr_r=0x80000000\0" \
	"kernel_comp_addr_r=0x813a0000\0" \
	"simple_env=setenv bootargs earlycon=sbi console=ttyS0,115200 root=/dev/ram0\0" \
	"simpleboot=run simple_env && unzip $kernel_comp_addr_r $kernel_addr_r && bootm $kernel_addr_r - $fdt_high\0" \
	"bootcmd=run simpleboot\0"

#endif /* __CONFIG_H */
