# SPDX-License-Identifier: GPL-2.0

APFS_VERSION = "1.0pre1"

ccflags-y += -Wall -DAPFS_VERSION=\"$(APFS_VERSION)\" -I$(src)/include -DDEBUG

obj-$(CONFIG_APFS_FS) += apfs.o

apfs-objs := super.o
