/****************************************************************************
 * lulzKey. Let's close those effin Windows so penguins won't enter.        *
 *                                                                          *
 * Copyright (C) 2009  meh. [http://meh.doesntexist.org]                    *
 *                                                                          *
 * This program is free software: you can redistribute it and/or modify     *
 * it under the terms of the GNU Affero General Public License as published *
 * by the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                      *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU Affero General Public License for more details.                      *
 *                                                                          *
 * You should have received a copy of the GNU Affero General Public License *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 ****************************************************************************/

#ifndef _LKEY_INTERRUPT_H
#define _LKEY_INTERRUPT_H

#include <Type.h>

namespace Kernel {

class Interrupt
{
  protected:
    Interrupt (void) {};

  public:
    struct Registers {
        Type::u32 ds; /*<< data segment selector */
        
        // Pushed by pusha.
        Type::u32 edi;
        Type::u32 esi;
        Type::u32 ebp;
        Type::u32 esp;
        Type::u32 ebx;
        Type::u32 edx;
        Type::u32 ecx;
        Type::u32 eax;

        Type::u32 number;    /*<< interrupt number */
        Type::u32 errorCode; /*<< interrupt error code (if applicable) */

        // Pushed by the processor automatically.
        Type::u32 eip;
        Type::u32 cs;
        Type::u32 eflags;
        Type::u32 useresp;
        Type::u32 ss;
    };

    enum Type {
        ServiceRoutine,
        Request
    };

    typedef void (*Handler)(Registers&);

  public:
    static void handle (Type type, Registers& registers);
    static void define (Type::u8 number, Handler handler);

  private:
    static Handler _handlers[256];
};

}

#endif