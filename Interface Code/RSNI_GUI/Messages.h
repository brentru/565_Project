/*
 * File: Messages.h
 * Author: Todd Morehouse
 * Description
 *  Contains the message ID for each message. These message IDs were defined in our project plan.
 */

#ifndef MESSAGES_H
#define MESSAGES_H

namespace Messages{
    const static int KillProcessID                  = 1;
    const static int KillProcessResponseID          = 2;
    const static int ResetProcessID                 = 3;
    const static int ResetProcessResponseID         = 4;
    const static int PauseProcessID                 = 5;
    const static int PauseProcessResponseID         = 6;
    const static int StartProcessID                 = 7;
    const static int StartProcessResponseID         = 8;
    const static int KillAllProcessesID             = 9;
    const static int KillAllProcessesResponseID     = 10;
    const static int ResetAllProcessesID            = 11;
    const static int ResetAllProcessesResponseID    = 12;
    const static int PauseAllProcessesID            = 13;
    const static int PauseAllProcessesResponseID    = 14;
    const static int ProcessStatusID                = 15;
    const static int ProcessStatusResponseID        = 16;
    const static int ResumeProcessID                = 17;
    const static int ResumeProcessResponseID        = 18;
}

#endif // MESSAGES_H
