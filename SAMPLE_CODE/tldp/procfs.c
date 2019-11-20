/*  procfs.c -  create a "file" in /proc 
 *
 *  Copyright (C) 2001 by Peter Jay Salzman
 *
 *  08/02/2006 - Updated by Rodrigo Rubira Branco <rodrigo@kernelhacking.com>
 */

/* Kernel Programming */
#define MODULE
#define LINUX
#define __KERNEL__

#include <linux/kernel.h>   /* We're doing kernel work */
#include <linux/module.h>   /* Specifically, a module */

/* Deal with CONFIG_MODVERSIONS */
#if CONFIG_MODVERSIONS==1
#define MODVERSIONS
#include <linux/modversions.h>
#endif        


/* Necessary because we use the proc fs */
#include <linux/proc_fs.h>



/* In 2.2.3 /usr/include/linux/version.h includes a 
 * macro for this, but 2.0.35 doesn't - so I add it 
 * here if necessary. */
#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a,b,c) ((a)*65536+(b)*256+(c))
#endif



/* Put data into the proc fs file.

   Arguments
   =========
   1. The buffer where the data is to be inserted, if 
   you decide to use it.
   2. A pointer to a pointer to characters. This is 
   useful if you don't want to use the buffer 
   allocated by the kernel.
   3. The current position in the file. 
   4. The size of the buffer in the first argument.  
   5. Zero (for future use?).


   Usage and Return Value
   ======================
   If you use your own buffer, like I do, put its 
   location in the second argument and return the 
   number of bytes used in the buffer.

   A return value of zero means you have no further 
   information at this time (end of file). A negative 
   return value is an error condition.


   For More Information
   ==================== 
   The way I discovered what to do with this function 
   wasn't by reading documentation, but by reading the 
   code which used it. I just looked to see what uses 
   the get_info field of proc_dir_entry struct (I used a 
   combination of find and grep, if you're interested), 
   and I saw that  it is used in <kernel source 
   directory>/fs/proc/array.c.

   If something is unknown about the kernel, this is 
   usually the way to go. In Linux we have the great 
   advantage of having the kernel source code for 
   free - use it.
 */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,4,0)
int procfile_read(char *buffer,
		char **buffer_location, off_t offset,
		int buffer_length, int *eof, void *data)
#else
int procfile_read(char *buffer, 
		char **buffer_location, 
		off_t offset, 
		int buffer_length, 
		int zero)
#endif
{
	int len;  /* The number of bytes actually used */

	/* This is static so it will still be in memory 
	 * when we leave this function */
	static char my_buffer[80];  

	static int count = 1;

	/* We give all of our information in one go, so if the 
	 * user asks us if we have more information the 
	 * answer should always be no. 
	 *
	 * This is important because the standard read 
	 * function from the library would continue to issue 
	 * the read system call until the kernel replies
	 * that it has no more information, or until its 
	 * buffer is filled.
	 */
	if (offset > 0)
		return 0;

	/* Fill the buffer and get its length */
	len = sprintf(my_buffer, 
			"For the %d%s time, go away!\n", count,
			(count % 100 > 10 && count % 100 < 14) ? "th" : 
			(count % 10 == 1) ? "st" :
			(count % 10 == 2) ? "nd" :
			(count % 10 == 3) ? "rd" : "th" );
	count++;

	/* Tell the function which called us where the 
	 * buffer is */
	*buffer_location = my_buffer;

	/* Return the length */
	return len;
}

#if LINUX_VERSION_CODE > KERNEL_VERSION(2,4,0)
struct proc_dir_entry *Our_Proc_File;
#else
struct proc_dir_entry Our_Proc_File = 
{
	0, /* Inode number - ignore, it will be filled by 
	    * proc_register[_dynamic] */
	4, /* Length of the file name */
	"test", /* The file name */
	S_IFREG | S_IRUGO, /* File mode - this is a regular 
			    * file which can be read by its 
			    * owner, its group, and everybody
			    * else */
	1,	/* Number of links (directories where the 
		 * file is referenced) */
	0, 0,  /* The uid and gid for the file - we give it 
		* to root */
	80, /* The size of the file reported by ls. */
	NULL, /* functions which can be done on the inode 
	       * (linking, removing, etc.) - we don't 
	       * support any. */
	(struct file_operations *) procfile_read, /* The read function for this file, 
						   * the function called when somebody 
						   * tries to read something from it. */
	NULL /* We could have here a function to fill the 
	      * file's inode, to enable us to play with 
	      * permissions, ownership, etc. */
}; 
#endif





/* Initialize the module - register the proc file */
int init_module()
{
	/* Success if proc_register[_dynamic] is a success, 
	 * failure otherwise. */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,2,0)
	/* In version 2.2, proc_register assign a dynamic 
	 * inode number automatically if it is zero in the 
	 * structure , so there's no more need for 
	 * proc_register_dynamic
	 */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,4,0)
	Our_Proc_File=create_proc_read_entry("test", 0444, NULL, procfile_read, NULL);

	if ( Our_Proc_File == NULL )
		return -ENOMEM;
	else
		return 0;
#else
	return proc_register(&proc_root, &Our_Proc_File);
#endif
#else
	return proc_register_dynamic(&proc_root, &Our_Proc_File);
#endif

	/* proc_root is the root directory for the proc 
	 * fs (/proc). This is where we want our file to be 
	 * located. 
	 */
}


/* Cleanup - unregister our file from /proc */
void cleanup_module()
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,4,0)
	remove_proc_entry("test", NULL);
#else
	proc_unregister(&proc_root, Our_Proc_File.low_ino);
#endif
}  

MODULE_LICENSE("GPL");
