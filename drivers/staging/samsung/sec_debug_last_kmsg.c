/*
 * sec_debug_last_kmsg.c
 *
 * Copyright (c) 2016 Samsung Electronics Co., Ltd
 *              http://www.samsung.com
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/proc_fs.h>
#include <linux/sec_debug.h>

static char *last_kmsg_buffer;
static size_t last_kmsg_size;

void sec_debug_save_last_kmsg(unsigned char* head_ptr, unsigned char* curr_ptr,
	size_t log_size)
{
	if (head_ptr == NULL || curr_ptr == NULL || head_ptr == curr_ptr) {
		pr_err("%s: no data \n", __func__);
		return;
	}

	/* provide previous log as last_kmsg */
	last_kmsg_size = (size_t)SZ_2M;
	last_kmsg_buffer = (char *)kzalloc(last_kmsg_size, GFP_NOWAIT);

	if (last_kmsg_size && last_kmsg_buffer) {
		unsigned i;
		// Relocate the last kmsg log buffer
		for (i = 0; i < last_kmsg_size; i++)
			last_kmsg_buffer[i] = head_ptr[((size_t)(curr_ptr - head_ptr) - last_kmsg_size + i) & (log_size -1)];
		pr_info("%s: successed\n", __func__);
	} else
		pr_err("%s: failed\n", __func__);
}

static ssize_t sec_last_kmsg_read(struct file *file, char __user *buf,
				  size_t len, loff_t *offset)
{
	loff_t pos = *offset;
	ssize_t count;

	if (pos >= last_kmsg_size)
		return 0;

	count = min(len, (size_t) (last_kmsg_size - pos));
	if (copy_to_user(buf, last_kmsg_buffer + pos, count))
		return -EFAULT;

	*offset += count;
	return count;
}

static const struct file_operations last_kmsg_file_ops = {
	.owner = THIS_MODULE,
	.read = sec_last_kmsg_read,
};

static int __init sec_last_kmsg_late_init(void)
{
	struct proc_dir_entry *entry;

	if (last_kmsg_buffer == NULL)
		return 0;

	entry = proc_create("last_kmsg", S_IFREG | S_IRUGO,
			NULL, &last_kmsg_file_ops);
	if (!entry) {
		pr_err("%s: failed to create proc entry\n", __func__);
		return 0;
	}

	proc_set_size(entry, last_kmsg_size);
	return 0;
}

late_initcall(sec_last_kmsg_late_init);
