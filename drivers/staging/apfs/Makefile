# SPDX-License-Identifier: GPL-2.0

APFS_VERSION = "1.0pre1"

ccflags-y += -Wall -DAPFS_VERSION=\"$(APFS_VERSION)\"

obj-$(CONFIG_APFS_FS) += super.o

ccflags-y += -I$(src)/include

# apfs-objs := super.o
