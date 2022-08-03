//
// Created by Tom Penn on 30/07/2022.
//

#ifndef GAMEALPHA_MAINLOOP_H
#define GAMEALPHA_MAINLOOP_H

#include "../../Public/Loop/Loop.h"
#include "../Users/User.h"
#include "Loop.h"

enum ELoopState {
    ELooping,
    EEnd
};

class MainLoop : public Loop {
public:
    using Loop::Loop;

    void Start() override;

protected:
    ELoopState loopState;

    static short ShowMainMenu();

    void HandleMainMenu(const short &option,  shared_ptr<User> &userOut);
};


#endif //GAMEALPHA_MAINLOOP_H
