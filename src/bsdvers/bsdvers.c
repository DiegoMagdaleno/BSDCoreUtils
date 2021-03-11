/*
 * Copyright (c) 2017 David Cantrell <david.l.cantrell@gmail.com>
 *                    Jim Bair <james.d.bair@gmail.com>
 *                    Diego Magdaleno <diegomagdaleno@protonmail.com>                   
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include "colors.h"

#define _(str) (char *)str

static void version(void)
{
    printf("\n");
    printf(YEL "       _____                    " RESET "The OpenBSD coreutils project. v6.7\n ");
    printf(YEL "   \\-     -/                   " RESET "Copyright (C) 1997-2020 The OpenBSD Project\n");
    printf(YEL " \\_/         \\                 " RESET " Copyright (C) 2017-2020 David Cantrell\n");
    printf(YEL " |" RESET "        O O" YEL " |                 " RESET "Copyright (C) 2019-2020 Diego Magdaleno\n");
    printf(YEL " |_  <   )  3 )                 " RESET "Copyright (C) 2018-2020 Jim Bair\n");
    printf(YEL "  / \\         /\n" RESET);
    printf(YEL "    /-_____-\\ \n" RESET);
    printf(_("                                This set of programs may be freely redistributed under\n"
             "                                The terms of the OpenBSD license. \n"));
    printf("\n");
}

int main(void)
{
    version();
    return 0;
}