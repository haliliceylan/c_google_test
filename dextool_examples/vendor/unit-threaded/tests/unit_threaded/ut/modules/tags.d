module unit_threaded.ut.modules.tags;

import unit_threaded.runner.attrs;

@Tags(["ninja", "make"])
unittest { }

unittest {
    assert(1 == 2);
}

version(unittest) {
    @Tags("make")
    void testMake() {
        import unit_threaded.should;

        2.shouldEqual(2);
    }
}

@Tags("make")
unittest {
    assert(1 == 2);
}

@HiddenTest
unittest {
    assert(1 == 2);
}
