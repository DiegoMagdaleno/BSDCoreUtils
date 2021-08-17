#include <errno.h>
#include <winerror.h>
#include <windows.h>

/* Translate from win32 -> POSIX */
int
err_translate ()
{
  int error = ENOSYS;
  switch (GetLastError ())
    {
    case ERROR_ACCESS_DENIED:
      error = EACCES;
      break;
    case ERROR_ACCOUNT_DISABLED:
      error = EACCES;
      break;
    case ERROR_ACCOUNT_RESTRICTION:
      error = EACCES;
      break;
    case ERROR_ALREADY_ASSIGNED:
      error = EBUSY;
      break;
    case ERROR_ALREADY_EXISTS:
      error = EEXIST;
      break;
    case ERROR_ARITHMETIC_OVERFLOW:
      error = ERANGE;
      break;
    case ERROR_BAD_COMMAND:
      error = EIO;
      break;
    case ERROR_BAD_DEVICE:
      error = ENODEV;
      break;
    case ERROR_BAD_DRIVER_LEVEL:
      error = ENXIO;
      break;
    case ERROR_BAD_EXE_FORMAT:
      error = ENOEXEC;
      break;
    case ERROR_BAD_FORMAT:
      error = ENOEXEC;
      break;
    case ERROR_BAD_LENGTH:
      error = EINVAL;
      break;
    case ERROR_BAD_PATHNAME:
      error = ENOENT;
      break;
    case ERROR_BAD_PIPE:
      error = EPIPE;
      break;
    case ERROR_BAD_UNIT:
      error = ENODEV;
      break;
    case ERROR_BAD_USERNAME:
      error = EINVAL;
      break;
    case ERROR_BROKEN_PIPE:
      error = EPIPE;
      break;
    case ERROR_BUFFER_OVERFLOW:
      error = ENAMETOOLONG;
      break;
    case ERROR_BUSY:
      error = EBUSY;
      break;
    case ERROR_BUSY_DRIVE:
      error = EBUSY;
      break;
    case ERROR_CALL_NOT_IMPLEMENTED:
      error = ENOSYS;
      break;
    case ERROR_CANNOT_MAKE:
      error = EACCES;
      break;
    case ERROR_CANTOPEN:
      error = EIO;
      break;
    case ERROR_CANTREAD:
      error = EIO;
      break;
    case ERROR_CANTWRITE:
      error = EIO;
      break;
    case ERROR_CRC:
      error = EIO;
      break;
    case ERROR_CURRENT_DIRECTORY:
      error = EACCES;
      break;
    case ERROR_DEVICE_IN_USE:
      error = EBUSY;
      break;
    case ERROR_DEV_NOT_EXIST:
      error = ENODEV;
      break;
    case ERROR_DIRECTORY:
      error = EINVAL;
      break;
    case ERROR_DIR_NOT_EMPTY:
      error = ENOTEMPTY;
      break;
    case ERROR_DISK_CHANGE:
      error = EIO;
      break;
    case ERROR_DISK_FULL:
      error = ENOSPC;
      break;
    case ERROR_DRIVE_LOCKED:
      error = EBUSY;
      break;
    case ERROR_ENVVAR_NOT_FOUND:
      error = EINVAL;
      break;
    case ERROR_EXE_MARKED_INVALID:
      error = ENOEXEC;
      break;
    case ERROR_FILENAME_EXCED_RANGE:
      error = ENAMETOOLONG;
      break;
    case ERROR_FILE_EXISTS:
      error = EEXIST;
      break;
    case ERROR_FILE_INVALID:
      error = ENODEV;
      break;
    case ERROR_FILE_NOT_FOUND:
      error = ENOENT;
      break;
    case ERROR_GEN_FAILURE:
      error = EIO;
      break;
    case ERROR_HANDLE_DISK_FULL:
      error = ENOSPC;
      break;
    case ERROR_INSUFFICIENT_BUFFER:
      error = ENOMEM;
      break;
    case ERROR_INVALID_ACCESS:
      error = EACCES;
      break;
    case ERROR_INVALID_ADDRESS:
      error = EFAULT;
      break;
    case ERROR_INVALID_BLOCK:
      error = EFAULT;
      break;
    case ERROR_INVALID_DATA:
      error = EINVAL;
      break;
    case ERROR_INVALID_DRIVE:
      error = ENODEV;
      break;
    case ERROR_INVALID_EXE_SIGNATURE:
      error = ENOEXEC;
      break;
    case ERROR_INVALID_FLAGS:
      error = EINVAL;
      break;
    case ERROR_INVALID_FUNCTION:
      error = ENOSYS;
      break;
    case ERROR_INVALID_HANDLE:
      error = EBADF;
      break;
    case ERROR_INVALID_LOGON_HOURS:
      error = EACCES;
      break;
    case ERROR_INVALID_NAME:
      error = EINVAL;
      break;
    case ERROR_INVALID_OWNER:
      error = EINVAL;
      break;
    case ERROR_INVALID_PARAMETER:
      error = EINVAL;
      break;
    case ERROR_INVALID_PASSWORD:
      error = EPERM;
      break;
    case ERROR_INVALID_PRIMARY_GROUP:
      error = EINVAL;
      break;
    case ERROR_INVALID_SIGNAL_NUMBER:
      error = EINVAL;
      break;
    case ERROR_INVALID_TARGET_HANDLE:
      error = EIO;
      break;
    case ERROR_INVALID_WORKSTATION:
      error = EACCES;
      break;
    case ERROR_IO_DEVICE:
      error = EIO;
      break;
    case ERROR_IO_INCOMPLETE:
      error = EINTR;
      break;
    case ERROR_LOCKED:
      error = EBUSY;
      break;
    case ERROR_LOCK_VIOLATION:
      error = EACCES;
      break;
    case ERROR_LOGON_FAILURE:
      error = EACCES;
      break;
    case ERROR_MAPPED_ALIGNMENT:
      error = EINVAL;
      break;
    case ERROR_META_EXPANSION_TOO_LONG:
      error = E2BIG;
      break;
    case ERROR_MORE_DATA:
      error = EPIPE;
      break;
    case ERROR_NEGATIVE_SEEK:
      error = ESPIPE;
      break;
    case ERROR_NOACCESS:
      error = EFAULT;
      break;
    case ERROR_NONE_MAPPED:
      error = EINVAL;
      break;
    case ERROR_NOT_ENOUGH_MEMORY:
      error = ENOMEM;
      break;
    case ERROR_NOT_READY:
      error = EAGAIN;
      break;
    case ERROR_NOT_SAME_DEVICE:
      error = EXDEV;
      break;
    case ERROR_NO_DATA:
      error = EPIPE;
      break;
    case ERROR_NO_MORE_SEARCH_HANDLES:
      error = EIO;
      break;
    case ERROR_NO_PROC_SLOTS:
      error = EAGAIN;
      break;
    case ERROR_NO_SUCH_PRIVILEGE:
      error = EACCES;
      break;
    case ERROR_OPEN_FAILED:
      error = EIO;
      break;
    case ERROR_OPEN_FILES:
      error = EBUSY;
      break;
    case ERROR_OPERATION_ABORTED:
      error = EINTR;
      break;
    case ERROR_OUTOFMEMORY:
      error = ENOMEM;
      break;
    case ERROR_PASSWORD_EXPIRED:
      error = EACCES;
      break;
    case ERROR_PATH_BUSY:
      error = EBUSY;
      break;
    case ERROR_PATH_NOT_FOUND:
      error = ENOENT;
      break;
    case ERROR_PIPE_BUSY:
      error = EBUSY;
      break;
    case ERROR_PIPE_CONNECTED:
      error = EPIPE;
      break;
    case ERROR_PIPE_LISTENING:
      error = EPIPE;
      break;
    case ERROR_PIPE_NOT_CONNECTED:
      error = EPIPE;
      break;
    case ERROR_PRIVILEGE_NOT_HELD:
      error = EACCES;
      break;
    case ERROR_READ_FAULT:
      error = EIO;
      break;
    case ERROR_SEEK:
      error = EIO;
      break;
    case ERROR_SEEK_ON_DEVICE:
      error = ESPIPE;
      break;
    case ERROR_SHARING_BUFFER_EXCEEDED:
      error = ENFILE;
      break;
    case ERROR_SHARING_VIOLATION:
      error = EACCES;
      break;
    case ERROR_STACK_OVERFLOW:
      error = ENOMEM;
      break;
    case ERROR_SWAPERROR:
      error = ENOENT;
      break;
    case ERROR_TOO_MANY_LINKS:
      error = EMLINK;
      break;
    case ERROR_TOO_MANY_MODULES:
      error = EMFILE;
      break;
    case ERROR_TOO_MANY_OPEN_FILES:
      error = EMFILE;
      break;
    case ERROR_UNRECOGNIZED_MEDIA:
      error = ENXIO;
      break;
    case ERROR_UNRECOGNIZED_VOLUME:
      error = ENODEV;
      break;
    case ERROR_WAIT_NO_CHILDREN:
      error = ECHILD;
      break;
    case ERROR_WRITE_FAULT:
      error = EIO;
      break;
    case ERROR_WRITE_PROTECT:
      error = EROFS;
      break;
    case ERROR_CANT_RESOLVE_FILENAME:
      error = ELOOP;
      break;
    }
  return error;
}
