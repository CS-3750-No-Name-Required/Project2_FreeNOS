/*
 * Copyright (C) 2015 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Log.h>
#include "Kernel.h"
#include "Scheduler.h"

Scheduler::Scheduler()
{
    DEBUG("");
}

Size Scheduler::count() const
{
    return m_queue_1.count() + m_queue_2.count() + m_queue_3.count() + m_queue_4.count() + m_queue_5.count();
}

Scheduler::Result Scheduler::enqueue(Process *proc, bool ignoreState)
{
    if (proc->getState() != Process::Ready && !ignoreState)
    {
        ERROR("process ID " << proc->getID() << " not in Ready state");
        return InvalidArgument;
    }

    switch(proc->getPriority()) {
        case 5:
            m_queue_5.push(proc);
            break;
        case 4:
            m_queue_4.push(proc);
            break;
        case 3:
            m_queue_3.push(proc);
            break;
        case 2:
            m_queue_2.push(proc);
            break;
        case 1:
            m_queue_1.push(proc);
            break;
    }
    return Success;
}

Scheduler::Result Scheduler::dequeue(Process *proc, bool ignoreState)
{
    if (proc->getState() == Process::Ready && !ignoreState)
    {
        ERROR("process ID " << proc->getID() << " is in Ready state");
        return InvalidArgument;
    }

    Size count5 = m_queue_5.count();
    Size count4 = m_queue_4.count();
    Size count3 = m_queue_3.count();
    Size count2 = m_queue_2.count();
    Size count1 = m_queue_1.count();

    // Traverse the Queues to remove the Process
    for (Size i = 0; i < count5; i++)
    {
        Process *p = m_queue_5.pop();

        if (p == proc)
            return Success;
        else
            m_queue_5.push(p);
    }

    for (Size i = 0; i < count4; i++)
    {
        Process *p = m_queue_4.pop();

        if (p == proc)
            return Success;
        else
            m_queue_4.push(p);
    }

    for (Size i = 0; i < count3; i++)
    {
        Process *p = m_queue_3.pop();

        if (p == proc)
            return Success;
        else
            m_queue_3.push(p);
    }

    for (Size i = 0; i < count2; i++)
    {
        Process *p = m_queue_2.pop();

        if (p == proc)
            return Success;
        else
            m_queue_2.push(p);
    }

    for (Size i = 0; i < count1; i++)
    {
        Process *p = m_queue_1.pop();

        if (p == proc)
            return Success;
        else
            m_queue_1.push(p);
    }

    FATAL("process ID " << proc->getID() << " is not in the schedule");
    return InvalidArgument;
}

Process * Scheduler::select()
{
    if (m_queue_5.count() > 0)
    {
        Process *p = m_queue_5.pop();
        m_queue_5.push(p);

        return p;
    }
    if (m_queue_4.count() > 0)
    {
        Process *p = m_queue_4.pop();
        m_queue_4.push(p);

        return p;
    }
    if (m_queue_3.count() > 0)
    {
        Process *p = m_queue_3.pop();
        m_queue_3.push(p);

        return p;
    }
    if (m_queue_2.count() > 0)
    {
        Process *p = m_queue_2.pop();
        m_queue_2.push(p);

        return p;
    }
    if (m_queue_1.count() > 0)
    {
        Process *p = m_queue_1.pop();
        m_queue_1.push(p);

        return p;
    }

    return (Process *) NULL;
}
