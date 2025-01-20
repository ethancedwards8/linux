// SPDX-License-Identifier: GPL-2.0
/*
 * Apple File System (APFS) Driver
 *
 * Copyright (C) 2025 Ethan Carter Edwards <ethan@ethancedwards.com>
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

#include "apfs_fs.h"

static void apfs_put_super(struct super_block *sb)
{
	printk("apfs super block is destroyed");
}

static struct super_operations const apfs_super_ops = {
	.put_super		= apfs_put_super,
};

static int apfs_fill_sb(struct super_block *sb, void *data, int silent)
{
	/*struct inode *root = NULL;*/

	sb->s_magic = APFS_MAGIC;
	sb->s_op = &apfs_super_ops;

	/*root = new_inode(sb);*/
	/*if (!root) {*/
	/*	pr_err("inode alloc has failed\n");*/
	/*	return -ENOMEM;*/
	/*}*/
	/**/
	/*root->i_ino = 0;*/
	/*root->i_sb = sb;*/
	/*root->i_atime = root->i_mtime = root->i_ctime = CURRENT_TIME;*/
	/*inode_init_owner(root, NULL, S_IFDIR);*/
	/**/
	/*sb->s_root = d_make_root(root);*/
	/*if (!sb->s_root)*/
	/*{*/
	/*	pr_err("root creation failed\n");*/
	/*	return -ENOMEM;*/
	/*}*/


	return 0;

}

static struct dentry *apfs_mount(struct file_system_type *type,
		int flags, const char *dev_name, void *data)
{
	struct dentry *const entry = mount_bdev(type, flags,
			dev_name, data, apfs_fill_sb);

	if (IS_ERR(entry))
		pr_err("apfs failed to mount\n");
	else
		printk("apfs mounted\n");

	return entry;
}

static struct file_system_type apfs_type = {
	.owner			= THIS_MODULE,
	.name			= "apfs",
	.mount			= apfs_mount,
	.kill_sb		= kill_block_super,
};

static int __init apfs_init(void)
{
	int ret;

	printk("apfs kernel module loaded");

	ret = register_filesystem(&apfs_type);

	if (ret == 0)
		printk("apfs filesystem loaded");
	else
		pr_err("failed to load apfs filesystem");

	return 0;
}

static void __exit apfs_exit(void)
{
	int ret;

	printk("apfs kernel module unloaded");

	ret = unregister_filesystem(&apfs_type);

	if (ret == 0)
		printk("apfs filesystem unloaded");
	else
		pr_err("failed to unload apfs filesystem");
}

MODULE_AUTHOR("Ethan Carter Edwards");
MODULE_DESCRIPTION("Apple File System Driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("apfs");
MODULE_ALIAS_FS("apfs");
module_init(apfs_init);
module_exit(apfs_exit);
