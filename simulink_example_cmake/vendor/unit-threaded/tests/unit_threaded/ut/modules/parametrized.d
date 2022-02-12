/**
 A module with tests to test the compile-time reflection
 */

module unit_threaded.ut.modules.parametrized;

import unit_threaded.runner.attrs;

version(unittest) {

    @(1, 2, 3)
    @AutoTags
    void testValues(int i) {
        assert(i % 2 != 0);
    }

    @Types!(float, int)
    @AutoTags
    void testTypes(T)() {
        assert(T.init == 0);
    }

    @Name("my_name_is_test")
    @UnitTest
    @Types!(float, int)
    void typesWithName(T)() {
        assert(T.init == 0);
    }

    struct Foo { int i; }
    struct Bar { int i; }

    @Name("cartesian_types")
    @UnitTest
    @Types!(int, float)
    @Types!(string, Foo, Bar)
    void cartesianTypes(T0, T1)() {
        static assert(T0.sizeof == 4);
        assert(T1.sizeof == 4);
    }
}

@("builtinIntValues")
@AutoTags
@Values(2, 3, 4, 5)
unittest {
    import std.conv;
    immutable i = getValue!int;
    assert(i == 3);
}

@("cartesianBuiltinNoAutoTags")
@Values("foo", "bar")
@Values("red", "blue", "green")
unittest {
    assert(getValue!(string, 0).length == getValue!(string, 1).length);
}

@("cartesianBuiltinAutoTags")
@Values("foo", "bar")
@Values("red", "blue", "green")
@AutoTags
unittest {
    assert(getValue!(string, 0).length == getValue!(string, 1).length);
}



@(1, 2, 3)
@("foo", "bar")
@AutoTags
testCartesianFunction(int i, string s) {
    assert(i == 2 && s == "bar");
}


void testIssue31(int, string) {
    // this used to fail because there are no UDAs on this function
}
