#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QThread>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <linux/videodev2.h>
#include "libv4l2.h"
#include "libv4lconvert.h"
#include "videowidget.h"

#define CLEAR(x) memset(&(x), 0, sizeof(x))

class CaptureThread : public QThread
{
public:
    explicit CaptureThread(QWidget *parent = 0);
    ~CaptureThread();
    bool devam;

    videowidget *parent;
    struct v4l2_format              fmt;
    struct v4l2_buffer              buf;
    struct v4l2_requestbuffers      req;
    enum v4l2_buf_type              type;
    fd_set                          fds;
    struct timeval                  tv;
    int                             r, fd;
    unsigned int                    n_buffers;
    char                            *dev_name;
    char                            out_name[256];
    FILE                            *fout;


    struct buffer {
            void   *start;
            size_t length;
    };
    static void xioctl(int fh, int request, void *arg)
    {
            int r;

            do {
                    r = v4l2_ioctl(fh, request, arg);
            } while (r == -1 && ((errno == EINTR) || (errno == EAGAIN)));

            if (r == -1) {
                    fprintf(stderr, "error %d, %s\n", errno, strerror(errno));
                    return;
            }
    };
    void run();
    struct buffer                   *buffers;


    void stopUlan();
    void startUlan();
};






#endif // CAPTURETHREAD_H
