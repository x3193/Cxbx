// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;; 
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['  
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P    
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,  
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->ThreadList.cpp
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#include "ThreadList.h"

// ******************************************************************
// * Static
// ******************************************************************
ThreadList *ThreadList::pFirst = new ThreadList;
ThreadList *ThreadList::pHead  = ThreadList::pFirst;

// ******************************************************************
// * ThreadList::Insert
// ******************************************************************
void ThreadList::Insert(HANDLE hThread, DWORD hThreadId)
{
    ThreadList *tl = ThreadList::pHead;

    tl->hThread = hThread;
    tl->dwThreadId = GetCurrentThreadId();
    tl->pNext = new ThreadList;
    tl->pNext->hThread = NULL;
    tl->pNext->dwThreadId = 0;
    tl->pNext->pNext = NULL;

    ThreadList::pHead = tl->pNext;
}

// ******************************************************************
// * ThreadList::Remove
// ******************************************************************
void ThreadList::Remove(DWORD hThreadId)
{
    // TODO! (Make this a mutex though!)
}