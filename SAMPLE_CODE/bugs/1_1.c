#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#define NAME "test-fclose.t"

		int
main (void)
{
		const char buf[] = "hello world";
		int fd;
		int fd2;
		FILE *f;

		/* Prepare a seekable file.  */
		fd = open (NAME, O_RDWR | O_CREAT | O_TRUNC, 0600);
		assert (0 <= fd);
		assert (write (fd, buf, sizeof buf) == sizeof buf);
		assert (lseek (fd, 1, SEEK_SET) == 1);

		/* Create an output stream visiting the file; when it is closed, all
		   other file descriptors visiting the file must see the new file
		   position.  */
		fd2 = dup (fd);
		assert (0 <= fd2);
		f = fdopen (fd2, "w");
		assert (f);
		assert(lseek(fd, 4, SEEK_SET) == 4);
		assert (fclose (f) == 0);
		errno = 0;
		assert (lseek (fd2, 0, SEEK_CUR) == -1);
		assert (errno == EBADF);
		assert (lseek (fd, 0, SEEK_CUR) == 4);

		/* Likewise for an input stream.  */
		fd2 = dup (fd);
		assert (0 <= fd2);
		f = fdopen (fd2, "r");
		assert (f);
		assert(lseek(fd, 4, SEEK_SET) == 4);
		assert (fclose (f) == 0);
		errno = 0;
		assert (lseek (fd2, 0, SEEK_CUR) == -1);
		assert (errno == EBADF);
		assert (lseek (fd, 0, SEEK_CUR) == 4);

		/* Clean up.  */
		assert (remove (NAME) == 0);

		return 0;
}
