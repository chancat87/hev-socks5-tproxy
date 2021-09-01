/*
 ============================================================================
 Name        : hev-socks5-session.h
 Author      : Heiher <r@hev.cc>
 Copyright   : Copyright (c) 2017 - 2021 hev
 Description : Socks5 Session
 ============================================================================
 */

#ifndef __HEV_SOCKS5_SESSION_H__
#define __HEV_SOCKS5_SESSION_H__

#include <hev-task.h>

#define HEV_SOCKS5_SESSION(p) ((HevSocks5Session *)p)
#define HEV_SOCKS5_SESSION_IFACE(p) ((HevSocks5SessionIface *)p)
#define HEV_SOCKS5_SESSION_TYPE (hev_socks5_session_iface ())

typedef void HevSocks5Session;
typedef struct _HevSocks5SessionIface HevSocks5SessionIface;

struct _HevSocks5SessionIface
{
    void (*splicer) (HevSocks5Session *self);
    HevTask *(*get_task) (HevSocks5Session *self);
    void (*set_task) (HevSocks5Session *self, HevTask *task);
};

void *hev_socks5_session_iface (void);

void hev_socks5_session_run (HevSocks5Session *self);
void hev_socks5_session_terminate (HevSocks5Session *self);

void hev_socks5_session_set_task (HevSocks5Session *self, HevTask *task);

#endif /* __HEV_SOCKS5_SESSION_H__ */
