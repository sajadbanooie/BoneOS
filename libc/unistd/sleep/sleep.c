/**
 ** This file is part of BoneOS.
 **
 **   BoneOS is free software: you can redistribute it and/or modify
 **   it under the terms of the GNU General Public License as published by
 **   the Free Software Foundation, either version 3 of the License, or
 **   (at your option) any later version.

 **   BoneOS is distributed in the hope that it will be useful,
 **   but WITHOUT ANY WARRANTY; without even the implied warranty of
 **   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **   GNU General Public License for more details.

 **   You should have received a copy of the GNU General Public License
 **   along with BoneOS.  If not, see <http://www.gnu.org/licenses/>.
 **
 **  @main_author : Amanuel Bogale
 **  
 **  @contributors:

 **     Amanuel Bogale <amanuel2> : start
 **/  

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <libc/stdio/stdio.h>
#include <drv/pit/pit.h>
#include <libc/unistd/sleep/sleep.h>
#include <drv/driver.h>
#include <libc/assertk.h>
#include <misc/asm_util.h>

void sleep(uint32_t ms)
{
  assertkm(device_initalized(PIT_DRIVER_INDEX) , "PIT NOT INITALIZED FOR SLEEP()");
  int64_t expiry = pit_ticks + ((uint64_t)ms * IRQ_SEC_HIT) / 1000;
  while (pit_ticks < expiry) hlt();
}




