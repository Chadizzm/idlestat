/*
 *  utils.h
 *
 *  Copyright (C) 2014, Linaro Limited.
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Contributors:
 *     Daniel Lezcano <daniel.lezcano@linaro.org>
 *     Zoran Markovic <zoran.markovic@linaro.org>
 *
 */
#ifndef __UTILS_H
#define __UTILS_H

#include <stdbool.h>

/* Program Configuration Options */
struct program_options {
	bool debug;
	bool verbose;
	bool dump;
	int iterations;
	int mode;
	unsigned int duration;
	char *filename;
	char *trace_file;
	char *energy_model_filename;
};
extern struct program_options options;

#define print_vrb(fmt, ...) 			\
if (options.verbose) {				\
	fprintf(stderr, fmt, ##__VA_ARGS__);	\
}

extern int write_int(const char *path, int val);
extern int read_int(const char *path, int *val);
extern int store_line(const char *line, void *data);
extern int file_read_value(const char *path, const char *name,
				const char *format, void *value);

void setup_mapping();
void close_gnuplot_data(void);
void update_pstate(FILE *f, double time, unsigned int freq, unsigned int cpu);

#endif
