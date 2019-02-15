#ifndef CONFIG_H
#define CONFIG_H

/* Number of digits used for printing float values 
 * 7 seems sufficient, we do 9 for good measure
 */
static int digits = 9;

/* Platform endianness
 * Set this to 1 if your platform uses big endian byte order instead
 */
static int big_endian = 0;

#endif /* CONFIG_H */
