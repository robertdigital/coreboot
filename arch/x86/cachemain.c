/*
 * This file is part of the LinuxBIOS project.
 *
 * Copyright (C) 2007 Stefan Reinauer <stepan@coresystems.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include <arch/types.h>
#include <arch/io.h>
#include <console/loglevel.h>
#include <lar.h>
#include "config.h"

/* these prototypes should go into headers */
void uart_init(void);
int printk(int msg_level, const char *fmt, ...);
void console_init(void);
void die(const char *msg);
int find_file(struct mem_file *archive, char *filename, struct mem_file *result);

void post_code(u8 value)
{
	outb(value, 0x80);
}

static void stop_ap(void)
{
	// nothing yet
	post_code(0xf0);
}

static void enable_superio(void)
{
	// nothing yet
	post_code(0xf1);
}

static void enable_rom(void)
{
	// nothing here yet
	post_code(0xf2);
}

void stage1_main(u32 bist)
{
	int ret;
	struct mem_file archive, result;

	post_code(0x02);

	// before we do anything, we want to stop if we dont run 
	// on the bootstrap processor.
	if (bist==0) {
		// stop secondaries
		stop_ap();
	}

	// We have cache as ram running and can start executing code in C.
	//
	
	enable_superio();

	//
	uart_init();	// initialize serial port
	console_init(); // print banner

	if (bist!=0) {
		printk(BIOS_INFO, "BIST FAILED: %08x", bist);
		die("");
	}

	// enable rom
	enable_rom();
	
	// location and size of image.
	
	// FIXME this should be defined in the VPD area
	// but NOT IN THE CODE.
	
	archive.len=LINUXBIOS_ROMSIZE_KB*1024;
	archive.start=(void *)(0UL-archive.len); 
	/* This won't work; the for loop in lib/lar.c will always 
	 * fail as adding len to start will be 0. 
	 * shave off 0x1000 since we know that is the boot block 
	 */
	archive.len-=0x1000;
printk(BIOS_INFO, "Start search at 0x%x, size %d\n", archive.start, archive.len);

	// FIXME check integrity


	// fixme: choose an initram image (normal/fallback)
	// find first initram
	ret = run_file(&archive, "normal/initram", (void *)(512*1024)); //CONFIG_CARBASE;

	if (ret)
		die("Failed ram init code\n");

	printk(BIOS_INFO, "Done ram init code\n");

	ret = run_file(&archive, "normal/stage2", (void *)0x1000);
	if (ret)
		die("Failed stage2 code\n");

	printk(BIOS_INFO, "Done stage2 code\n");

	die ("FATAL: This is as far as it goes\n");
}


