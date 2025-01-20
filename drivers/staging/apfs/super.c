// SPDX-License-Identifier: GPL-2.0
/*
 * Apple File System (APFS) Driver
 *
 * Copyright (C) 2025 Ethan Carter Edwards <ethan@ethancedwards.com>
 */

#include <linux/module.h>
#include <linux/init.h>

static int __init apfs_init(void)
{
	printk("apfs module loaded");

	return 0;
}

static void __exit apfs_exit(void)
{
	printk("apfs moduled unloaded");
}

MODULE_AUTHOR("Ethan Carter Edwards");
MODULE_DESCRIPTION("Apple File System Driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("apfs");
MODULE_ALIAS_FS("apfs");
module_init(apfs_init);
module_exit(apfs_exit);
