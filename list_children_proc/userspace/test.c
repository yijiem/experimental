#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
  printf("pid: %d\n", getpid());
  int pipefd[2];
  pipe(pipefd);
  pid_t pid = fork();
  if (pid == 0) {
    // first child
    sleep(5);
    return 0;
  }
  // parent
  printf("first child pid: %d\n", pid);
  pid = fork();
  if (pid == 0) {
    // second child
    sleep(5);
    return 0;
  }
  printf("second child pid: %d\n", pid);
  char buf[1024];
  int fd = open("/proc/ps_children_list", O_RDONLY);
  ssize_t sz = read(fd, buf, sizeof(buf));
  buf[sz] = '\0';
  printf("buf: %s\n", buf);

  int status = 0;
  wait(&status);
  wait(&status);
  return 0;
}

