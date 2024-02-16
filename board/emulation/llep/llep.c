// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2018, Hanyuan Zhao <zhaohy22@mails.tsinghua.edu.cn>
 */

#include <common.h>
#include <dm.h>
#include <dm/ofnode.h>
#include <env.h>
#include <fdtdec.h>
#include <image.h>
#include <log.h>
#include <spl.h>
#include <init.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
    return 0;
}

int board_late_init(void)
{

    return 0;
}

#ifdef CONFIG_SPL
u32 spl_boot_device(void)
{
	/* RISC-V QEMU only supports RAM as SPL boot device */
	return BOOT_DEVICE_RAM;
}
#endif

#ifdef CONFIG_SPL_LOAD_FIT
int board_fit_config_name_match(const char *name)
{
	/* boot using first FIT config */
	return 0;
}
#endif

void *board_fdt_blob_setup(int *err)
{
    *err = 0;
    /* Stored the DTB address there during our init */
    return (void *)(ulong)gd->arch.firmware_fdt_addr;
}
